#ifndef OPCIONES_H_INCLUDED
#define OPCIONES_H_INCLUDED

void juego1p(char nombre[][30], int matriz[][3], int jug[]);
void juego2p(char nombre[][30], int matriz[][3], int jug[]);
void puntuacion(char nombre[][30], int matriz[][3], int jug[], int tam);
void fin();

/// ----------------- OPCION 1 -----------------
void juego1p(char nombre[][30], int matriz[][3], int jug[]){
    int rondas,opcion,jugador;
    int i;
    int gen[1]; /// Para Generala Servida
    ponerCero(gen,1);
    int puntaje[1][10];
    ponerNegativo(puntaje,1,10);
    jug[0]++;
    jugador=jug[0];

    cargarNombres(nombre,jugador,1);
    cout<<endl<<"CANTIDAD DE RONDAS: ";
    cin>>rondas;
    cout<<endl<<"--------- MENU DADOS ---------"<<endl;
    cout<<"1. MANUAL"<<endl;
    cout<<"2. ALEATORIO"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"OPCION: "<<endl;
    cin>>opcion;
    system("cls");

    for(i=0;i<rondas;i++){
        if(gen[0]==0){
            funcionRonda(nombre,matriz,puntaje,jugador,opcion,i+1,1,gen);
        }
    }
    system("cls");
    findePartida(nombre,matriz,jugador);
}

/// ----------------- OPCION 2 -----------------
void juego2p(char nombre[][30], int matriz[][3], int jug[]){
    int jug1,jug2,rondas,opcion,ganador;
    int i;
    int gen[2]; /// Para Generala Servida
    ponerCero(gen,2);
    int puntaje[2][10];
    ponerNegativo(puntaje,2,10);
    jug1=jug[0]+1;
    jug2=jug[0]+2;
    jug[0]+=2;

    cargarNombres(nombre,jug1,2);
    cout<<endl<<"CANTIDAD DE RONDAS: ";
    cin>>rondas;
    cout<<endl<<"--------- MENU DADOS ---------"<<endl;
    cout<<"1. MANUAL"<<endl;
    cout<<"2. ALEATORIO"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"OPCION: "<<endl;
    cin>>opcion;
    system("cls");

    for(i=0;i<rondas;i++){
        if(gen[0]==0){
            entreTurnos(nombre,matriz,jug1,jug2,i+1);
            funcionRonda(nombre,matriz,puntaje,jug1,opcion,i+1,1,gen);
            if(gen[0]==1){
                system("cls");
                gotoxy(40,12);
                cout<<"El proximo jugador tiene la posibilidad de sacar Generala Servida"<<endl;
                gotoxy(47,18);
                system("pause");
            }
            entreTurnos(nombre,matriz,jug2,jug1,i+1);
            funcionRonda(nombre,matriz,puntaje,jug2,opcion,i+1,2,gen);
        }
    }

    system("cls");
    if(gen[0]==1){
        ganador=gen[1];
        findePartida(nombre,matriz,ganador);
    }
    else {
        if(matriz[jug1-1][2]>matriz[jug2-1][2]){
            findePartida(nombre,matriz,jug1);
        }
        else {
            if(matriz[jug1-1][2]==matriz[jug2-1][2]){
                dibujarRecuadro(50,10,30,6);
                gotoxy(58,13);
                cout<<"ES UN EMPATE"<<endl;
                gotoxy(48,19);
            }
            else {
            findePartida(nombre,matriz,jug2);
            }
        }
    }
}

/// ----------------- OPCION 3 -----------------
void puntuacion(char nombre[][30], int matriz[][3], int jug[], int tam){
    int maximo;
    maximo = maximoMatriz(matriz,tam);
    dibujarRecuadro(40,10,50,10);
    if(jug[0]!=0){
        gotoxy(55,12);
        cout<<"PUNTUACION MAS ALTA"<<endl;
        gotoxy(54,14);
        cout<<"  JUGADOR: "<<nombre[maximo]<<endl;
        gotoxy(54,15);
        cout<<"  CANTIDAD DE TIRADAS: "<<matriz[maximo][1]<<endl;
        gotoxy(54,16);
        cout<<"  PUNTAJE FINAL: "<<matriz[maximo][2]<<endl;
        gotoxy(48,18);
    }
    else {
        gotoxy(50,13);
        cout<<"AUN NO HAY PUNTAJES DISPONIBLES"<<endl<<endl;
        gotoxy(47,18);
    }
}

void fin(){
    dibujarRecuadro(50,10,30,6);
    gotoxy(57,13);
    cout<<"GRACIAS POR JUGAR!"<<endl;
    gotoxy(58,19);
}
#endif // OPCIONES_H_INCLUDED
