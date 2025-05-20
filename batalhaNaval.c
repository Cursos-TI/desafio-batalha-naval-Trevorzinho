#include <stdio.h>

// nivel novato

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
    int sobreposicao = 0;

    if (verticalLinha + 2 > 9 || verticalColuna > 9) {
        printf("Navio vertical fora do tabuleiro!\n");
        return 0;
    }
    if (horizontalLinha > 9 || horizontalColuna + 2 > 9) {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 0;
    }

    for(int controle = 0; controle < 3; controle++){
        if(tabuleiro[verticalLinha + controle][verticalColuna] == 3 || (tabuleiro[verticalLinha][verticalColuna + controle] == 3)) sobreposicao = 1;
        if((verticalLinha + controle == horizontalLinha) && (verticalColuna == horizontalColuna + controle)) sobreposicao = 1;
    } // checando possiveis sobreposições

    if(!sobreposicao){
        for (int controle = 0; controle < 3; controle++)
        {
            tabuleiro[verticalLinha + controle][verticalColuna] = 3;
        } // barco vertical

        for (int controle = 0; controle < 3; controle++){
            tabuleiro[horizontalLinha][horizontalColuna + controle] = 3;
        }
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
