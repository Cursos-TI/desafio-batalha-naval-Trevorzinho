#include <stdio.h>
//nivel aventureiro
    char letras[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0}, linha, coluna;

void TabuleiroMapa(){

    printf("=========== Tabuleiro da Batalha Naval ===========");
    printf("\n  ");

    for (int controle = 0; controle < 10; controle++)
        {
          printf(" %c", letras[controle]);
        }

    printf("\n");

    for (int linha = 0; linha < 10; linha++){
        
        if (linha < 9){
            printf(" %d ", (linha + 1));
        }
        else{
            printf("%d ", (linha + 1));
        }
    
        for (int coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]);
        }
    printf("\n");
        
    }

}

int posicionaNavios() {

    int verticalLinha = 2, verticalColuna = 0; // barco na vertical vai ficar em (2,0), (3,0), (4,0)
    int horizontalLinha = 4, horizontalColuna = 4; // barco na horizontal vai ficar em (4,4), (4,5) e (4,6)
    int diag1_linha = 6, diag1_coluna = 6; // primeiro barco na diagonal vai ficar em (6,6), (7,7) e(8,8))
    int diag2_linha = 6, diag2_coluna = 3; // segundo barco na diagonal em (6,3), (7,2) e (8,1))
    int sobreposicao = 0;

    if (verticalLinha + 2 > 9 || verticalColuna > 9) {
        printf("Navio vertical fora do tabuleiro!\n");
        return 0;
    }
    if (horizontalLinha > 9 || horizontalColuna + 2 > 9) {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 0;
    }
    if (diag1_linha + 2 > 9 || diag1_coluna + 2 > 9) {
        printf("Primeiro navio diagonal fora do tabuleiro!\n");
        return 0;
    }
    if (diag2_linha + 2 > 9 || diag2_coluna - 2 < 0) {
        printf("Segundo Navio diagonal fora do tabuleiro!\n");
        return 0;
    }

     for (int controle = 0; controle < 3; controle++) {
        // vertical
        if (tabuleiro[verticalLinha + controle][verticalColuna] == 3) sobreposicao = 1;
        // horizontal
        if (tabuleiro[horizontalLinha][horizontalColuna + controle] == 3) sobreposicao = 1;
        // segundo na diagonal
        if (tabuleiro[diag1_linha + controle][diag1_coluna + controle] == 3) sobreposicao = 1;
        // primeiro na diagonal
        if (tabuleiro[diag2_linha + controle][diag2_coluna - controle] == 3) sobreposicao = 1;
    }


    if(!sobreposicao){
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[verticalLinha + controle][verticalColuna] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[horizontalLinha][horizontalColuna + controle] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[diag1_linha + controle][diag1_coluna + controle] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[diag2_linha + controle][diag2_coluna - controle] = 3;
        return 1; //retornando que a função funcionou
    } else{ 
        printf("Barcos sobrepostos, escolha uma posição diferente. \n");
        return 0;
        }
}


int main(){

    if (posicionaNavios()) {    
        TabuleiroMapa();
    }
    return 0;
}
