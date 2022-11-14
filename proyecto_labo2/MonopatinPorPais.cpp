#include "MonopatinPorPais.h"

MonopatinPorPais::MonopatinPorPais()
{
	_idPais = 0;
	_cantidadMonopatines = 0;
}

void MonopatinPorPais::setIdPais(int idPais)
{
	_idPais = idPais;
}

void MonopatinPorPais::setCantidadMonopatines(int cant)
{
	_cantidadMonopatines = cant;
}

void MonopatinPorPais::setEstado(bool e)
{
	_estado = e;
}

int MonopatinPorPais::getIdPais()
{
	return _idPais;
}

int MonopatinPorPais::getCantidadMonopatines()
{
	return _cantidadMonopatines;
}

bool MonopatinPorPais::getEstado()
{
	return _estado;
}

int cantidadRegPaises()
{
	FILE* p = fopen("paises.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Pais);
	return cant_reg;
}

void cantidad_de_monopatines_por_pais()
{
	int cantRegMonopatines = CantidadRegistroMonopatines();
	if (cantRegMonopatines == 0)
	{
		cout << "No se registraron monopatines al dia de la fecha.";
		return;
	}

	int cantRegPaises = cantidadRegPaises();
	if (cantRegPaises == 0)
	{
		cout << "No se registraron paises al dia de la fecha.";
		return;
	}

	const int PAISES = 5;
	MonopatinPorPais* vPaises = new MonopatinPorPais[cantRegPaises];

	inicializarVecPaises(vPaises, cantRegPaises);
	ordenarVectorPaises(vPaises, cantRegPaises);
	buscarMonopatinPorPais(vPaises, cantRegPaises);
	ordenarVectorPaises(vPaises, cantRegPaises);
	MostrarVectorPaises(vPaises, cantRegPaises);

	delete vPaises;

}

void inicializarVecPaises(MonopatinPorPais* vPaises, int cantReg)
{
	Pais pais;

	for (int i = 0; i < cantReg; i++) {
		pais.leerDeDisco(i);

		vPaises[i].setIdPais(pais.getIdPais());
		vPaises[i].setEstado(pais.getEstado());
	}
}

void buscarMonopatinPorPais(MonopatinPorPais* vPaises, int cantReg)
{
	int pos = 0;
	int posPais = 0;

	Monopatin monopatin;

	while (monopatin.leerDeDisco(pos))
	{
		posPais = buscarPosPais(monopatin.getidPaisFabricacion(), vPaises, cantReg);
		vPaises[posPais].setCantidadMonopatines(vPaises[posPais].getCantidadMonopatines() + 1);
		pos++;
	}
}

int buscarPosPais(int idPais, MonopatinPorPais* vPaises, int cantReg)
{
	for (int pos = 0; pos < cantReg; pos++) {
		if (vPaises[pos].getIdPais() == idPais) {
			return pos;
		}
	}
	return -1;
}

void ordenarVectorPaises(MonopatinPorPais* vPaises, int cantReg)
{
	MonopatinPorPais aux;

	for (int i = 0; i < cantReg - 1; i++) {
		for (int j = i + 1; j < cantReg; j++) {
			if (vPaises[i].getCantidadMonopatines() < vPaises[j].getCantidadMonopatines()) {

				aux = vPaises[i];
				vPaises[i] = vPaises[j];
				vPaises[j] = aux;
			}
		}
	}
}

void MostrarVectorPaises(MonopatinPorPais* vPaises, int cantReg)
{
	cout << left;
	cout << setw(17) << "PAIS";
	cout << setw(10) << "CANTIDAD" << endl;
	cout << "--------------------------------" << endl;

	for (int i = 0; i < cantReg; i++)
	{
		if (vPaises[i].getEstado())
		{
			cout << setw(15);
			mostrarPais(vPaises[i].getIdPais());
			cout << setw(10) << vPaises[i].getCantidadMonopatines() << endl;
		}
	}
}