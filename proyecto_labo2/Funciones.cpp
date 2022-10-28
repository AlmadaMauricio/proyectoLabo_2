#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include "funciones.h"
#include "rlutil.h"
#include <cstring>
#include "Administrador.h"
#include "Persona.h"

using namespace std;
using namespace rlutil;

bool login()
{
	int aux;
	bool flag = false;
	bool flag2 = false;
	bool flag3 = false;
	int pos = 0;
	string aux2;
	string password;
	int cont = 0;

	Administrador admin;

	do {
		int opcion;
		char confirmarSalida;
		bool salir = false;

		setColor(CYAN);
		cout << "    Bienvenido al Sistema MONOPATIGRES" << endl;
		cout << "    Ingrese 1: Si usted ya tiene usuario admin y contraseña" << endl;
		cout << "    Ingrese 2: Para generar un nuevo usuario admin" << endl;
		cout << endl;
		cout << "Opción: ";
		cin >> opcion;
		cls();

		switch (opcion) {
		case 1:
			cout << "    Bienvenido al Sistema MONOPATIGRES" << endl;
			cout << "    --------------------------" << endl;
			cout << "    ID Administrador: " << endl;
			cout << "    Contraseña: " << endl;
			cout << "    --------------------------" << endl;

			locate(23, 3);
			cin >> aux;

			pos = buscarAdministradorPorID(aux);

			if (pos == -1)
			{
				cls();
				setColor(RED);
				locate(11, 6);
				cout << "ID incorrecto." << endl;
				flag = false;
				setColor(WHITE);
				setBackgroundColor(CYAN);
				locate(1, 1);
			}
			else
			{
				locate(17, 4);
				admin.leerDeDisco(pos);
				password = admin.getContrasenia();

				aux2 = pedirContrasenia();

				if (aux2 != password)
				{
					cls();
					locate(8, 6);
					setColor(RED);
					cout << "Contraseña incorrecta." << endl;
					flag = false;
					setColor(WHITE);
					locate(1, 1);
					cont++;
					cls();
				}
				else
				{
					locate(4, 6);
					setColor(LIGHTGREEN);
					//setBackgroundColor(GREEN);
					cout << "ID y Contraseña correctos." << endl;
					locate(11, 7);
					cout << "¡Bienvenido al Sistema Monopatigres!" << endl << endl;
					setColor(WHITE);
					setBackgroundColor(CYAN);
					system("PAUSE");
					cls();
					return true;

				}
			}
		

			if (cont == 3)
			{
				cls();
				setBackgroundColor(RED);
				setColor(YELLOW);
				cout << endl << "\t-- Ha superado el límite de intentos. Contacte al administrador. --" << endl;
				anykey();

				setColor(CYAN);
				setBackgroundColor(BLACK);
				setColor(CYAN);
				cls();
				login();

				return false;


			}
			break;
		case 2:
			crear_nuevo_admin();
				break;
			case 0:
				cout << "¿Confirma salir? (S/N) ";
				cin >> confirmarSalida;

				salir = (tolower(confirmarSalida) == 's');
				return false;
				break;
		}
		

	} while (!flag2);

	return true;
}

bool menuPrincipal() {
	setBackgroundColor(BLACK);

	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {
		setColor(CYAN);
		cls();
		cout << "\t Sistema de Gestión Monopatigres" << endl;
		cout << "-------------------------------" << endl;
		cout << "    1 - Menú Users" << endl;
		cout << "    2 - Menú Admins" << endl;
		cout << "    3 - Menú Rentas" << endl;
		cout << "    4 - Menú Monopatines" << endl;
		cout << "    5 - Menú Informes" << endl;
		cout << "    6 - Menú Configuraciones" << endl;
		cout << "-------------------------------" << endl;
		cout << "    9 - Cerrar sesion" << endl;
		cout << "-------------------------------" << endl;
		cout << "    0 - Salir del programa" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			
			break;
		case 2:
		
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 9:
			cout << "¿Desea cerrar la sesion? (S/N) ";
			cin >> confirmarSalida;

			if (tolower(confirmarSalida) == 's')
			{
				cls();
				return true;
			}
			else
			{
				salir = false;
			}
			break;
		case 0:
			cout << "¿Confirma salir? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			return false;
		}
	}
	return true;
}
void mostrarIntegrantes() {
	locate(25, 10);
	cout << "UTN - Universidad Tecnológica Nacional - FRGP" << endl;
	cout << endl;
	locate(6, 12);
	cout << "Alumnos: " << endl;
	cout << endl;
	cout << "> " << "Almada Mauricio" << endl;
	cout << "> " << "Escalante Juan Cruz" << endl;
	cout << "> " << "Illanes María José" << endl;
	
	cout << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	system("pause");
}
void mostrarLogo() {
	animacion();
	for (int i = 0; i < 3; i++)


	{
		setColor(CYAN);
		locate(16, 1);
		cout << "     ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____" << endl;
		animacion();
		locate(16, 2);
		cout << "    || M|||O |||N |||O |||P |||A |||T |||I |||G |||R |||E |||S || " << endl;
		animacion();
		locate(16, 3);
		cout << "    ||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|| " << endl;
		animacion();
		locate(16, 4);
		cout << "    |/__/|/__/|/__/|/__/|/__/|/__/|/__/|/__/|/__/|/__/|/__/|/__|| " << endl;
		animacion();

	}
}

	void mostrarLeyenda(){

		locate(16, 8);
		cout << "Sistema de Gestión desarrollado por el equipo Monopatigres" << endl;
		locate(6, 9);
		cout << "Para la materia Laboratorio II de la Carrera Técnico Universitario en Programación " << endl;

	}

void animacion()
{
	int segs = 2;

	while (segs >= 1)
	{
		Sleep(24);
		segs--;
	}
}