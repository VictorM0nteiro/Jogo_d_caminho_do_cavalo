#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 4 // na minha máquina não está funcionando a definição global, vou ter que fazer manuelmente int N = 4 todas as vezes

    //movimentos possíveis do cavalo no xadrez, primeiro número indica o movimento vertical e o segundo o movimento horizontal
    int movimentosCavalo[8][2] = {
        {2,1}, {1,2}, {-1,2}, {-2, 1},
        {-2, -1}, {-1, -2}, {-2, 1}, {2,1}
    };

    void imprimirTabuleiro(int *tabuleiro, int N){
        printf("\nTabuleiro\n");
        for( int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%2d ", *(tabuleiro + (i * N) + j)); //%2d serve para melhorar a estética da impressão // (tabuleiro) + (i * N): Depois, a multiplicação é somada ao ponteiro    tabuleiro. Calculcando a posição de memória correspondente a linha i do tabuleiro, depois e mesmo com J para a coluna;
            }
            printf("\n");
        }
    }

    int main(){
        int N = 4;
        int tabuleiro[4][4] = {0};
        
        tabuleiro[0][0] = 1;

        imprimirTabuleiro((int*)tabuleiro, N);
        //printf("Bom dia amiguinhos!(.)(.)(|)\n");
    }