#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void funcionRonda(char nombre[][30], int mat[][3], int puntaje[][10], int jugador1, int jugador2, int opcion, int ronda, int num, int gen[]);
void CombPosibles(int v1[], int v2[], int tam1, int tam2);
void verTablaPuntaje(int v1[][10], char v2[][30], int tam, int num);
void entreTurnos(char nombre[][30], int mat[][3], int jugador1, int jugador2, int ronda);
void findePartida(char v1[][30], int v2[][3], int num);
void menu();

/// DESARROLLO DE FUNCIONES / DEFINICIONES
void menu(){
system("cls");
        dibujarRecuadro(40,10,50,10);
        gotoxy(63,12);
        cout<<"MENU"<<endl;
        gotoxy(52,14);
        cout<<"1. JUEGO NUEVO (1 JUGADOR)"<<endl;
        gotoxy(52,15);
        cout<<"2. JUEGO NUEVO (2 JUGADORES)"<<endl;
        gotoxy(52,16);
        cout<<"3. PUNTUACION MAS ALTA"<<endl;
        gotoxy(60,17);
        cout<<"4. SALIR"<<endl;
        gotoxy(60,19);
        cout<<"OPCION: "<<endl;
        gotoxy(68,19);
        }

void funcionRonda(char nombre[][30], int mat[][3], int puntaje[][10], int jugador, int opcion, int ronda, int num, int gen[]){
    char categorias[10][30]={"Juego de 1","Juego de 2","Juego de 3","Juego de 4","Juego de 5","Juego de 6","Escalera","Full\t","Poker    ","Generala"};
    int cantidad,posicion,comb;
    char lanzar;
    int dados[5], vAux[5];
    int combinaciones[10];
    int i,j;
    int tiradasTotal,puntuacion;
    ponerCero(vAux,5);
    ponerCero(combinaciones,10);

    tiradasTotal=mat[jugador-1][1];
    puntuacion=mat[jugador-1][2];

    cout<<" TURNO DE "<<nombre[jugador-1]<<endl;
    cout<<"================================================="<<endl;
    cout<<" RONDA No: "<<ronda<<'\t';
    cout<<"|  PUNTAJE TOTAL: "<<sumarVector(puntaje,10,num);
    int tirada=1;
    tiradasTotal++;
    cout<<endl<<" TIRADA No: "<<tirada<<'\t';
    cout<<"|  TIRADAS TOTALES: "<<tiradasTotal<<endl;
    cout<<"================================================="<<endl;
    if (opcion==1) {
        gotoxy(6,6);
        cout<<"INGRESAR 5 VALORES DE DADOS:"<<endl;
        cargarManual(dados,5);
    }
    else cargarAleatorio(dados,5,6);
    mostrarDados(dados,5);
    do{
        cout<<endl<<"CONTINUAR LANZANDO (S/N)?  ";
        cin>>lanzar;
        if(lanzar=='S'||lanzar=='s'){
            tirada++;
            tiradasTotal++;
            cout<<endl<<"CUANTOS DADOS VUELVE A TIRAR?  ";
            cin>>cantidad;
            if(cantidad==5) {
                    if (opcion==1) {
                        cout<<"INGRESE 5 VALORES DE DADOS: "<<endl;
                        cargarManual(dados,5);
                    }
                    else cargarAleatorio(dados,5,6);
            }
            else {
                cout<<endl<<"CUALES? "<<endl;
                for(i=0;i<cantidad;i++){
                    cout<<"Indicar posicion: ";
                    cin>>posicion;
                    cambiarVector(dados,vAux,posicion,opcion);
                }
            }
            system("cls");
            cout<<" TURNO DE "<<nombre[jugador-1]<<endl;
            cout<<"================================================="<<endl;
            cout<<" RONDA No: "<<ronda<<'\t';
            cout<<"|  PUNTAJE TOTAL: "<<sumarVector(puntaje,10,num);
            cout<<endl<<" TIRADA No: "<<tirada<<'\t';
            cout<<"|  TIRADAS TOTALES: "<<tiradasTotal<<endl;
            cout<<"================================================="<<endl;
            mostrarDados(dados,5);
        }
    } while(tirada<3&&(lanzar=='S'||lanzar=='s'));

    CombPosibles(dados,combinaciones,5,10);

    if(combinaciones[9]==50 && tirada==1){
        system("cls");
        gotoxy(58,12);
        cout<<"GENERALA SERVIDA!"<<endl;
        gen[0]++;
        gen[1]=jugador;
        mat[jugador-1][0]=jugador;
        mat[jugador-1][1]=tiradasTotal;
        mat[jugador-1][2]=puntuacion+50;
        gotoxy(47,18);
        system("pause");
    }

    if(gen[0]==0){
        cout<<endl<<endl<<"----------------------------------"<<endl;
        cout<<"COMBINACIONES POSIBLES: "<<endl;
        cout<<"----------------------------------"<<endl;
        for(j=0;j<10;j++){
            if(puntaje[num-1][j]==-1){
                if(combinaciones[j]!=0) cout<<categorias[j]<<'\t'<<combinaciones[j]<<endl;
            }
        }

        verTablaPuntaje(puntaje,categorias,10,num);

        cout<<"--------------------------------------"<<endl;
        cout<<"SELECCIONAR COMBINACION ELEGIDA (1-10): "<<endl;
        cout<<"(En caso de seleccionar una Combinacion en la que no haya logrado un puntaje, se anulara dicha Combinacion)"<<endl;
        cin>>comb;

        if(puntaje[num-1][comb-1]==-1) cargarPuntaje(puntaje,combinaciones,comb-1,num);
        puntuacion=sumarVector(puntaje,10,num);

        cout<<endl<<"PUNTAJE TOTAL: "<<puntuacion<<endl;

        mat[jugador-1][0]=jugador;
        mat[jugador-1][1]=tiradasTotal;
        mat[jugador-1][2]=puntuacion;

        system("pause");
        system("cls");
    }
}

