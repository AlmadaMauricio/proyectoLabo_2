#include "Monopatin.h"

using namespace std;
using namespace rlutil;

Monopatin::Monopatin(int idMonopatin, const char* modelo, int numSerie, bool estado, int _idPais, int idUser) {
	_idMonopatin = idMonopatin;
	strcpy(_modelo, modelo);
	_idPaisFabricacion = _idPais;
	_numSerie = numSerie;
	_idUser = idUser;
	_estado = estado;
};

void Monopatin::setIdMonopatin(int idMonopatin) {
	_idMonopatin = idMonopatin;
};
void Monopatin::setIdUser(int idUser) {
	_idUser = idUser;
};


void Monopatin::setModelo(const char* modelo) {
	strcpy(_modelo, modelo);
};

void Monopatin::setidPaisFabricacion(int idPaisFabricacion) {
	_idPaisFabricacion = idPaisFabricacion;
};

void Monopatin::setNumSerie(int numSerie) {
	_numSerie = numSerie;
};

void Monopatin::setEstado(bool estado) {
	_estado = estado;
};

int Monopatin::getIdMonopatin() {
	return _idMonopatin;
};
int Monopatin::getIdUser() {
	return _idUser;
};

const char* Monopatin::getModelo() {
	return _modelo;
};

int Monopatin::getidPaisFabricacion() {
	return _idPaisFabricacion;
};

int Monopatin::getNumSerie() {
	return _numSerie;
};

