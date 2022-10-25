#pragma once
class Fecha 
{
private:
	int _dia;
	int _mes;
	int _anio;
public:
	Fecha();
	Fecha(int, int, int);

	int getDia();
	int getMes();
	int getAnio();

	bool operator>(Fecha aux);

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	void Cargar(int, int, int);
	void Mostrar();


};

