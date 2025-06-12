#include<iostream>
#define T 50
#include "Vuelos.h"
using namespace std;


class Cliente: public Vuelos //clase Hija por herencia
{
	public:
		string nombreClie, correo, contrasena, usuario, tarjeta;
		void consulta();//consulta muestra los datos del cliente
		friend Cliente operator <(Cliente x, string y); //checa que el correo sea correcto y contrasena sean correctos OPERADOR 1
		friend Cliente operator -(Cliente x ); //crea una cuenta nueva OPERADOR 2 MS
		void muestra();//muestra los datos de los vuelos SOBRECARGA 1
		void muestra(Cliente x);//muestra los datos por costo y muestra la ciudad SOBRECARGA 2
		void muestra(Cliente x, Cliente y, Cliente z); //muestra los datos por horario SOBRECARGA 3
		Cliente compra(Cliente x, Cliente y); //compra los vuelos
		
		void setAsiento(string x)
		{
			asiento=x;
		}
		Cliente(string aero, string ciu, string a, int di, int me,int ani, string hor, float tarif, 
				 string nombre, string corr, string usua, string contra, string tar);
};

Cliente::Cliente(string aero, string ciu, string a, int di, int me,int ani, string hor, float tarif, 
				 string nombre, string corr, string usua, string contra, string tar) : 
				 		Vuelos(aero,  ciu,  a,  di,  me, ani,  hor,  tarif)
{
	nombreClie=nombre;
	correo=corr;
	usuario=usua;
	contrasena=contra;
	tarjeta=tar;
	
 }		
					
Cliente operator <(Cliente x, string y) //revisa correo y contrasena
{
	Cliente casode("", "","", 0,0,0,"", 0.0,"", "", "", "", "");
	int acum=3;
	if(x.correo == y)
	{
		cout<<"Introduzca la contrasena"<<endl;
		do 
		{
			cin>>y;
			if(y!=x.contrasena)
				cout<<"Contrasena incorrecta digite de nuevo, intenteos restantes  "<<acum--<<endl;
			if(acum==-1)
			{
				cout<<"Intentos excedidos";
				return casode;
			}
				
		}while(y!=x.contrasena);
		return  x;
	}
	else 
		return casode;
}

Cliente operator -(Cliente x) //Introduce nuevos datos
{
	unsigned short int val;
	cout<<"\nCreacion de cuenta nueva"<<endl;
	cout<<"\nNombre: ";
	cin>>x.nombreClie;
	cout<<"\nCorreo: ";
	cin>>x.correo;
	cout<<"\nNombre de usuario: ";
	cin>>x.usuario;
	cout<<"\nContrasena: ";
	cin>>x.contrasena;
	cout<<"\nDesea agregar tarjeta en este momento? si=1, no=2 ";
	do
	{
		cin>>val;
		if(val!=1 && val!=2)
			cout<<"\nError digite de nuevo: ";
	}while(val!=1 && val!=2);
	if (val==1)
	{
		cout<<"\nTarjeta: ";
		cin>>x.tarjeta;
	}
	return x;
	
}

void Cliente::consulta()
{
	if(nombreClie=="" && aerolinea=="") //si es vacio
		return;
	else //caso no sea vacio
	{
			if(nombreClie=="") //si son datos de vuelo
		{
			consultaVue();
			return;
		}
		if(aerolinea=="") //si no tiene boleto comprado
		{
			cout<<"\nCuenta a nombre de: "<<nombreClie<<endl;
			cout<<"Usuario: "<<usuario<<"\nCorreo: "<<correo;
			return;
		}	
	}
	//si tiene ya boleto comprado cuenta
	cout<<"\nCuenta a nombre de: "<<nombreClie<<endl;
	cout<<"Usuario: "<<usuario<<"\nCorreo: "<<correo;
	consultaVue();
}

void Cliente::muestra()
{
	consultaVue();
}

void Cliente::muestra(Cliente x)
{
	cout<<"\n\nPrecio "<<x.tarifa;
	cout<<"\nDestino "<<x.ciudad;
	cout<<"\nAerolinea  "<<x.aerolinea;
	cout<<"\nHay asientos tipo A,B y C del 1-12 ";
	cout<<"\nArribara el "<<x.dia<<"/"<<x.mes<<"/"<<x.anio<<" a las "<<x.hora<<endl;
	
}

void Cliente::muestra(Cliente x, Cliente y, Cliente z)
{
	cout<<"\n\nHora de llegada "<<x.hora<<" Fecha "<<x.dia<<"/"<<x.mes<<"/"<<x.anio<<endl;
	cout<<"Precio "<<x.tarifa;
	cout<<"\nAerolinea  "<<x.aerolinea;
	cout<<"\nDestino "<<x.ciudad;
	cout<<"\nHay asientos tipo A,B y C del 1-12 ";	
	
	cout<<"\n\nHora de llegada "<<y.hora<<" Fecha "<<y.dia<<"/"<<y.mes<<"/"<<y.anio<<endl;
	cout<<"Precio "<<y.tarifa;
	cout<<"\nAerolinea  "<<y.aerolinea;
	cout<<"\nDestino "<<y.ciudad;
	cout<<"\nHay asientos tipo A,B y C del 1-12 ";	
	
	cout<<"\n\nHora de llegada "<<z.hora<<" Fecha "<<z.dia<<"/"<<z.mes<<"/"<<z.anio<<endl;
	cout<<"Precio "<<z.tarifa;
	cout<<"\nAerolinea  "<<z.aerolinea;
	cout<<"\nDestino "<<z.ciudad;
	cout<<"\nHay asientos tipo A,B y C del 1-12 ";	
}

Cliente Cliente::compra(Cliente x, Cliente y) //x= vuelo, y= cliente
{	
	x.nombreClie=y.nombreClie;
	x.correo=y.correo;
	x.contrasena=y.contrasena;
	x.usuario=y.usuario;
	x.tarjeta=y.tarjeta;
	return x;
}
