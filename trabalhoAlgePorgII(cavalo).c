#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4; // defini pq acho que da para usar mais pra frente(ideia minha), se não precisar colocamos como nota/apagamos

    //movimentos possíveis do cavalo no xadrez, primeiro número indica o movimento vertical e o segundo o movimento horizontal
    int movimentosCavalo[8][2] = {
        {2,1}, {1,2}, {-1,2}, {-2, 1},
        {-2, -1}, {-1, -2}, {-2, 1}, {2,1}
    };

    int main(){
        printf("Bom dia amiguinhos!(.)(.)(|)\n");
    }