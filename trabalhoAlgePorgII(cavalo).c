#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 4 // defini o tamanho do tabuleiro

    
    

//funcao que imprime o tabuleiro
void imprime_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%2d ",tabuleiro[i][j]);
        }
        printf("\n"); 
    }
}


int main(){
    int tabuleiro[TAMANHO][TAMANHO] = {0}; //criando tabuleiro com todas as casas com 0

    // movimentos possíveis do cavalo no xadrez, primeiro número indica o movimento vertical e o segundo o movimento horizontal
    int movimentos_Cavalo[8][2] = {
        {2,1}, {1,2}, {-1,2}, {-2, 1},
        {-2, -1}, {-1, -2}, {-2, 1}, {2,1}
    };

    //variaveis da posicao inicial do cavalo
    int cavalo_x, cavalo_y;

    //colocando a posicao inicial aleatoria
    srand(time(NULL));  //gera um numero aleatorio toda vez que o tempo muda
    cavalo_x = rand() % TAMANHO;
    cavalo_y = rand() % TAMANHO;
    tabuleiro[cavalo_x][cavalo_y] = 1; //colocando o cavalo no tabuleiro

    while (1)
    {
        printf("Tabuleiro atual: \n");
        imprime_tabuleiro(tabuleiro);
    }
    
    
    


    return 0;
}