#include <stdio.h>
#include <stdlib.h>
#define V 20
#define H 75

void inicio (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA);
void borde (char campo[V][H]);
void raqJug (char campo[V][H], int iniJug, int finJug);
void raqIA (char campo[V][H], int iniIA, int finIA);
void pel (char campo[V][H], int pelX, int pelY);
void leercamp (char campo [V][H]);

int main () {
    int pelX, pelY, iniJug, finJug, iniIA, finIA;
    char campo[V][H];
    pelX = 37;
    pelY = 10;

    iniJug = 8;
    finJug = 12;

    iniIA = 8;
    finIA = 12;

    inicio (campo,pelX,pelY,iniJug,finJug,iniIA,finIA);
    leercamp (campo);
    system ("pause");
    return 0;
}

void inicio (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA) {
    borde (campo);
    raqJug (campo, iniJug, finJug);
    raqIA (campo, iniIA, finIA);
    pel (campo, pelX, pelY);
}

void borde (char campo[V][H]) {
    int i, j;

    for (i = 0; i < V; i++) {
        for (j = 0; j < H; j++){
            if (i == 0 || i == V-1){
                campo[i][j] = '-';
            }
            else if (j == 0 || j == H-1){
                campo[i][j] = '|';
            }
            else {
                campo[i][j] = ' ';
            }
        }
    }
}

void raqJug (char campo[V][H], int iniJug, int finJug) {
    int i, j;
    for (i = iniJug; i <= finJug; i++) {
        for (j = 2; j <= 3; j++) {
            campo [i][j] = 'X';
        }
    }
}

void raqIA (char campo [V][H], int iniIA, int finIA) {
    int i, j;

    for (i = iniIA; i < finIA; i++) {
        for (j = H -4; j <= H - 3; j++){
            campo [i][j] = 'X';
        }
    }

}

void pel (char campo[V][H], int pelX, int pelY) {
    campo [pelY] [pelX] = 'O';
}

void leercamp (char campo [V][H]) {
    int i, j;

    for (i = 0; i < V; i++){
        for(j = 0; j < H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}
