#include"Assi.h"
#include<iostream>

using namespace std;

class AsiPol: public Assi //clase para usar el polimorfismo
{
	public:
		string asientos() //POLIMORFISMO
		{
			string num;
			cout<<"\nSeleccione el numero de asiento, tenemos del 1-12 disponibles\nEn caso de querer varios boletos escriba 1,2,3, etc."<<endl;
			cin>>num;
			return num;
		}
};