bool Monopatin::getEstado() {
	return _estado;
}
void Monopatin::cargarMonopatin()
{
	int aux;
	char aux2[30];
	bool flag = false;
	int pos = 0;

	cout << "Ingrese el Modelo del Monopatin: ";

	cin >> aux2;
	this->setModelo(aux2);

	//cin.ignore();
	//cin.getline(_modelo, 29);

	// Usar metodo set para ingreso	automatizado con 
	// excel o getline para ingreso manual (comentar uno y descomentar el otro)


	do {
		cout << "1 - Argentina" << endl;
		cout << "2 - Brasil" << endl;
		cout << "3 - USA" << endl;
		cout << "4 - Rusia" << endl;
		cout << "5 - Alemania" << endl;

		cout << "Ingrese el Pais de Fabricacion: ";
		cin >> aux;

		if (aux < 1 || aux > 5)
		{
			cout << "ID de pais incorrecto." << endl;
			flag = false;
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	this->setidPaisFabricacion(aux);


	do {
		cout << "Ingrese número de serie: ";
		cin >> aux;

		if (aux < 1)
		{
			cout << "Número de serie inválido." << endl;
			flag = false;
		}
		else
		{
			pos = buscarMonopatinPorNumSerie(aux);

			if (pos != -1)
			{
				cout << "El número de serie ya ha sido registrado";
				anykey();
				cls();
				flag = false;
			}
			else
			{
				flag = true;
			}
		}

	} while (!flag);

	this->setNumSerie(aux);

	this->setIdMonopatin(generarIdMonopatin() + 1);

	this->setEstado(true);

	cout << endl << "-- Monopatin agregado con exito. --" << endl << endl;

	this->mostrarMonopatin();

}
void Monopatin::mostrarMonopatin()
{
	cout << "Id del Monopatin: " << this->getIdMonopatin();
	cout << endl;
	cout << "Modelo del Monopatin: " << this->getModelo();
	cout << endl;
	cout << "Pais de Fabricacion: ";
	mostrarPais(this->getidPaisFabricacion());
	cout << endl;
	cout << "Numero de Serie: " << this->getNumSerie();
	cout << endl;
}
void Monopatin::listar()
{
	cout << left;
	cout << setw(5) << this->getIdMonopatin();
	cout << setw(18) << this->getModelo();
	cout << setw(15);
	mostrarPais(this->getidPaisFabricacion());
	cout << setw(18);
	cout << setw(15) << this->getNumSerie();
	cout << endl;
}
void Monopatin::listarPorNumSerie()
{
	if (this->getEstado())
	{
		cout << left;
		cout << setw(18) << this->getNumSerie();
		cout << setw(9) << this->getIdMonopatin();
		cout << setw(18) << this->getModelo();
		cout << setw(15);
		mostrarPais(this->getidPaisFabricacion());
		cout << setw(20);
		cout << endl;
	}
}
void Monopatin::listarPorIdMonopatin()
{
	if (this->getEstado())
	{
		cout << left;
		cout << setw(9) << this->getIdMonopatin();
		cout << setw(18) << this->getNumSerie();
		cout << setw(18) << this->getModelo();
		cout << setw(15);
		mostrarPais(this->getidPaisFabricacion());
		cout << setw(18);
		cout << endl;
	}
}

int buscarMonopatinPorNumSerie(int id)
{
	Monopatin monopatin;
	int pos = 0;

	while (monopatin.leerDeDisco(pos))
	{
		if (monopatin.getNumSerie() == id && monopatin.getEstado())
		{
			return pos;
		}
		pos++;
	}

	return -1;
}

int generarIdMonopatin()
{
	Monopatin monopatin;
	int id = 0;
	int pos = 0;

	while (monopatin.leerDeDisco(pos++)) {
		id = monopatin.getIdMonopatin();
	};

	return id;
}

int checkArchivoMonopatin()
{
	FILE* rentReg = fopen("monopatines.dat", "rb");

	if (rentReg == NULL)
	{
		rentReg = fopen("monopatines.dat", "wb");

		if (rentReg == NULL)
		{
			cout << "Error al crear o leer archivo de monopatines." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(rentReg);
			cout << "Archivo de monopatines creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Monopatin: cargado OK" << endl;
	}

	fclose(rentReg);
	return 1;
}

int buscarMonopatinPorId(int id)
{
	Monopatin monopatin;
	int pos = 0;
	while (monopatin.leerDeDisco(pos))
	{
		if (monopatin.getIdMonopatin() == id && monopatin.getEstado())
		{
			return pos;
		}
		pos++;
	}

	return -1;
}

void crear_nuevo_monopatin()
{
	Monopatin monopatin;

	monopatin.cargarMonopatin();
	monopatin.grabarEnDisco();
}

void eliminarMonopatin(int idMonopatin)
{
	Monopatin reg;
	int pos = buscarMonopatinPorId(idMonopatin);
	if (pos > -1) {
		reg.leerDeDisco(pos);
		reg.setEstado(false);
		reg.modificarEnDisco(pos);
	}
}

void modificar_monopatin()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;
	bool flag = false;
	int idaux;
	int pos = 0;
	Monopatin aux;

	while (!salir) {

		do
		{
			cout << "Ingrese ID de monopatin a modificar (0 para volver al menu anterior): ";
			cin >> idaux;

			if (idaux == 0)
			{
				return;
			}

			pos = buscarMonopatinPorId(idaux);

			if (idaux < 0)
			{
				cout << "ID inválido. Reintente por favor." << endl << endl;
				anykey();
				cls();
				flag = false;
			}
			else
				if (pos < 0)
				{
					cout << "El ID no se encuentra. Reintente por favor." << endl << endl;
					anykey();
					cls();
					flag = false;
				}
				else
				{
					flag = true;
				}

		} while (!flag);

		cls();

		aux.leerDeDisco(pos);
		aux.mostrarMonopatin();

		cout << "--------------------------------" << endl;
		cout << "  Seleccione campo a modificar" << endl;
		cout << "--------------------------------" << endl;
		cout << "1 - Modificar modelo " << endl;
		cout << "2 - Modificar pais de fabricación " << endl;
		cout << "3 - Modificar número de serie" << endl;
		cout << "--------------------------------" << endl;
		cout << "0 - Volver al menú Monopatines" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			ModificarModelo(aux, pos);
			break;

		case 2:
			ModificarPais(aux, pos);
			break;
		case 3:
			ModificarNumSerie(aux, pos);
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void ModificarModelo(Monopatin aux, int pos)
{
	bool flag = false;
	bool confirmar = false;
	char newModel[30];

	cout << "Ingrese modelo nuevo: ";
	cin.ignore();
	cin.getline(newModel, 29);
	aux.setModelo(newModel);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;

	anykey();
	cls();
}

void ModificarPais(Monopatin aux, int pos)
{
	bool flag = false;
	bool confirmar = false;
	int newPais;

	do {

		cout << "Ingrese nuevo ID de Pais: ";
		cin >> newPais;

		if (newPais <= 0)
		{
			cout << endl << "Pais inválido. Reingrese de nuevo por favor";
			anykey();
			cls();
			flag = false;
		}
		else
		{
			flag = true;
		}
	} while (!flag);

	aux.setidPaisFabricacion(newPais);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;

	anykey();
	cls();
}

void ModificarNumSerie(Monopatin aux, int pos)
{
	bool flag = false;
	bool confirmar = false;
	int newNum;

	do {

		cout << "Ingrese nuevo número de serie: ";
		cin >> newNum;

		if (newNum <= 0)
		{
			cout << endl << "Número de serie inválido. Reingrese de nuevo por favor";
			anykey();
			cls();
			flag = false;
		}
		else if (buscarMonopatinPorId(newNum) != -1)
		{
			cout << endl << "El número de serie ingresado ya existe.";
			anykey();
			cls();
			flag = false;
		}
		else
		{
			flag = true;
		}
	} while (!flag);

	aux.setNumSerie(newNum);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;

	anykey();
	cls();
}

void listadoGeneralMonopatines()
{
	Monopatin monopatin;
	int pos = 0;

	cout << left;
	cout << setw(5) << "ID";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR.";
	cout << setw(16) << "NÚMERO DE SERIE" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	while (monopatin.leerDeDisco(pos++))
	{
		if (monopatin.getEstado())
		{
			monopatin.listar();
		}
	}
}

int buscarCantidadMonopatines()
{
	FILE* p = fopen("monopatines.dat", "rb");

	if (p == NULL) { return 0; }

	fseek(p, 0, SEEK_END);
	size_t bytes = ftell(p);
	fclose(p);

	unsigned int cantidadMonopatines = bytes / sizeof Monopatin;
	return cantidadMonopatines;
}
void listadoDeMonopatinesPorNumDeSerie()
{
	int cantRegMonopatines = buscarCantidadMonopatines();

	if (cantRegMonopatines == 0) {
		cout << "No existen Monopatines registrados." << endl;
		return;
	}

	Monopatin* monopatin = new Monopatin[cantRegMonopatines];

	if (monopatin == NULL) { return; }

	copiarMonopatines(monopatin, cantRegMonopatines);
	ordernarVecPorNumSerie(monopatin, cantRegMonopatines);
	mostrarListadoMonopatines(monopatin, cantRegMonopatines);

	delete[]monopatin;
}
void copiarMonopatines(Monopatin* vMonopatin, int tam) {
	for (int i = 0; i < tam; i++)
	{
		vMonopatin[i].leerDeDisco(i);
	}
}

void ordernarVecPorNumSerie(Monopatin* vMonopatin, int tam)
{
	Monopatin aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vMonopatin[i].getNumSerie() > vMonopatin[j].getNumSerie()) {
				aux = vMonopatin[i];
				vMonopatin[i] = vMonopatin[j];
				vMonopatin[j] = aux;
			}
		}
	}
}

void mostrarListadoMonopatines(Monopatin* vMonopatin, int tam)
{
	cout << left;
	cout << setw(15) << "NÚM DE SERIE";
	cout << setw(9) << "ID MONOPATIN";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR." << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {
		vMonopatin[i].listarPorNumSerie();
	}
}

