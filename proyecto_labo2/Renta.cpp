#include "Renta.h"
#include <iostream>
using namespace std;

Renta::Renta()
{
	_idRenta = 0;
	_idAdmin = 0;
	_idUser = 0;
	Monopatin _monopatinAusar;
	Fecha _fechaRenta;
}

void Renta::setIdRenta(int idRenta)
{
	_idRenta = idRenta;
}

void Renta::setIdAdmin(int idAdmin)
{
	_idAdmin = idAdmin;
}


void Renta::setIdUser(int idUser)
{
	_idUser = idUser;
}

void Renta::setMonopatinAusar(Monopatin monopatinAusar)
{
	_monopatinAusar = monopatinAusar;
}

void Renta::setFechaRenta(Fecha fechaRenta)
{
	_fechaRenta = fechaRenta;
}

int Renta::getIdRenta()
{
	return _idRenta;
}

int Renta::getIdAdmin()
{
	return _idAdmin;
}

int Renta::getIdUser()
{
	return _idUser;
}

Monopatin Renta::getMonopatinAusar()
{
	return _monopatinAusar;
}

Fecha Renta::getFechaRenta()
{
	return _fechaRenta;
}

void Renta::Cargar()
{
	int dia = 0, mes = 0, anio = 0;

	cout << "---Carga de Renta---" << endl;
	cout << "Id de Renta: ";
	cin >> _idRenta;
	cout << "Id de Admin: ";
	cin >> _idAdmin;
	cout << "Id de User: ";
	cin >> _idUser;
	cout << "Monopatin a utilizar: ";
	_monopatinAusar.Cargar();
	cout << "Fecha de Renta: ";
	_fechaRenta.cargarFecha();
}

void Renta::Mostrar()
{
	cout << "---Carga de Renta---" << endl;
	cout << "Id de Renta: " << _idRenta << endl;
	cout << "Id de Admin: " << _idAdmin << endl;
	cout << "Id de User: " << _idUser << endl;
	cout << "Monopatin a utilizar: ";
	_monopatinAusar.Mostrar();
	cout << "Fecha de Renta: ";
	_fechaRenta.mostrarFecha();
}

bool Renta::GrabarEnDisco()
{
	FILE* pRenta = fopen("renta.dat", "ab");

	if (pRenta == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("pause");
		return false;
	}

	int escribio = fwrite(this, sizeof(Renta), 1, pRenta);

	fclose(pRenta);

	return escribio;
}

bool Renta::LeerDeDisco(int pos)
{
	int escribio;

	FILE* pRenta = fopen("renta.dat", "rb+");

	if (pRenta == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("pause");
		return false;
	}

	fseek(pRenta, pos * sizeof(Renta), SEEK_SET);

	escribio = fwrite(this, sizeof(Renta), 1, pRenta);

	fclose(pRenta);

	return escribio;

}
