#include "Pixel.h"
#include <cstdlib>
/*
Implementare una funzione void printMatrix(Pixel** p_matrix, int p_row, int p_col)
per stampare in forma testuale il contenuto della matrice di Pixel.

Implementare un main test per inizializzare dinamicamente e stampare una matrice di Pixel. 
Prestare attenzione nella liberazione della memoria.
*/

void printMatrix(Pixel** p_matrix, const int p_row, const int p_col){
    if(p_matrix == nullptr)return;
    for(int i = 0; i<p_row; i++){
        for(int j = 0; j < p_col; j++){
            p_matrix[i][j].printRGB();
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

//funzione globale che dealloca la matrice di Pixel
void deallocaMatrix(Pixel**& p_matrix, const int p_row, const int p_col){
    for(int i = 0; i < p_row; i++){
        delete [] p_matrix[i];
        p_matrix[i] = nullptr;
    }
    delete [] p_matrix;
    p_matrix = nullptr;
}

//funzione globale che inizializza e alloca dinamicamente la matrice di Pixel
//inizializzazione viene effettuata
//estraendo numeri interi casuali nell'intervallo [0,255]
void init_matrix(Pixel** mat, const int r, const int c){
    srand(time(NULL)); //rand time init.
    if(mat) deallocaMatrix(mat,r,c);
    //inizializzazione matrice
    mat = new Pixel*[r]; //allocazione righe
    for(int i = 0; i<r; i++){
        mat[i] = new Pixel[c]{};//allocazione colonne
        for(int j = 0; j < c; j++){
            int r=rand()%256,g=rand()%256,b=rand()%256; //estrazioni
            mat[i][j].setRGB(r,g,b);//chiamata metodo setRGB(int,int,int)
        }
    }
}

int main(){

    Pixel** p_matrix{nullptr};

    int p_row = 3; //righe matrice Pixel**
    int p_col = 5; //colonne matrice Pixel**

    //inizializzazione matrice
    p_matrix = new Pixel*[p_row];
    for(int i = 0; i <p_row; i++){
        p_matrix[i] = new Pixel[p_col]{};
        for(int j = 0; j < p_col; j++){
            int r=rand()%256,g=rand()%256,b=rand()%256;
            p_matrix[i][j].setRGB(r,g,b);
        }
    }

    printMatrix(p_matrix,p_row,p_col);
    deallocaMatrix(p_matrix,p_row,p_col);

    return 0;
}