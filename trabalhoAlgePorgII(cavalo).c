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

//funcao para verificar se a nova posicao que o cavalo pode assumir eh valida
int movimento_valido(int nova_linha, int nova_coluna, int tabuleiro[TAMANHO][TAMANHO]){
    //nova_linha e nova_coluna tem que ser positivo pois se nao pode acessar uma posicao de memoria indevida
    if(nova_linha >=0 && nova_linha < TAMANHO && nova_coluna >=0 && nova_coluna < TAMANHO && tabuleiro[nova_linha][nova_coluna] == 0) {
        return 1; //a nova posicao eh valida
    }
    else return 0;
}

int main(){
    int tabuleiro[TAMANHO][TAMANHO] = {0}; //criando tabuleiro com todas as casas com 0

    // movimentos possíveis do cavalo no xadrez, primeiro número indica o movimento vertical e o segundo o movimento horizontal
    int movimentos_Cavalo[8][2] = {
        {2, 1}, {2, -1},
        {-2, 1}, {-2, -1},
        {1, 2}, {1, -2},
        {-1, 2}, {-1, -2}
    };

    //variaveis da posicao inicial do cavalo
    int cavalo_linha, cavalo_coluna;


    //colocando a posicao inicial aleatoria
    srand(time(NULL));  //gera um numero aleatorio toda vez que o tempo muda
    cavalo_linha = rand() % TAMANHO;
    cavalo_coluna = rand() % TAMANHO;
    tabuleiro[cavalo_linha][cavalo_coluna] = 1; //colocando o cavalo no tabuleiro

    //criando o ponteiro
    int *P = &tabuleiro[cavalo_linha][cavalo_coluna];

    //criando um contador de casas preenchidas para verificar se o usuário ganhou ou perdeu
    int cont_casas=1;

     while (1)
    {
        printf("Tabuleiro atual: \n");
        imprime_tabuleiro(tabuleiro);

        printf("\nMovimentos validos:\n");
        int movimento_valido_encontrado = 0;
        int movimentos_validos[8][2] = {0};
        int total_movimentos_validos = 0;

        //definindo os movimentos possíveis a partir da posicao atual do cavalo
        for (int i = 0; i < 8; i++)
        {
            //criando as variavies que vao receber as novas posicoes que o cavalo pode assumir
            int nova_linha = cavalo_linha + movimentos_Cavalo[i][0];
            int nova_coluna = cavalo_coluna + movimentos_Cavalo[i][1];

            //precisamos verificar se a nova posicao eh valida (esta dentro do tabuleiro e se a posicao nao foi preenchida ainda)
            if(movimento_valido(nova_linha, nova_coluna, tabuleiro)){
                movimento_valido_encontrado = 1;
                movimentos_validos[total_movimentos_validos][0] = nova_linha;
                movimentos_validos[total_movimentos_validos][1] = nova_coluna;
                total_movimentos_validos++;
                printf("%d. Linha: %d, Coluna: %d\n",total_movimentos_validos,nova_linha, nova_coluna);
            }
        }

        //se não tiver mais movimentos o player perde e encerra o programa
        if(!movimento_valido_encontrado){
            printf("Você perdeu! Não possui mais movimentos!\n");
            break; // break pois estamos dentro do while
        }

        //para escolher o próximo movimento
        int escolha;
        printf("Escolha o movimento de (1 a %d): ", total_movimentos_validos);
        scanf("%d", &escolha);
        if(escolha < 1 || escolha > total_movimentos_validos){
            printf("\nMovimento invalido. Tente novamente.\n");
            continue;
        }

    }
    
    
    

    return 0;
}