#include<iostream>
#include"Aeropuerto.h"
using namespace std;
class Vuelos: public Aeropuerto //tendra la informacion de los vuelos es la clase Base para la herencia
{
	public:
		string	asiento, ciudad, hora;
		int dia, mes, anio;
		float tarifa;
		Vuelos(string aero, string ciu, string a, int di, int me,int ani, string hor, float tarif);
		void consultaVue(); //MG 
};


Vuelos::Vuelos(string aero, string ciu, string a, int di, int me,int ani, string hor, float tarif)
{
	aerolinea=aero;
	ciudad=ciu;
	asiento=a;
	dia=di;
	mes=me;
	hora=hor;
	tarifa=tarif;
	anio=ani;
}

void Vuelos::consultaVue()
{
	cout<<"\n\nAerolinea  "<<aerolinea;
	cout<<"\nDestino "<<ciudad;
	if(asiento=="")
		cout<<"\nHay asientos tipo A,B y C del 1-12 ";
	else
		cout<<"\nAsiento(s) "<<asiento;
	cout<<"\nArribara el "<<dia<<"/"<<mes<<"/"<<anio<<" a las "<<hora;
	cout<<"\nPrecio por boleto "<<tarifa;
}

