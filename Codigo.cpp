#include<iostream>
#include<conio.h>
#define T 50
#include"Cliente.h"
#include"AsiPol.h"
#include <string.h>
using namespace std;


int main() // operador < checa correo, operador - introduce nueva cuenta
{
	Assi as; //para polimorfismo categoria
	AsiPol asp;//para polimorfismo cant boletos
	string cadena="";//cadena que usare para el polimorfismo
	Cliente clie1("Viva Aero", "Tokio", "B32", 3, 02, 2021, "14:52", 7852.32,
	"Guadalupe Victoria", "guadalup123@gmail.com", "Guadupi15", "Papas*2", "455123456789");//usado
	
	Cliente clie2("FillFly", "Paris", "C12", 21, 02, 2021, "16:33", 8931.17,
	"Benito Juarez", "beniLoco17@hotmail.com", "BuenBeni#", "sacAtemop4n", "455111648796");//usado
	
	//los sufijos atom indican que están libres para usarse boletos de Vuelo
	Cliente atom1("Aztra Vuelo", "Minas Gerais", "",  15, 8, 2021, "17:53", 5731.38, "", "", "", "", "");
	Cliente atom2("Aire Control", "Singapur", "", 23, 03, 2021, "12:15", 5632.52, "", "", "", "", "");
	Cliente atom3("Viva Aero", "Lima", "", 12, 06, 2021, "15:25", 4312.35, "", "", "", "", "");
	
	Cliente vacio("", "","", 0,0,0,"", 0.0,"", "", "", "", ""); //cualquier cosa que necesite
	Cliente vacio2("", "","", 0,0,0,"", 0.0,"", "", "", "", ""); //si cuenta con boleto comprado quiere comprar otro
	
	//A partir de aqui ya comienza el codigo y la llamada a mis metodos ////////////////////////////////////////
	int decisionPrin=0, decisionVuelos=0, compraBoleto, centinelaSesion=0, centinelaComprar=0, centinelaComprar2=0;
	string correoVal;

	cout<<"\nBienvenido al Aeropuerto CDMX"<<endl<<endl;
	cout<<"\nQue deseas hacer?"<<endl;
	do
	{
		cout<<"1=Ver vuelos disponibles para comprar\n2=Iniciar Sesion\n3=Crear cuenta\n4=Ver datos de Cuenta\n5=Salir"<<endl;
		cin>>decisionPrin;
		switch(decisionPrin)
		{
			case 1: system("cls");
				do
				{
					cout<<"Ordenados por:\n1=Sin ordenar\n2=Costo y Ciudad\n3=Horario y Fecha"<<endl;
					cin>>decisionVuelos;
					if(decisionVuelos<1 || decisionVuelos>3)
						cout<<"\nError en dato digitie de nuevo\n";	
				}while (decisionVuelos<1 || decisionVuelos>3);
				switch(decisionVuelos)
				{
					case 1:
						atom3.muestra();
						atom2.muestra();
						atom1.muestra();	break;
					case 2:
						vacio.muestra(atom1);
						vacio.muestra(atom2);
						vacio.muestra(atom3); break;
					case 3: 
						vacio.muestra(atom2, atom3, atom1); break; 
				}
				cout<<"\n\nQuieres comprar un boleto? 1=si 2=no:  ";
				cin>>compraBoleto;
				if(compraBoleto==1)
				{
					if(vacio.nombreClie=="") //valida que se pueda comprar un boleto nuevo
					{
						cout<<"\nPrimero inicia sesion o crea una cuenta nueva";
						break;
					}
					else
						if(vacio.tarjeta=="")
						{
							cout<<"\nA tu cuenta le falta una tarjeta para comprar tu boleto, introduzca una tarjeta valida"<<endl;
							cin>>vacio.tarjeta;
							break;
						}
				}
				else
					break;
				do //checa alguna opcion válida para la compra 
				{
					cout<<"\nDe cual opcion quieres comprar boleto? 1, 2 o 3:  ";
					cin>>compraBoleto;
					if(compraBoleto<1 || compraBoleto>3)
						cout<<"\nError en dato digite de nuevo";
				}while(compraBoleto<1 || compraBoleto>3);
				
				if(centinelaComprar) //si es una cuenta que ya compro boleto con anterioridad
				{
					cadena+=as.asientos();
					cadena+=asp.asientos(); //CLARO USO DE POLIMORFISMO
					switch(decisionVuelos)
					{
						case 1: //sin orden
							switch(compraBoleto)
							{
								case 1:
									vacio2=vacio2.compra(atom3, vacio2);
								 break;
								case 2:
									vacio2=vacio2.compra(atom2, vacio2);
								break;
								case 3:
									vacio2=vacio2.compra(atom1, vacio2);
									 break;
							} break;
						case 2: //costo ciudad
							switch(compraBoleto)
							{
								case 1:
									vacio2=vacio2.compra(atom1, vacio2);
									 break;
								case 2: 
									vacio2=vacio2.compra(atom2, vacio2);
									break;
								case 3: 
									vacio2=vacio2.compra(atom3, vacio2);
									break;
							} break;
						case 3: //horario y fecha
							switch(compraBoleto)
							{
								case 1: 
									vacio2=vacio2.compra(atom2, vacio2);
									break;
								case 2: 
									vacio2=vacio2.compra(atom3, vacio2);
									break;
								case 3: 
									vacio2=vacio2.compra(atom1, vacio2);
									break;
							} break;
					}
					cout<<"\n\nBoleto comprado y reservado";
					vacio2.setAsiento(cadena);
					centinelaComprar2=1;
					vacio2.consulta();
				}
				else //si es un nuevo boleto a comprar
				{
					cadena+=as.asientos();
					cadena+=asp.asientos(); //CLARO USO DE POLIMORFISMO
					vacio.setAsiento(cadena);
					switch(decisionVuelos)
					{
						case 1: //sin orden
							switch(compraBoleto)
							{
								case 1:
									vacio=vacio.compra(atom3, vacio);
								 break;
								case 2:
									vacio=vacio.compra(atom2, vacio);
								break;
								case 3:
									vacio=vacio.compra(atom1, vacio);
									 break;
							} break;
						case 2: //costo ciudad
							switch(compraBoleto)
							{
								case 1:
									vacio=vacio.compra(atom1, vacio);
									 break;
								case 2: 
									vacio=vacio.compra(atom2, vacio);
									break;
								case 3: 
									vacio=vacio.compra(atom3, vacio);
									break;
							} break;
						case 3: //horario y fecha
							switch(compraBoleto)
							{
								case 1: 
									vacio=vacio.compra(atom2, vacio);
									break;
								case 2: 
									vacio=vacio.compra(atom3, vacio);
									break;
								case 3: 
									vacio=vacio.compra(atom1, vacio);
									break;
							} break;
						
					}
					
					centinelaComprar=1;
					vacio.setAsiento(cadena);
					cout<<"\n\nBoleto comprado y reservado";
					vacio.consulta();
				}
				cadena=""; //se limpia cadena por si compra mas boletos
				break;
				
				
				
			case 2: system("cls"); //entrando a una sesion ya existente
				if(centinelaSesion)
				{
					cout<<"\nHay una sesion activa, porfavor cierre la app y vuelva a abir si quiere cambiar de sesion";
					vacio.consulta();
					break;
				}
				cout<<"\nIntroduzca un corrreo electronico asociado a alguna cuenta"<<endl;
				cin>>correoVal;
				if(correoVal==clie1.correo)
				{
					vacio= (clie1<correoVal);
					cout<<"\nSesion iniciada";
					vacio.consulta();
					centinelaSesion=1;
					centinelaComprar=1;
				}
				else
					if(correoVal==clie2.correo)
					{
						vacio=(clie2<correoVal);
						cout<<"\nSesion iniciada";
						vacio.consulta();
						centinelaSesion=1;
						centinelaComprar=1;
					}
					else
						cout<<"\nNo hay cuenta asociada a ese correo"<<endl;
				break;
				
				
				
			case 3: system("cls");
				if(centinelaSesion)
				{
					cout<<"\nHay una sesion activa, porfavor cierre la app y vuelva a abir si quiere cambiar de sesion";
					vacio.consulta();
					break;
				}
				vacio= -vacio;
				vacio.consulta();
				cout<<"\nYa tienes tu cuenta, no sera necesario volver a iniciar sesion para comprar boleto";
				centinelaSesion=1;
				break;
			
			case 4: system("cls");
				if(centinelaSesion)
				{
					vacio.consulta();
					if(centinelaComprar2)
						vacio2.consulta();
						
				}
				else
					cout<<"\nNo hay cuenta activa"<<endl;
				break;
				
			case 5: cout<<"\nHasta Pronto"; 
					break;
			default:cout<<"\nError digite de nuevo"<<endl;	 break;
		}
		getch();	
		system("cls");
	}while (decisionPrin!=5);
	return 0;
}

