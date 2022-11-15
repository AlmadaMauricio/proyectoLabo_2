#include <iostream>
#include <iomanip>
#include "Fecha.h"
#include "Administrador.h"
#include "Persona.h"
#include "Funciones.h"
#include "Renta.h"
#include "ValorRenta.h"
#include "PagoRenta.h"


using namespace std;
using namespace rlutil;

int main()
{
	setlocale(LC_ALL, "Spanish");

	bool flag = false;
	bool flag2 = false;
	setBackgroundColor(BLACK);
	setColor(CYAN);
	instalacionArchivos();
	mostrarLogo();
	mostrarLeyenda();
	mostrarIntegrantes();

	cout << endl;
	cls();
	mostrarLogo();
	cout << endl;
	do
	{
		flag = login();

		if (flag)
		{
			flag2 = menuPrincipal();
		}

	} while (flag && flag2);

	/*
	User aux;
	for (int i = 0; i < 100; i++)
	{
	aux.cargar();
	}
	*/
	
	menuPrincipal();
	
	Renta aux2;
	for (int i = 0; i < 100; i++)
	{
		aux2.cargarRenta();
	}
	
	
	

	return 0;
}