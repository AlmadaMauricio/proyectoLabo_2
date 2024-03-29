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
#include "User.h"
#include "Monopatin.h"
#include "ValorRenta.h"
#include "PagoRenta.h"
#include "Renta.h"
#include "MonopatinPorPais.h"
#include "recaudacionesPorAdmin.h"

void instalacionArchivos()
{

	setBackgroundColor(BLACK);
	setColor(GREEN);
	cls();

	checkArchivoUsers();
	checkArchivoAdmins();
	checkArchivoRenta();
	checkArchivoMonopatin();
	checkArchivoPagosRenta();
	checkArchivoPrecioRenta();

	cout << endl << "\t-- Presione enter para continuar --";
	system("PAUSE > null");
	system("cls");
}

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
		setBackgroundColor(BLACK);
		setColor(CYAN);
		cout << "    Bienvenido al Sistema MONOPATIGRES" << endl;
		cout << "    Ingrese 1: Si usted ya tiene usuario admin y contrase�a" << endl;
		cout << "    Ingrese 2: Para generar un nuevo usuario admin" << endl;
		cout << endl;
		cout << "Opci�n: ";
		cin >> opcion;
		cls();

		switch (opcion) {
		setBackgroundColor(BLACK);
		setColor(CYAN);
		case 1:
			cout << "    Bienvenido al Sistema MONOPATIGRES" << endl;
			cout << "    --------------------------" << endl;
			cout << "    ID Administrador: " << endl;
			cout << "    Contrase�a: " << endl;
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
					cout << "Contrase�a incorrecta." << endl;
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
					cout << "ID y Contrase�a correctos." << endl;
					locate(11, 7);
					cout << "�Bienvenido al Sistema Monopatigres!" << endl << endl;
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
				cout << endl << "\t-- Ha superado el l�mite de intentos. Contacte al administrador. --" << endl;
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
				cout << "�Confirma salir? (S/N) ";
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
	setColor(CYAN);

	int opcion;
	char confirmarSalida;
	bool salir = false;


	while (!salir) {
		setColor(CYAN);
		cls();
		cout << "\t Sistema de Gesti�n Monopatigres" << endl;
		cout << "-------------------------------" << endl;
		cout << "    1 - Men� Users" << endl;
		cout << "    2 - Men� Admins" << endl;
		cout << "    3 - Men� Rentas" << endl;
		cout << "    4 - Men� Monopatines" << endl;
		cout << "    5 - Men� Informes" << endl;
		cout << "    6 - Men� Configuraciones" << endl;
		cout << "-------------------------------" << endl;
		cout << "    9 - Cerrar sesion" << endl;
		cout << "-------------------------------" << endl;
		cout << "    0 - Salir del programa" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			menuUsers();
			break;
		case 2:
			menuAdmins();
			break;
		case 3:
			menuRentas();
			break;
		case 4:
			menuMonopatines();
			break;
		case 5:
			menuInformes();
			break;
		case 6:
			menuConfiguracion();
			break;
		case 9:
			cout << "�Desea cerrar la sesion? (S/N) ";
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
			cout << "�Confirma salir? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			return false;
		}

	}
	return true;
}

void todoAMayus(char* apellido)
{

	int len = strlen(apellido);

	for (int i = 0; i < len; i++)
	{
		apellido[i] = toupper(apellido[i]);
	}
}

