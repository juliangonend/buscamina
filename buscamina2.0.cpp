#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
using namespace std;

void imprimirColumna(char tablero[5][5],int vida);
void minasAleatorias( char tablero[5][5]);
void selecCasillero( char tablero[5][5]);
int cercaniaMina(char tablero[5][5],int fila,int columna);
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
				 if ( tablero[fila][columna]!='*'&& vida){
						cout<<"[ "<<tablero[fila][columna]<<" ]";
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

 		minaFila=rand()%5;
 		minaColumna=rand()%5;
 		
 		tablero[minaFila][minaColumna]='*';
	}
	for (int fila=0;fila<5;fila++){
		for (int columna=0;columna<5 ;columna++){
			if (tablero[fila][columna]!= '*'){
				tablero[fila][columna]='.';
			}
		}
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
	
		int contMinas=cercaniaMina(tablero,filaIngresada-1,columIngresada-1);
		if (contMinas>0 ){
			char charContMinas = contMinas  + '0';
			tablero[filaIngresada-1][columIngresada-1]=charContMinas;
		}else{	tablero[filaIngresada-1][columIngresada-1]='X';
		}
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
int cercaniaMina(char tablero[5][5],int fila,int columna){
int contMinas=0;;

if(tablero[fila-1][columna]=='*' ){
	contMinas ++;
}
if (tablero[fila+1][columna]=='*' ){
contMinas ++;
}
if (tablero[fila][columna-1]=='*' ){
contMinas ++;
}
if (tablero[fila][columna+1]=='*' ){
	contMinas ++;
}
return contMinas;
}

