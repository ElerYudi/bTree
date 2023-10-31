#include "arvore_b.h"
#include <stdio.h>

int main() {
  int valor, resultadoBusca;

  inserir(8);
  inserir(9);
  inserir(10);
  inserir(11);
  inserir(15);
  inserir(16);
  inserir(17);
  inserir(18);
  inserir(20);
  inserir(23);

  buscar(10, &resultadoBusca, raiz);

  return 0;
}
