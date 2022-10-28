#include <iostream>
#include <iomanip>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Funciones.h"


using namespace std;
using namespace rlutil;

int main()
{
	setlocale(LC_ALL, "Spanish");

	bool flag = false;
	bool flag2 = false;

	

	do
	{
		flag = login();

		if (flag)
		{
			flag2 = menuPrincipal();
		}

	} while (flag && flag2);

	

	menuPrincipal();
	
	return 0;
}