/*
JOGO DO CAMINHO DO CAVALO - Algorítmos e Programação II

Integrantes do grupo:

Matheus Nascimento Leite
Victor Hugo Monteiro
Luccas Asaphe Pena Salomão
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 4 // defini o tamanho do tabuleiro

//funcao que imprime o tabuleiro
void imprime_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    system("cls");//funcao para limpar terminal

    //inserindo numeros e letras para deixar o tabuleiro mais intuitivo
    printf("  ");
    for (int i = 1; i <= TAMANHO; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%c ",'A'+i);
        for (int j = 0; j < TAMANHO; j++)
        {         
            printf("%2d ",tabuleiro[i][j]);
        }
        printf("\n"); 
    }
}

//funcao para verificar se a nova posicao que o cavalo pode assumir eh valida
int movimento_valido(int *P, int desloc_linha, int desloc_coluna, int *P_tabuleiro){
    int linha_atual = (P-P_tabuleiro)/TAMANHO;
    int coluna_atual = (P-P_tabuleiro)%TAMANHO;

    int nova_linha = linha_atual + desloc_linha; // essa conta nos da o resultado da linha atual somado com o deslocamento ( nova_linha)
    int nova_coluna = coluna_atual + desloc_coluna;// essa conta nos da o resultado da coluna atual somado com o deslocamento ( nova_coluna)
    
    //nova_linha e nova_coluna tem que ser positivo pois se nao pode acessar uma posicao de memoria indevida
    if(nova_linha >=0 && nova_linha < TAMANHO && nova_coluna >=0 && nova_coluna < TAMANHO && *(P_tabuleiro + nova_linha*TAMANHO+nova_coluna)==0) {
        return 1; //a nova posicao eh valida
    }
    else return 0;
}

int main(){
    int tabuleiro[TAMANHO][TAMANHO] = {0}; //criando tabuleiro com todas as casas com 0

    // movimentos possíveis do cavalo no xadrez, primeiro número indica o movimento vertical e o segundo o movimento horizontal
    int movimentos_Cavalo[8][2] = {
        {2, 1}, 
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1, 2}, 
        {1, -2},
        {-1, 2},
        {-1, -2}
    };

    //variaveis da posicao inicial do cavalo
    int cavalo_linha, cavalo_coluna;

    //criando os ponteiros
    int *P_tabuleiro = &tabuleiro[0][0];
    int *P = &tabuleiro[0][0]; // ponteiro do cavalo
    int *P_movimentos_cavalo = &movimentos_Cavalo[0][0]; //ponteiro que aponta para a matriz de movimentos do cavalo

    //colocando a posicao inicial aleatoria
    srand(time(NULL));  //gera um numero aleatorio toda vez que o tempo muda
    cavalo_linha = rand() % TAMANHO;
    cavalo_coluna = rand() % TAMANHO;

    //posicionando o cavalo na posicao aleatoria gerada
    P += cavalo_linha*TAMANHO+cavalo_coluna;
    *P = 1; //colocando o cavalo no tabuleiro

    

    //criando um contador de casas preenchidas para verificar se o usuário ganhou ou perdeu
    int cont_casas=1;

     while (1)
    {
        printf("Tabuleiro atual: \n");
        imprime_tabuleiro(tabuleiro);
        printf("Posicao do cavalo: %c%d\n",('A'+((P-(P-cavalo_linha*TAMANHO))/TAMANHO)),((P-(P-cavalo_coluna))%TAMANHO)+1);

        //printf("Posicao do cavalo: %c%d\n", 'A' + cavalo_linha, cavalo_coluna + 1); // sujestão de codigo, amiguitos avaliar se é valido de acordo com as exigencias 👈👈👈👈👈👈

        printf("\nMover para: \n");
        int movimento_valido_encontrado = 0;
        int movimentos_validos[8][2] = {0};
        int total_movimentos_validos = 0;

        int *P_movimentos_validos = &movimentos_validos[0][0];

        //definindo os movimentos possíveis a partir da posicao atual do cavalo
        for (int i = 0; i < 8; i++)
        {
            //criando as variavies que vao receber as novas posicoes que o cavalo pode assumir
        int nova_linha = *(P_movimentos_cavalo + i * 2); // movimentos_Cavalo[i][0];
        int nova_coluna = *(P_movimentos_cavalo + i * 2 + 1); // movimentos_Cavalo[i][1];

            //precisamos verificar se a nova posicao eh valida (esta dentro do tabuleiro e se a posicao nao foi preenchida ainda)
            if(movimento_valido(P,nova_linha, nova_coluna, P_tabuleiro)){
                movimento_valido_encontrado = 1;
                nova_linha = (P-P_tabuleiro)/TAMANHO + nova_linha; // essa conta nos da o resultado da linha atual somado com o deslocamento ( nova_linha)
                nova_coluna = (P-P_tabuleiro)%TAMANHO + nova_coluna;// essa conta nos da o resultado da coluna atual somado com o deslocamento ( nova_coluna)
                *(P_movimentos_validos + total_movimentos_validos*2) = nova_linha; //movimentos_validos[total_movimentos_validos][0] = nova_linha;
                *(P_movimentos_validos + total_movimentos_validos*2+1) = nova_coluna; //movimentos_validos[total_movimentos_validos][1] = nova_coluna;
                total_movimentos_validos++;

                
                printf("%d. %c%d\n",total_movimentos_validos,'A'+nova_linha, nova_coluna+1);
            }
        }

        //se não tiver mais movimentos o player perde e encerra o programa
        if(!movimento_valido_encontrado){
            printf("Voce perdeu! Nao possui mais movimentos!\n");
            break; // break pois estamos dentro do while
        }

        //para escolher o próximo movimento
        int escolha;
        int *pont_escolha;
        pont_escolha = &escolha;
        printf("Escolha o movimento de (1 a %d): ", total_movimentos_validos);
        scanf("%d", pont_escolha);
        if(*pont_escolha < 1 || *pont_escolha > total_movimentos_validos){
            printf("\nMovimento invalido. Tente novamente.\n");
            continue;
        }

        //atualizando a posicao do cavalo
        // int nova_linha = movimentos_validos[escolha-1][0];
        // int nova_coluna = movimentos_validos[escolha-1][1];
        // P = &tabuleiro[nova_linha][nova_coluna];
        // tabuleiro[nova_linha][nova_coluna] = ++cont_casas; //colocando o cavalo no tabuleiro
        
        //atualizando a posicao do cavalo 2.0
        cavalo_linha = *(P_movimentos_validos + (escolha-1)*2);    //cavalo_linha = movimentos_validos[escolha-1][0]; // otimizei essa parte com variáveis que já possuimos
        cavalo_coluna = *(P_movimentos_validos + (escolha-1)*2 + 1);    //cavalo_coluna = movimentos_validos[escolha-1][1];
        P = P_tabuleiro + (cavalo_linha * TAMANHO + cavalo_coluna);
        //P = (int *)(&tabuleiro[cavalo_linha][cavalo_coluna]);
        *P = ++cont_casas; //colocando o cavalo no tabuleiro // diminuir um pouco de codigo utilizando a desrefrenciação

        //verificando se o usuario venceu
        if(cont_casas == TAMANHO*TAMANHO){
            printf("Voce ganhou! Todas as casas foram preenchidas!\n");
            break;
        }

    }
    return 0;
}