void mostrarIntegrantes() {
	locate(25, 10);
	cout << "UTN - Universidad Tecnol�gica Nacional - FRGP" << endl;
	cout << endl;
	locate(6, 12);
	cout << "Alumnos: " << endl;
	cout << endl;
	cout << "> " << "Almada Mauricio" << endl;
	cout << "> " << "Escalante Juan Cruz" << endl;
	cout << "> " << "Illanes Mar�a Jos�" << endl;
	
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
		cout << "Sistema de Gesti�n desarrollado por el equipo Monopatigres" << endl;
		locate(6, 9);
		cout << "Para la materia Laboratorio II de la Carrera T�cnico Universitario en Programaci�n " << endl;

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

void menuUsers()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tUsers" << endl;
		cout << "---------------------------------" << endl;
		cout << "    1 - Cargar nuevo User" << endl;
		cout << "    2 - Modificar User" << endl;
		cout << "    3 - Eliminar User" << endl;
		cout << "---------------------------------" << endl;
		cout << "    4 - Listados" << endl;
		cout << "    5 - Consultas" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			cargar_nuevo_user();
			break;
		case 2:
			modificar_user();
			break;
		case 3:
			baja_user();
			break;
		case 4:
			menuListadosUsers();
			break;
		case 5:
			menuConsultasUsers();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuListadosUsers()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tListados Users" << endl;
		cout << "-------------------------------" << endl;
		cout << "    1 - Listar todos los Users" << endl;
		cout << "    2 - Listar users ordenados alfabeticamente" << endl;
		cout << "    3 - Listar users por antig�edad" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listado_general_users();
			anykey();
			break;
		case 2:
			listarUserAlfabeticamente();
			anykey();
			break;
		case 3:
			listarUserPorFecha();
			anykey();
			break;
		case 4:

			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuConsultasUsers()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tConsultas Users" << endl;
		cout << "-------------------------------" << endl;
		cout << "    1 - Consulta por DNI" << endl;
		cout << "    2 - Consulta por ID" << endl;
		cout << "    3 - Consulta por Apellido" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaPorDni();
			break;
		case 2:
			consulta_Por_Id();
			break;
		case 3:
			consulta_Por_Apellido();
			break;
		case 4:


			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuAdmins()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tAdministradores" << endl;
		cout << "---------------------------------" << endl;
		cout << "    1 - Crear nuevo Administrador " << endl;
		cout << "    2 - Modificar Administrador " << endl;
		cout << "    3 - Eliminar Administrador " << endl;
		cout << "---------------------------------" << endl;
		cout << "    4 - Listados de administradores" << endl;
		cout << "    5 - Buscar Administrador por ID" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			crear_nuevo_admin();
			break;
		case 2:
			modificar_admin();
			break;
		case 3:
			baja_admin();
			break;
		case 4:
			menuListadosAdmin();
			break;
		case 5:
			consulta_admin_Por_ID();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosAdmin()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\t Listados administradores" << endl;
		cout << "---------------------------------" << endl;
		cout << "    1 - Listados general de administradores" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listado_general_admin();
			anykey();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuRentas()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tRentas" << endl;
		cout << "---------------------------------" << endl;
		cout << "    1 - Crear nueva Renta" << endl;
		cout << "    2 - Modificar Renta" << endl;
		cout << "---------------------------------" << endl;
		cout << "    3 - Listados" << endl;
		cout << "    4 - Consultas" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			cargarNuevaRenta();
			anykey();
			break;
		case 2:
			modificar_renta();
			break;
		case 3:
			menuListadosRentas();
			break;
		case 4:
			menuConsultasRentas();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosRentas()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tListados Rentas" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "    1 - Listar todas las Rentas" << endl;
		cout << "    2 - Listar Rentas por ID de user" << endl;
		cout << "    3 - Listar Rentas por orden descendente" << endl;
		cout << "    4 - Listar Rentas por fecha Descendente" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoRentas();
			anykey();
			break;
		case 2:
			listadoRentasPorIdUser();
			anykey();
			break;
		case 3:
			listarRentasPorIdDesc();
			anykey();
			break;
		case 4:
			listarRentaPorFechaDesc();
			anykey();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuConsultasRentas()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tConsultas Rentas" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "    1 - Consulta por ID de Renta" << endl;
		cout << "    2 - Consulta por Fecha" << endl;
		cout << "    3 - Consulta por A�o" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaRentasPorId();
			anykey();
			break;
		case 2:
			consultaRentasPorFecha();
			anykey();
			break;
		case 3:
			consultaRentasPorAnio();
			anykey();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuMonopatines()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();

		cout << "\tMonopatines" << endl;
		cout << "---------------------------------" << endl;
		cout << "    1 - Modificar monopatin " << endl;
		cout << "---------------------------------" << endl;
		cout << "    2 - Listados" << endl;
		cout << "    3 - Consultas" << endl;
		cout << "---------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			modificar_monopatin();
			break;
		case 2:
			menuListadosMonopatines();
			break;
		case 3:
			menuConsultasMonopatines();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void menuListadosMonopatines()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tListados Monopatines" << endl;
		cout << "----------------------------------" << endl;
		cout << "    1 - Listar todos los monopatines" << endl;
		cout << "    2 - Listado por N� de serie" << endl;
		cout << "----------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			listadoGeneralMonopatines();
			anykey();
			break;
		case 2:
			listadoDeMonopatinesPorNumDeSerie();
			anykey();
			break;

		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuConsultasMonopatines()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\tConsultas Monopatines" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "    1 - Consultas de monopatines por n�mero de serie" << endl;
		cout << "    2 - Consultas por ID de monopatines" << endl;
		cout << "    3 - Consulta de monopatines por modelo" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			consultaMonopatinPorNumSerie();
			anykey();
			break;
		case 2:
			consultaMonopatinPorIdMonopatin();
			anykey();
			break;
		case 3:
			consultaMonopatinesPorModelo();
			anykey();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuInformes()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\t\t\t\tInformes" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "    1 - Recaudaci�n anual" << endl;
		cout << "    2 - Recaudaci�n por user" << endl;
		cout << "    3 - Recaudaci�n por administrador" << endl;
		cout << "    4 - Cantidad de monopatines por pais " << endl;
		cout << "    5 - Cantidad de rentas aprobadas por a�o" << endl;
		cout << "    6 - Cantidad de rentas desaprobadas por a�o" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "    7 - Listar historial de precios de renta" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			Informe_Recaudacion_Anual();
			break;
		case 2:
			recaudacionPorUser();
			break;
		case 3:
			recaudacionPorAdmin();
			break;
		case 4:
			cantidad_de_monopatines_por_pais();
			anykey();
			break;
		case 5:
			cantidad_rentas_aprobadas_por_anio();
			anykey();
			break;
		case 6:
			cantidad_rentas_desap_por_anio();
			anykey();
			break;
		case 7:
			listar_historial_precios_renta();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

void menuConfiguracion()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;

	while (!salir) {

		setBackgroundColor(BLACK);
		setColor(CYAN);
		cls();
		cout << "\t\tConfiguraciones" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "               - Precios -              " << endl;
		cout << "    1 - Modificar precio de renta" << endl << endl;
		cout << "               - Archivos -              " << endl;
		cout << "    2 - Hacer copia de seguridad Users" << endl;
		cout << "    3 - Hacer copia de seguridad Rentas" << endl;
		cout << "    4 - Exportar archivo CSV de Users" << endl;
		cout << "    5 - Exportar archivo CSV de Rentas" << endl;
		cout << "    6 - Exportar archivo CSV de Monopatines" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "    0 - Volver al men� principal" << endl << endl;

		cout << "Opci�n: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			modificar_precio_renta();
			break;
		case 2:
			backup_users();
			anykey();
			break;
		case 3:
			backup_rentas();
			anykey();
			break;
		case 4:
			exportarCSVUsers();
			break;
		case 5:
			exportarCSVRentas();
			break;
		case 6:
			exportarCSVMonopatines();
			break;
		case 0:
			cout << "�Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');

			break;
		}
	}
}

