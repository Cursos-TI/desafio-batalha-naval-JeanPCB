#include <stdio.h>

#define SIZE 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
void setNavioHorizontal(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
   int linhaValida = linha >= 0 && linha < SIZE;
   int colunaValida = coluna >= 0 && coluna < SIZE - 2;

   // Checa sobreposicao dos navios
   if (linhaValida && colunaValida) {
      for (int j = coluna; j < coluna + 3; j++) {
         if (tabuleiro[linha][j] == 3) {
            break;
         } else {
            tabuleiro[linha][j] = 3;
         }
      }
   }
}

void setNavioVertical(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
   int linhaValida = linha >= 0 && linha < SIZE - 2;
   int colunaValida = coluna >= 0 && coluna < SIZE;
   
   // Checa sobreposicao dos navios
   if (linhaValida && colunaValida) {
      for (int i = linha; i < linha + 3; i++) {
         if (tabuleiro[i][coluna] == 3) {
            break;
         } else {
            tabuleiro[i][coluna] = 3;
         }
      }
   }
}

void setNavioDiagonal(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
   int linhaValida = linha >= 0 && linha < SIZE - 2;
   int colunaValida = coluna >= 0 && coluna < SIZE - 2;

   // Checa sobreposicao dos navios
   if (linhaValida && colunaValida) {
      for (int i = linha; i < linha + 3; i++) {
         if(tabuleiro[i][coluna] == 3) {
            break;
         } else {
            tabuleiro[i][coluna++] = 3;
         }
      }
   }
}

void habilidadeCone(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
   for (int i = linha; i < linha + 3; i++) {
      for (int j = coluna; j < coluna + 5; j++) {
         if (i == linha && j == coluna + 2) {
            tabuleiro[i][j] = 1;
         } else if (i == linha + 1 && (j != coluna && j != coluna + 4)) {
            tabuleiro[i][j] = 1;
         } else if (i == linha + 2) {
            tabuleiro[i][j] = 1;
         } else {
            tabuleiro[i][j] = 0;
         }
      }
   }
}

void habilidadeOctaedro(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
   for (int i = linha; i < linha + 3; i++) {
      for (int j = coluna; j < coluna + 5; j++) {
         if (i == linha && j == coluna + 2) {
            tabuleiro[i][j] = 1;
         } else if (i == linha + 1 && (j != coluna && j != coluna + 4)) {
            tabuleiro[i][j] = 1;
         } else if (i == linha + 2 && j == coluna + 2) {
            tabuleiro[i][j] = 1;
         } else {
            tabuleiro[i][j] = 0;
         }
      }
   }
}

int main() {
   int tabuleiro[SIZE][SIZE] = {0};
   int matrizCone[SIZE][SIZE] = {0};
   int matrizOcta[SIZE][SIZE] = {0};

   setNavioVertical(tabuleiro, 0, 0);
   setNavioHorizontal(tabuleiro, 0, 6);
   setNavioDiagonal(tabuleiro, 0, 2);
   setNavioDiagonal(tabuleiro, 1, 4);

   printf("TABULEIRO:\n");
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         printf("%d ", tabuleiro[i][j]);
      }
      printf("\n");
   }

   habilidadeCone(matrizCone, 2, 2);

   printf("\nHABILIDADE CONE:\n");
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         printf("%d ", matrizCone[i][j]);
      }
      printf("\n");
   }

   habilidadeOctaedro(matrizOcta, 2, 2);

   printf("\nHABILIDADE OCTAEDRO:\n");
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         printf("%d ", matrizOcta[i][j]);
      }
      printf("\n");
   }

   return 0;
}
