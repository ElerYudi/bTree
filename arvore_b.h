#include <stdio.h>
#ifndef ARVORE_B_H
#define ARVORE_B_H


#define MAX 3
#define MIN 2

struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct NoArvoreB {
  int val[MAX + 1], count;
  struct NoArvoreB *link[MAX + 1];
};

extern struct NoArvoreB *raiz;

struct NoArvoreB *criarNo(int val, struct NoArvoreB *filho);
void inserirNo(int val, int pos, struct NoArvoreB *no, struct NoArvoreB *filho);
void dividirNo(int val, int *pval, int pos, struct NoArvoreB *no, struct NoArvoreB *filho, struct NoArvoreB **novoNo);
int definirValor(int val, int *pval, struct NoArvoreB *no, struct NoArvoreB **filho);
void inserir(int val);
void buscar(int val, int *pos, struct NoArvoreB *meuNo);
void percorrer(struct NoArvoreB *meuNo);


#endif