bool exportarCSVUsers()
{
	ofstream myFile;
	myFile.open("listadoUsers.csv");

	FILE* p = fopen("users.dat", "rb");

	User reg;

	if (p == NULL) {
		cout << "No se pudo abrir el archivo";
		return false;
	}

	int pos = 0;

	myFile << "ID USER" << ';' << "DNI" << ';' << "APELLIDO" << ';' << "NOMBRE" << ';' << "FECHA INGRESO" << endl;
	
	//Variable para fecha de ingreso
	string fecha2;

	while (reg.leerDeDisco(pos++)) {
		
		fecha2 = reg.getFechaIngreso().toString();

		myFile << reg.getIduser() << ';' << reg.getDni() << ';' << reg.getApellido() << ';' << reg.getNombre() << ';' << fecha2 << endl;
	}

	cout << "Listado 'listadoUsers.csv' exportado correctamente" << endl;
	system("pause");
	system("cls");

	

	return true;
}

bool exportarCSVRentas()
{
	ofstream myFile;
	myFile.open("listadoRentas.csv");

	FILE* p = fopen("rentas.dat", "rb");
	Renta reg;

	if (p == NULL) {
		cout << "No se pudo abrir el archivo";
		return false;
	}
	
	int pos = 0;

	myFile << "ID RENTA" << ';' << "ID ADMIN" << ';' << "ID USER" << ';' << "ID MONOPATIN" << ';' << "FECHA INICIO" <<  endl;

	string fecha;
	string estado;

	while (reg.leerDeDisco(pos++)) {
		fecha = reg.getFechaRenta().toString();

		myFile << reg.getIdRenta() << ';' << reg.getIdAdministrador() << ';' << reg.getIdUser() << ';' << reg.getIdMonopatin() << ';' << fecha << endl;
	}

	cout << "Listado 'listadoRentas.csv' exportado correctamente" << endl;
	system("pause");
	system("cls");


	return true;
}

bool exportarCSVMonopatines()
{
	ofstream myFile;
	myFile.open("listadoMonopatines.csv");

	FILE* p = fopen("monopatines.dat", "rb");
	Monopatin reg;

	if (p == NULL) {
		cout << "No se pudo abrir el archivo";
		return false;
	}

	int pos = 0;

	myFile << "ID MONOPATIN" << ',' << "MODELO" << ',' << "ID PAIS" << ',' << "NUM SERIE" << endl;

	string modelo;


	while (reg.leerDeDisco(pos++)) {

		modelo = reg.getModelo();

		myFile << reg.getIdMonopatin() << ',' << modelo << ',' << reg.getidPaisFabricacion() << ',' << reg.getNumSerie() << endl;
	}

	cout << "Listado 'listadoMonopatines.csv' exportado correctamente" << endl;
	system("pause");
	system("cls");


	fclose(p);

	return true;
}