void CombPosibles(int v1[], int v2[], int tam1, int tam2){
    int i;
    ponerCero(v2,tam2);

    /// JUEGO DE 1 A 6
    int vRep[6]; // Guarda las repeticiones de cada valor de los dados
    for(i=0;i<6;i++){
        vRep[i]=contarNumerosRepetidos(v1,tam1,i+1);
        v2[i]=vRep[i]*(i+1);
    }

    /// ESCALERA
    if(contarNumerosRepetidos(vRep,6,1)==5){
        if(posicionNumeroEnVector(vRep,6,0)==0||posicionNumeroEnVector(vRep,6,0)==5) v2[6]=25;
    }

    /// FULL
    if(contarNumerosRepetidos(vRep,6,3)==1) {
        if(contarNumerosRepetidos(vRep,6,2)==1) v2[7]=30;
    }

    /// POKER
    if(contarNumerosRepetidos(vRep,6,4)==1||contarNumerosRepetidos(vRep,6,5)==1) v2[8]=40;

    /// GENERALA
    if(contarNumerosRepetidos(vRep,6,5)==1) v2[9]=50;
}

void verTablaPuntaje(int v1[][10], char v2[][30], int tam, int num){
    int i;
    cout<<"----------------------------------"<<endl;
    cout<<"TABLA DE PUNTAJES: "<<endl;
    cout<<"----------------------------------"<<endl;
    for(i=0;i<tam;i++){
        cout<<i+1<<". "<<v2[i]<<'\t';
        if(v1[num-1][i]!=-1){
            cout<<v1[num-1][i]<<endl;
        }
        else {
            cout<<"__"<<endl;
        }
    }
}

void entreTurnos (char nombre[][30], int mat[][3], int jugador1, int jugador2, int ronda){
    system("cls");
    dibujarRecuadro(40,10,50,10);
    gotoxy(57,11);
    cout<<"  RONDA No: "<<ronda<<endl;
    gotoxy(49,12);
    cout<<"  PROXIMO TURNO: "<<nombre[jugador1-1]<<endl;
    gotoxy(55,13);
    cout<<"  LANZAMIENTOS: "<<mat[jugador1-1][1]<<endl<<endl;
    gotoxy(48,15);
    cout<<"  PUNTAJE "<<nombre[jugador1-1]<<": "<<mat[jugador1-1][2]<<" PUNTOS"<<endl;
    gotoxy(48,16);
    cout<<"  PUNTAJE "<<nombre[jugador2-1]<<": "<<mat[jugador2-1][2]<<" PUNTOS"<<endl;
    gotoxy(48,18);
    system("pause");
    system("cls");
}

void findePartida(char v1[][30], int v2[][3] , int num){
    dibujarRecuadro(40,10,50,10);
    gotoxy(50,13);
    cout<<"GRACIAS POR JUGAR! EL GANADOR ES: "<<endl;
    gotoxy(60,14);
    cout<<v1[num-1]<<endl;
    gotoxy(53,15);
    cout<<"CANTIDAD DE TIRADAS: "<<v2[num-1][1]<<endl;
    gotoxy(52,16);
    cout<<"PUNTAJE TOTAL ACUMULADO: "<<v2[num-1][2]<<endl;
    gotoxy(48,18);
}

#endif // FUNCIONES_H_INCLUDED
