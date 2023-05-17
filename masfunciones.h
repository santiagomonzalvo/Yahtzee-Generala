#ifndef MASFUNCIONES_H_INCLUDED
#define MASFUNCIONES_H_INCLUDED

#include "rlutil.h"

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void cargarNombres(char v[][30],int num,int tam);
void cargarManual(int v[], int tam);
void cargarAleatorio(int v[], int tam, int limite);
void mostrarVector(int v[], int tam);
void cambiarVector(int v[],int v2[], int num1, int num2);
void ponerCero(int v[], int tam);
void ponerCeroM(int v[][3], int tam1, int tam2);
void ponerNegativo(int v[][10], int tam1, int tam2);
void cargarPuntaje(int v1[][10],int v2[],int num1,int num2);
int sumarVector(int v[][10], int tam, int num);
int contarNumerosRepetidos(int v[], int tam, int num);
int posicionNumeroEnVector(int v[], int tam, int num);
int maximoMatriz(int v[][3], int tam); ///devuelve  la posición (primera) que ocupa el máximo en la matriz
void dibujarRecuadro(int x,int y,int ancho,int alto);
void dado(short iniX, short iniY, short ancho, short alto, int num);
void mostrarDados(int v[], int tam);
void dado(short iniX, short iniY, short ancho, short alto,int num);
void mostrarDados(int v[], int tam);
void dado1(short iniX);
void dado2(short iniX);
void dado3(short iniX);
void dado4(short iniX);
void dado5(short iniX);
void dado6(short iniX);
void colores();

/// DESARROLLO DE FUNCIONES / DEFINICIONES
void dibujarRecuadro(int x,int y,int ancho,int alto){
    for(int i=x;i<=x+ancho;i+=2){
        gotoxy(i,y);
        cout<<"*";
        gotoxy(i,y+alto);
        cout<<"*";
    }
    for(int i=y;i<=y+alto;i++){
        gotoxy(x,i);
        cout<<"*";
        gotoxy(x+ancho,i);
        cout<<"*";
    }
}

void cargarNombres(char v[][30], int num, int tam){
    cin.ignore();
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE NOMBRE DEL JUGADOR "<<i+1<<": "<<endl;
        cin.getline(v[(num-1)+i],30);
    }
}

void cargarManual(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    cout<<endl;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
}

void cambiarVector(int v1[],int v2[],int num1,int num2){
    if (num2==1) {
        cout<<"Ingresar valor del dado: ";
        cargarManual(v2,1);
    }
    else cargarAleatorio(v2,1,6);
    v1[num1-1]=v2[0];
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

void ponerCeroM(int v[][3], int tam1, int tam2){
    int i,j;
    for(i=0;i<tam1;i++){
        for(j=0;j<tam2;j++){
            v[i][j]=0;
        }
    }
}

void ponerNegativo(int v[][10], int tam1, int tam2){
    int i,j;
    for(i=0;i<tam1;i++){
        for(j=0;j<tam2;j++){
            v[i][j]=-1;
        }
    }
}

void cargarPuntaje(int v1[][10],int v2[],int num1, int num2){
    v1[num2-1][num1]=v2[num1];
}

int sumarVector(int v[][10], int tam,  int num){
    int suma=0;
    int i;
    for(i=0;i<tam;i++){
        if(v[num-1][i]!=-1) suma+=v[num-1][i];
    }
    return suma;
}

int contarNumerosRepetidos(int v[], int tam, int num){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==num) cant++;
        }
    return cant;
}

int posicionNumeroEnVector(int v[],int tam, int num){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==num) return i;
        }
    return -1;
}

int maximoMatriz(int v[][3], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i][2]>v[posMax][2]) {
                posMax=i;
        }
    }
    return posMax;
}

void dado(short iniX, short iniY, short ancho, short alto, int num){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            //rlutil::setBackgroundColor(rlutil::BLACK);
            //rlutil::setColor(rlutil::WHITE);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                switch(num){
                    case 1: dado1(iniX);
                            break;
                    case 2: dado2(iniX);
                            break;
                    case 3: dado3(iniX);
                            break;
                    case 4: dado4(iniX);
                            break;
                    case 5: dado5(iniX);
                            break;
                    case 6: dado6(iniX);
                            break;
                }
            }
        }
    }
}
void dado1(short iniX){
    int a;
    a=iniX+4;
    gotoxy(a,9);
    cout<<(char)254;
}
void dado2(short iniX){
    int a;
    a=iniX+2;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,10);
    cout<<(char)254;
}
void dado3(short iniX){
    int a;
    a=iniX+2;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+4;
    gotoxy(a,9);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,10);
    cout<<(char)254;
}
void dado4(short iniX){
    int a;
    a=iniX+2;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+2;
    gotoxy(a,10);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,10);
    cout<<(char)254;
}
void dado5(short iniX){
    int a;
    a=iniX+2;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+4;
    gotoxy(a,9);
    cout<<(char)254;
    a=iniX+2;
    gotoxy(a,10);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,10);
    cout<<(char)254;

}
void dado6(short iniX){
    int a;
    a=iniX+2;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,8);
    cout<<(char)254;
    a=iniX+2;
    gotoxy(a,9);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,9);
    cout<<(char)254;
    a=iniX+2;
    gotoxy(a,10);
    cout<<(char)254;
    a=iniX+6;
    gotoxy(a,10);
    cout<<(char)254;
}
void colores(){
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::setColor(rlutil::WHITE);
}
void mostrarDados(int v[], int tam){
    int i,num;
    int a=1;
    cout<<endl<<endl;
    for(i=0;i<tam;i++){
        num=v[i];
        dado(a,7,8,4,num);
        a=a+10;
    }
    cout<<endl;
}


#endif // MASFUNCIONES_H_INCLUDED