int CantidadRegistroMonopatines()
{
	FILE* p = fopen("monopatines.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	int bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Monopatin);
	return cant_reg;
}

void ordenarVector(Monopatin* vec, int tam)
{
	Monopatin aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vec[i].getModelo() > vec[j].getModelo()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

void MostrarVector(Monopatin* vec, int tam)
{
	cout << left;
	cout << setw(9) << "ID MONOPATIN";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR.";
	cout << setw(18) << "NÚMERO DE SERIE" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++)
	{
		vec[i].listarPorIdMonopatin();
	}

}

void consultaMonopatinPorNumSerie()
{
	int cantMonopatines = buscarCantidadMonopatines();
	int numSerie;

	if (cantMonopatines == 0) {
		cout << "No se encontraron Registros de Monopatines cargados.";
		return;
	}

	Monopatin* vecMonopatines = new Monopatin[cantMonopatines];

	if (vecMonopatines == NULL) { return; }

	copiarMonopatines(vecMonopatines, cantMonopatines);

	cout << "Ingrese el Numero de Serie: ";
	cin >> numSerie;

	mostrarConsultaMonopatinPorNumSerie(vecMonopatines, cantMonopatines, numSerie);
}

void mostrarConsultaMonopatinPorNumSerie(Monopatin* vecMonopatin, int tamVec, int numSerie)
{
	cls();

	cout << " -- CONSULTAS DE MONOPATINES POR NUMERO DE SERIE --" << endl;

	cout << left;
	cout << setw(18) << "NÚMERO DE SERIE";
	cout << setw(9) << "ID MONOPATIN";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR." << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < tamVec; i++) {
		if (vecMonopatin[i].getNumSerie() == numSerie) {
			vecMonopatin[i].listarPorNumSerie();
		}
	}
}

