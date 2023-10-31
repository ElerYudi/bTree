#include <stdio.h>
#include <stdlib.h>
#include "arvore_b.h"

struct NoArvoreB *raiz;

struct NoArvoreB *criarNo(int val, struct NoArvoreB *filho) {
  struct NoArvoreB *novoNo;
  novoNo = (struct NoArvoreB *)malloc(sizeof(struct NoArvoreB));
  novoNo->val[1] = val;
  novoNo->count = 1;
  novoNo->link[0] = raiz;
  novoNo->link[1] = filho;
  return novoNo;
}

void inserirNo(int val, int pos, struct NoArvoreB *no, struct NoArvoreB *filho) {
  int j = no->count;
  while (j > pos) {
    no->val[j + 1] = no->val[j];
    no->link[j + 1] = no->link[j];
    j--;
  }
  no->val[j + 1] = val;
  no->link[j + 1] = filho;
  no->count++;
}

void dividirNo(int val, int *pval, int pos, struct NoArvoreB *no, struct NoArvoreB *filho, struct NoArvoreB **novoNo) {
  int mediana, j;

  if (pos > MIN)
    mediana = MIN + 1;
  else
    mediana = MIN;

  *novoNo = (struct NoArvoreB *)malloc(sizeof(struct NoArvoreB));
  j = mediana + 1;
  while (j <= MAX) {
    (*novoNo)->val[j - mediana] = no->val[j];
    (*novoNo)->link[j - mediana] = no->link[j];
    j++;
  }
  no->count = mediana;
  (*novoNo)->count = MAX - mediana;

  if (pos <= MIN) {
    inserirNo(val, pos, no, filho);
  } else {
    inserirNo(val, pos - mediana, *novoNo, filho);
  }
  *pval = no->val[no->count];
  (*novoNo)->link[0] = no->link[no->count];
  no->count--;
}

int definirValor(int val, int *pval, struct NoArvoreB *no, struct NoArvoreB **filho) {
  int pos;
  if (!no) {
    *pval = val;
    *filho = NULL;
    return 1;
  }

  if (val < no->val[1]) {
    pos = 0;
  } else {
    for (pos = no->count; (val < no->val[pos] && pos > 1); pos--);
    if (val == no->val[pos]) {
      printf("Duplicados não são permitidos\n");
      return 0;
    }
  }
  if (definirValor(val, pval, no->link[pos], filho)) {
    if (no->count < MAX) {
      inserirNo(*pval, pos, no, *filho);
    } else {
      dividirNo(*pval, pval, pos, no, *filho, filho);
      return 1;
    }
  }
  return 0;
}

void inserir(int val) {
  int flag, i;
  struct NoArvoreB *filho;

  flag = definirValor(val, &i, raiz, &filho);
  if (flag)
    raiz = criarNo(i, filho);
}

void buscar(int val, int *pos, struct NoArvoreB *meuNo) {
  if (!meuNo) {
    return;
  }

  if (val < meuNo->val[1]) {
    *pos = 0;
  } else {
    for (*pos = meuNo->count; (val < meuNo->val[*pos] && *pos > 1); (*pos)--);
    if (val == meuNo->val[*pos]) {
      printf("%d foi encontrado\n", val);
      return;
    }else{
      printf("Valor nao possui na arvore\n");
    }
  }
  buscar(val, pos, meuNo->link[*pos]);
  return;
}

void percorrer(struct NoArvoreB *meuNo) {
  int i;
  if (meuNo) {
    for (i = 0; i < meuNo->count; i++) {
      percorrer(meuNo->link[i]);
      printf("%d ", meuNo->val[i + 1]);
    }
    percorrer(meuNo->link[i]);
  }
}