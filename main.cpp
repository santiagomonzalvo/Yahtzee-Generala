#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdlib.h>

using namespace std;
#include "rlutil.h"
#include "masfunciones.h"
#include "funciones.h"
#include "opciones.h"

int main(){
    colores();
    int opcion;
    int jugador[1];
    ponerCero(jugador,1);
    char nombre[10][30];
    int matriz[10][3];
    ponerCeroM(matriz,10,3);
    while(true){
        menu();
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: juego1p(nombre,matriz,jugador);
                    break;
            case 2: juego2p(nombre,matriz,jugador);
                    break;
            case 3: puntuacion(nombre,matriz,jugador,10); /// 10 es el cantidad de jugadores max
                    break;
            case 4: fin();
                    return 0;
                    break;
        }
        system("pause");
    }
    return 0;
}
