#include "Fecha.h"
#include <iostream>

using namespace std;

/// Constructor
Fecha::Fecha() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	_dia = timeinfo->tm_mday;
	_mes = timeinfo->tm_mon + 1;
	_anio = timeinfo->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio) {
	_dia = dia;
	_mes = mes;
	_anio = anio;
}

void Fecha::setDia(int dia) {
	_dia = dia;
}

void Fecha::setMes(int mes) {
	_mes = mes;
}

void Fecha::setAnio(int anio) {
	_anio = anio;
}

int Fecha::getDia() {
	return	_dia;
}

int Fecha ::getMes() {
	return _mes;
}

int Fecha::getAnio() {
	return _anio;
}

bool Fecha::operator> (Fecha aux)
{
	if (_anio < aux.getAnio())
	{
		return false;
	}

	if (_mes < aux.getMes())
	{
		return false;
	}

	if (_dia < aux.getDia())
	{
		return false;

	}
	else
	{
		return true;
	}
}

void Fecha::Cargar(int, int, int)
{
	cout << "Dia: ";
	cin >> _dia;
	cout << "Mes: ";
	cin >> _mes;
	cout << "Anio: ";
	cin >> _anio;
}

void Fecha::Mostrar()
{
	cout << "Dia: ";
	cout << _dia << endl;
	cout << "Mes: ";
	cout << _mes << endl;
	cout << "Anio: ";
	cout << _anio << endl;
}