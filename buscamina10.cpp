#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
using namespace std;

void imprimirColumna(char tablero[5][5],int vida);
void minasAleatorias( char tablero[5][5]);
void selecCasillero( char tablero[5][5]);
int main (){
	int vida;
	char tablero[5][5];
	cout<<"      ~BUSCA MINAS~  "<<endl;
	imprimirColumna(tablero,vida);
	minasAleatorias(tablero);
	selecCasillero(tablero);
}
void imprimirColumna(char tablero[5][5],int vida){

	cout<<endl;
	for ( int numFilas=0 ; numFilas<6;numFilas++){
		if( numFilas==0){
		cout<<"[   ]";
		}else {
		cout<<"[ "<<numFilas<<" ]";
		}
	}
	cout<<endl;
	
for(int fila =0 ; fila<5 ;fila++){
		for (int barra=0 ;barra<4 ;barra++){
			cout<<"--------";
		}
		cout<<endl;
		
		cout<<"[ "<<fila+1<<" ]";
		
			
		for (int columna =0;columna<5;columna++){
			if (vida==0){
					 if ( tablero[fila][columna]=='*') {
					cout<<"[ * ]";}
					else if ( tablero[fila][columna]=='X'){
						cout<<"[ X ]";
					}else{
				cout<<"[ . ]";
						}
				}else{
				 if ( tablero[fila][columna]=='X'&& vida){
						cout<<"[ X ]";
							}
				else{
				cout<<"[ . ]";
					}
			}
		}
		cout<<endl;
				
	}
	cout<<endl;
	}
void minasAleatorias( char tablero[5][5]){
	int minaFila;
	int minaColumna;
	srand(time(NULL));
	for (int alea=0 ; alea<5 ; alea++){

 		minaFila=rand()%4;
 		minaColumna=rand()%4;
 		
 		tablero[minaFila][minaColumna]='*';
	}
};
void selecCasillero( char tablero[5][5]){
	int filaIngresada,columIngresada;
	int vida;
	int espaciosVacios;
	bool mina;
	espaciosVacios=20;

	do{
	cout<<"Ingrese Fila"<<endl;
	do{
	cin>>filaIngresada;
	if(filaIngresada>5){
		cout<<"Numero invalido ingrese una fila menor o igual que 5"<<endl;
	}
  }while(filaIngresada>5);
	cout<<"Ingrese Columna"<<endl;
	do{	
	cin>>columIngresada;
	if(columIngresada>5){
		cout<<"Numero invalido ingrese una columna menor o igual que 5"<<endl;
	}
	}while(columIngresada>5);
	if (tablero[filaIngresada-1][columIngresada-1]=='*'){
		
		espaciosVacios=0;
		vida= 0 ;
	}else{
		tablero[filaIngresada-1][columIngresada-1]='X';
		
		vida= 1;
	}
		imprimirColumna(tablero,  vida);
		espaciosVacios--;
	}while(espaciosVacios>0  );
	if( vida==1){
		cout<<"HAS GANADO EN EL BUSCAMINAS "<<endl;
	}else {
		cout<<"HAS PERDIDO , CAISTE EN UNA MINA";
	}
	
}


