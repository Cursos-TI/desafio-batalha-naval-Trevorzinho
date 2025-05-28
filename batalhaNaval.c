#include <stdio.h>
//nivel mestre
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
            printf(" %d ", (linha + 1));//alinhamento das linhas 1-9
        }
        else{
            printf("%d ", (linha + 1)); //alinhamento da linha 10
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
    int diagonal1Linha = 6, diagonal1Coluna = 6; // primeiro barco na diagonal vai ficar em (6,6), (7,7) e(8,8))
    int diagonal2Linha = 6, diagonal2Coluna = 3; // segundo barco na diagonal em (6,3), (7,2) e (8,1))
    int sobreposicao = 0;

    if (verticalLinha + 2 > 9 || verticalColuna > 9) {
        printf("Navio vertical fora do tabuleiro!\n");
        return 0;
    }
    if (horizontalLinha > 9 || horizontalColuna + 2 > 9) {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 0;
    }
    if (diagonal1Linha + 2 > 9 || diagonal1Coluna + 2 > 9) {
        printf("Primeiro navio diagonal fora do tabuleiro!\n");
        return 0;
    }
    if (diagonal2Linha + 2 > 9 || diagonal2Coluna - 2 < 0) {
        printf("Segundo Navio diagonal fora do tabuleiro!\n");
        return 0;
    }

    //corrigir a discrepância entre 0-9 interno e 1-10 no display para melhor
        verticalLinha--;
        horizontalLinha--;
        diagonal2Linha--;
        diagonal1Linha--;

     for (int controle = 0; controle < 3; controle++) {
        // vertical
        if (tabuleiro[verticalLinha + controle][verticalColuna] == 3) sobreposicao = 1;
        // horizontal
        if (tabuleiro[horizontalLinha][horizontalColuna + controle] == 3) sobreposicao = 1;
        // segundo na diagonal
        if (tabuleiro[diagonal1Linha + controle][diagonal1Coluna + controle] == 3) sobreposicao = 1;
        // primeiro na diagonal
        if (tabuleiro[diagonal2Linha + controle][diagonal2Coluna - controle] == 3) sobreposicao = 1;
    }


    if(!sobreposicao){
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[verticalLinha + controle][verticalColuna] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[horizontalLinha][horizontalColuna + controle] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[diagonal1Linha + controle][diagonal1Coluna + controle] = 3;
        for (int controle = 0; controle < 3; controle++)
            tabuleiro[diagonal2Linha + controle][diagonal2Coluna - controle] = 3;
        return 1; //retornando que a função funcionou
    } else{ 
        printf("Barcos sobrepostos, escolha uma posição diferente. \n");
        return 0;
        }
}

void ataqueCruz(int linhaCentro, int colunaCentro){

    //corrigir a discrepância entre 0-9 interno e 1-10 no display para melhor
    linhaCentro--;
    colunaCentro--;
    //ataque vertical
    for (int i = linhaCentro - 1; i <= linhaCentro + 1; i++) {
        if (i >= 0 && i < 10) {
            tabuleiro[i][colunaCentro] = 5;
        }
    }

    //ataque horizontal
    for (int j = colunaCentro - 2; j <= colunaCentro + 2; j++) {
        if (j >= 0 && j < 10) {
            tabuleiro[linhaCentro][j] = 5;
        }
    }
}

void ataqueOctaedro(int linhaCentro, int colunaCentro){

    linhaCentro--;
    colunaCentro--;
    //ataque vertical
    for (int i = linhaCentro - 1; i <= linhaCentro + 1; i++){
        if (i >= 0 && i < 10){
            tabuleiro[i][colunaCentro] = 5;
        }
    }

    //ataque horizontal
    for (int j = colunaCentro - 1; j <= colunaCentro + 1; j++){
        if (j >= 0 && j < 10){
            tabuleiro[linhaCentro][j] = 5;
        }
    }
}

void ataqueCone(int linhaCentro, int colunaCentro){

    linhaCentro--;
    colunaCentro--;

    int altura = 3; // altura do cone

    for (int i = 0; i < altura; i++) {

        int linha = linhaCentro + i;
        int inicio = colunaCentro - i;
        int fim = colunaCentro + i;
        
        if (linha >= 0 && linha < 10) {
            for (int j = inicio; j <= fim; j++) {
                if (j >= 0 && j < 10) {
                    tabuleiro[linha][j] = 5;
                }
            }
        }
    }
}

int main(){

    ataqueCone(7, 5);
    ataqueCruz(3, 8);
    ataqueOctaedro(2, 3);
    if (posicionaNavios()) {    
        TabuleiroMapa();
    }
    return 0;
}
