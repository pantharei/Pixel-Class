/*
1) Pixel
Implementare una class Pixel con attributi RGB interi.

Implementare una funzione void printMatrix(Pixel** p_matrix, int p_row, int p_col)
 per stampare in forma testuale il contenuto della matrice di Pixel.

Implementare un main test per inizializzare dinamicamente e stampare una matrice di Pixel. 
Prestare attenzione nella liberazione della memoria.

*/

//implemento in un unico file dato che le implementazioni sono minime
#include <iostream>
class Pixel{
    //attributi RGB
    int r = 0;
    int g = 0;
    int b = 0;
    public:

    //metodo pubblico 'setRGB' per modificare i campi RGB
    void setRGB(int in_r, int in_g, int in_b){
        r = in_r;
        g = in_g;
        b = in_b;
    }

    //metodo 'printRGB' che stampa il pixel
    //nel formato (R,G,B)
    void printRGB()const{
        std::cout << '(';
        std::cout << r <<',';
        std::cout << g <<',';
        std::cout << b <<')';
    }
};