void consultaMonopatinPorIdMonopatin()
{
	int cantMonopatines = buscarCantidadMonopatines();
	int numID;

	if (cantMonopatines == 0) {
		cout << "No se encontraron Registros de Monopatines cargados.";
		return;
	}

	Monopatin* vecMonopatines = new Monopatin[cantMonopatines];

	if (vecMonopatines == NULL) { return; }

	copiarMonopatines(vecMonopatines, cantMonopatines);

	cout << "Ingrese el Numero de ID: ";
	cin >> numID;

	mostrarConsultaMonopatinPorId(vecMonopatines, cantMonopatines, numID);
}

void mostrarConsultaMonopatinPorId(Monopatin* vecMonopatin, int tamVec, int numId)
{
	cls();

	cout << " -- CONSULTAS DE MONOPATINES POR NUMERO DE SERIE --" << endl;

	cout << left;
	cout << setw(9) << "ID MONOPATIN";
	cout << setw(18) << "NÚMERO DE SERIE";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR." << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < tamVec; i++) {
		if (vecMonopatin[i].getIdMonopatin() == numId) {
			vecMonopatin[i].listarPorIdMonopatin();
		}
	}
}

void consultaMonopatinesPorModelo()
{
	Monopatin monopatin;
	int pos = 0;
	char modeloABuscar[30];
	char modeloArchivo[30];

	cout << "Ingrese el modelo a buscar: ";
	cin.ignore();
	cin.getline(modeloABuscar, 29);

	todoAMayus(modeloABuscar);

	cout << left;
	cout << setw(5) << "ID";
	cout << setw(18) << "MODELO";
	cout << setw(15) << "PAIS FABR.";
	cout << setw(15) << "NÚMERO DE SERIE" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	while (monopatin.leerDeDisco(pos++))
	{
		strcpy(modeloArchivo, monopatin.getModelo());
		todoAMayus(modeloArchivo);

		if (monopatin.getEstado() && strcmp(modeloABuscar, modeloArchivo) == 0)
		{
			monopatin.listar();
		}
	}
}

void eliminar_monopatin(int id)
{
	Monopatin monopatin;
	int pos = 0;

	while (monopatin.leerDeDisco(pos))
	{
		if (monopatin.getIdMonopatin() == id)
		{
			monopatin.setEstado(false);
			monopatin.modificarEnDisco(pos);
		}
		pos++;
	}
}


bool Monopatin::leerDeDisco(int pos)
{
	FILE* fReg = fopen("monopatines.dat", "rb");
	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	fseek(fReg, pos * sizeof(Monopatin), SEEK_SET);

	int escribio = fread(this, sizeof(Monopatin), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Monopatin::grabarEnDisco()
{
	FILE* fReg = fopen("monopatines.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Monopatin), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool Monopatin::modificarEnDisco(int pos)
{
	FILE* monopReg = fopen("monopatines.dat", "rb+");

	if (monopReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	fseek(monopReg, pos * sizeof(Monopatin), SEEK_SET);
	int escribio = fwrite(this, sizeof(Monopatin), 1, monopReg);
	fclose(monopReg);

	return escribio;
}
