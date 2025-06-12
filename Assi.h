
#include<iostream>

using namespace std;

class Assi//clase que usare solo para el polimorfismo
{
	public:
	
	string virtual asientos() //categoria de asientos POLIMORFISMO
	{
		string car;
		cout<<"Seleccione la categoria de su vuelo A=ejecutivo, B=turista, C=economico"<<endl;
		cin>>car;
		return car;
	} 	
};

