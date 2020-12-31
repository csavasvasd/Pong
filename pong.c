#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define V 20
#define H 75

void inicio (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA);
void borde (char campo[V][H]);
void raqJug (char campo[V][H], int iniJug, int finJug);
void raqIA (char campo[V][H], int iniIA, int finIA);
void pel (char campo[V][H], int pelX, int pelY);
void leercamp (char campo [V][H]);
void gameloop (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA, int modX, int modY, int modIA);
void draw (char campo[V][H]);
void input (char campo[V][H], int *pelX, int *pelY, int *iniJug, int *finJug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol);
void update (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA);

int main () {
    int pelX, pelY, iniJug, finJug, iniIA, finIA; // Posicion
    int modX, modY, modIA;
    char campo[V][H];

    // Posición
    pelX = 37;
    pelY = 10;

    iniJug = 8;
    finJug = 12;

    iniIA = 8;
    finIA = 12;

    //Modificación
    modX = -1;
    modY = -1;

    modIA = -1;

    inicio (campo,pelX,pelY,iniJug,finJug,iniIA,finIA);
    gameloop (campo,pelX,pelY,iniJug,finJug,iniIA,finIA,modX,modY,modIA);
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

    for (i = iniIA; i <= finIA; i++) {
        for (j = H - 4; j <= H - 3; j++){
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
        for (j = 0; j < H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}

void gameloop (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA, int modX, int modY, int modIA) {
    int gol;
    gol = 0;
    
    do {
        draw (campo); // Dibujar en pantalla
        input (campo, &pelX, &pelY, &iniJug, &finJug, &iniIA, &finIA, &modX, &modY, &modIA, &gol); // Verificar y modificar las posiciones
        update (campo, pelX, pelY, iniJug, finJug, iniIA, finIA); // Actualizar la matriz campo
        Sleep(3);  // Para que no corra demasiado rapido el juego
    } while (gol == 0);
}

void draw (char campo[V][H]){
    system ("cls");   // Limpiar pantalla antes de ejecutar
    leercamp (campo);
}

void input (char campo[V][H], int *pelX, int *pelY, int *iniJug, int *finJug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol) {
    
    int i;
    int key;

    // Verificación
    if (*pelY == 1 || *pelY == V - 2) {
         *modY *= -1;
    }
    if (*pelX == 1 || *pelX == H - 2) {
        *gol = 1;
    }

    if (*pelX == 4) {
        for (i = *iniJug; i <= *finJug; i++) {
            if (i == *pelY) {
                *modX *= -1;
            }
        }
    }

    if (*pelX == H - 5) {
        for (i = (*iniIA); i <= (*finIA); i++) {
            if (i == (*pelY)) {
                *modX *= -1;
            }
        }
    }
    
    if (*iniIA == 1 || *finIA == V-1) {
        *modIA *= -1;
    }
    // Modficación

    if (*gol == 0) {
        //Pelota
        *pelX += (*modX);
        *pelY += (*modY);

        //Raqueta de IA

        *iniIA += (*modIA);
        *finIA += (*modIA);

        //Raqueta jugador

        if (kbhit() == 1) {
            key = getch();

            if (key == '8'){
                if (*iniJug != 1) {
                    *iniJug -= 1;
                    *finJug -= 1;
                }
            }
            if (key == '2') {
                if (*finJug != V-2) {
                    *iniJug += 1;
                    *finJug += 1; 
                }
            }   
        }
    }
}

void update (char campo[V][H], int pelX, int pelY, int iniJug, int finJug, int iniIA, int finIA) {
    borde (campo);
    raqJug (campo, iniJug, finJug);
    raqIA (campo, iniIA, finIA);
    pel (campo, pelX, pelY);
}
