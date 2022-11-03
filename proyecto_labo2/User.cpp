#include <iomanip>
#include "User.h"
#include "rlutil.h"
#include "funciones.h"
#include "administrador.h"
#include "Renta.h"
#include "Fecha.h"


using namespace rlutil;
using namespace std;

User::User() {

	Persona();
	Fecha _fechaIngreso;
	_iduser = 0;
	_estado = false;
}

void User::setIduser(int idsocio) {
	_iduser = idsocio;
}

void User::setEstado(bool estado) {
	_estado = estado;
}

void User::setFechaIngreso(Fecha fechaIng)
{
	_fechaIngreso = fechaIng;
}

int	 User::getIduser() {
	return _iduser;
}

Fecha User::getFechaIngreso()
{
	return _fechaIngreso;
}

bool User::getEstado() {
	return _estado;
}



//METODOS DE DISCO
bool User::grabarEnDisco() {
	FILE* fReg = fopen("users.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(User), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool User::grabarBackupUsers() {
	FILE* fReg = fopen("backupUsers.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(User), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool User::leerDeDisco(int pos) {
	FILE* fReg = fopen("users.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(User), SEEK_SET);

	int escribio = fread(this, sizeof(User), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool User::leerBackupUsers(int pos)
{
	FILE* fReg = fopen("backupUsers.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(User), SEEK_SET);

	int escribio = fread(this, sizeof(User), 1, fReg);

	fclose(fReg);

	return escribio;
}

bool User::modificarEnDisco(int pos) {
	FILE* fReg = fopen("users.dat", "rb+");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(User), SEEK_SET);

	int escribio = fwrite(this, sizeof(User), 1, fReg);

	fclose(fReg);

	return escribio;
}

//Cargar y Mostrar
void User::cargar() {

	bool flag = false;
	bool flag2 = false;
	int aux = 0;
	int pos = 0;
	int ID = 0;

	Fecha fechaActual;
	Administrador admin;

	srand(time(NULL));

	aux = CargarPersona();

	if (aux == 0)
	{
		return;
	}

	this->setFechaIngreso(fechaActual);

	this->setIduser(generarIDUser() + 1);

	this->setEstado(true);
	
	do
	{
		cout << endl << "Ingrese el ID de administrador actual: ";
		cin >> ID;

		if (ID < 1)
		{
			cout << "ID inválido. Reintente por favor" << endl;
			flag2 = false;
			anykey();
		}
		else
		{

			pos = buscarAdministradorPorID(ID);

			if (pos > -1) {
				admin.leerDeDisco(pos);
				
				/// Agregar la validación
				
			}
			else
			{
				cout << "El ID no fue encontrado en el archivo de administradores" << endl;
				flag2 = false;
				anykey();
			}
		}

	} while (!flag2);

	this->grabarEnDisco();

	cout << endl << " -- User creado correctamente --" << endl << endl;

	this->mostrar();

}

void User::mostrar() {

	cout << "ID de user: " << this->getIduser() << endl;
	cout << "Fecha de ingreso: ";
	_fechaIngreso.mostrarFecha();
	MostrarPersona();
	cout << endl;
}

void User::mostrarSimplificado()
{

	if (this->getEstado())
	{

		cout << left;
		cout << setw(5) << this->getIduser();
		cout << setw(15) << this->getDni();
		cout << setw(20) << this->getApellido();
		cout << setw(20) << this->getNombre();
		cout << setw(20);
		
	}

}

void User::listar() {

	cout << left;
	cout << setw(5) << this->getIduser();
	cout << setw(15) << this->getDni();
	cout << setw(20) << this->getNombre();
	cout << setw(20) << this->getApellido();
	cout << setw(20);


	this->getFechaIngreso().mostrarFecha();
	cout << endl;
}


// Funciones globales User

int generarIDUser()
{
	return CantidadRegistrosUser();
}

int buscarUserPorID(int id)
{
	User user;
	int pos = 0;

	while (user.leerDeDisco(pos))
	{
		if (user.getIduser() == id && user.getEstado())
		{
			return pos;
		}
		pos++;
	}

	return -1;
}

bool buscarUserPorDNI(int dni)
{
	User user;
	int pos = 0;

	while (user.leerDeDisco(pos++))
	{
		if (user.getDni() == dni && user.getEstado())
		{
			return true;
		}
	}

	return false;
}
int checkArchivoUsers() {

	FILE* fReg = fopen("users.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("users.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de users." << endl;
			system("PAUSE > null");
			system("cls");
			return -1;
		}
		else
		{
			fclose(fReg);
			cout << "Archivo de users creado correctamente" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Users: cargado OK" << endl;
	}

	fclose(fReg);

	return 1;

}
void listado_general_users()
{
	User user;
	int pos = 0;

	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRE";
	cout << setw(20) << "APELLIDO";
	cout << setw(20) << "ESTADO DE CUOTA";
	cout << setw(10) << "FECHA INGRESO" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;

	while (user.leerDeDisco(pos++))
	{
		if (user.getEstado())
		{
			user.listar();
		}
	}
}

void cargar_nuevo_user()
{
	User aux;

	aux.cargar();
}

void modificar_user()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;
	bool flag = false;
	int idaux;
	int pos = 0;
	User aux;

	while (!salir) {

		do
		{
			cout << "Ingrese ID de socio a modificar (0 para volver al menu anterior): ";
			cin >> idaux;

			if (idaux == 0)
			{
				return;
			}

			pos = buscarUserPorID(idaux);

			if (pos <= -1)
			{
				cout << "El ID no se encuentra. Reintente por favor.";
				anykey();
				cls();
			}
			else
			{
				flag = true;
			}
		} while (!flag);

		cls();

		aux.leerDeDisco(pos);
		aux.mostrar();
		cout << endl;

		cout << "\tSeleccione campo a modificar" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Modificar DNI " << endl;
		cout << "2 - Modificar nombre " << endl;
		cout << "3 - Modificar apellido " << endl;
		cout << "4 - Modificar fecha de nacimiento" << endl;
		cout << "5 - Modificar domicilio" << endl;
		cout << "6 - Modificar email" << endl;
		cout << "7 - Modificar telefono" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú Socios" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			ModificarDNIUser(aux, pos);
			break;
		case 2:
			ModificarNombreUser(aux, pos);
			break;
		case 3:
			ModificarApellidoUser(aux, pos);
			break;
		case 4:
			ModificarFechaNac(aux, pos);
			break;
		case 5:
			ModificarDomicilio(aux, pos);
			break;
		case 6:
			ModificarEmail(aux, pos);
			break;
		case 7:
			ModificarTelefono(aux, pos);
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void baja_user()
{
	User aux;
	int id;
	bool flag = false;
	int pos = 0;
	char confirm;

	do {
		do {
			cout << "Ingrese ID de user a dar de baja (0 para volver al menu anterior): ";
			cin >> id;

			if (id == 0)
			{
				return;
			}

			pos = buscarUserPorID(id);

			if (pos <= -1 && id != 0)
			{
				cout << "El ID no se encuentra. Reintente por favor.";
				anykey();
				cls();
			}
			else
			{
				flag = true;
			}
		} while (!flag);

		cls();

		aux.leerDeDisco(pos);
		aux.mostrar();
		cout << endl;

		cout << "¿Desea dar de baja el socio  N°" << id << "? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{

			//eliminar_monopatines_user(id);
			//eliminar_rentas_pendientes(id);
			aux.setEstado(false);
			aux.modificarEnDisco(pos);
			cout << endl << " -- El user N° " << aux.getIduser() << "ha sido dado de baja -- " << endl;
			cout << "Todas los rentas pendientes han sido dadas de baja" << endl;
			anykey();
			cls();
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

}


// Funciones globales ModificarUser


void ModificarDNIUser(User aux, int pos)
{
	int newDni;
	bool flag = false;
	char confirm;
	bool confirmar = false;

	do {
		cout << "Ingrese el dni nuevo (0 para volver al menu anterior): ";
		cin >> newDni;

		if (newDni == 0)
		{
			cls();
			return;
		}

		if (newDni < 1000000)
		{
			cout << " El dni ingresado es incorrecto, intente nuevamente." << endl;
			flag = false;
		}
		else
			if (buscarUserPorDNI(newDni))
			{
				cout << "El user ya se encuentra registrado." << endl;
				flag = false;
			}
			else
			{
				cls();
				cout << "Nuevo DNI: " << newDni << endl << endl;
				cout << "¿Confirma los cambios? (S/N): ";
				cin >> confirm;

				confirm = (tolower(confirm));

				if (confirm == 's')
				{
					flag = true;
				}
				else
				{
					cls();
					flag = false;
				}
			}

	} while (!flag);

	aux.setDni(newDni);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}

void ModificarApellidoUser(User aux, int pos)
{
	char newName[30];
	char confirm;
	bool flag = false;

	do
	{
		cout << "Ingrese apellido nuevo: ";
		cin.ignore();
		cin.getline(newName, 29);

		todoAMayus(newName);
		cls();
		cout << "Nuevo apellido: " << newName << endl << endl;

		cout << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

	aux.setApellido(newName);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}
void ModificarNombreUser(User aux, int pos)
{
	char newName[30];
	char confirm;
	bool flag = false;

	do
	{
		cout << "Ingrese nombre nuevo: ";
		cin.ignore();
		cin.getline(newName, 29);
		cls();
		cout << "Nuevo nombre: " << newName << endl << endl;

		cout << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

	aux.setNombre(newName);
	aux.modificarEnDisco(pos);

	cout << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}
void ModificarFechaNac(User aux, int pos)
{
	Fecha nuevaFecha;
	char confirm;
	bool flag = false;

	do {
		nuevaFecha.cargarFecha();
		cls();

		cout << "Nueva fecha: ";
		nuevaFecha.mostrarFecha();

		cout << endl << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);


	aux.setFechanacimiento(nuevaFecha);
	aux.modificarEnDisco(pos);

	cout << endl << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}
void ModificarDomicilio(User aux, int pos)
{
	Domicilio nuevoDomicilio;
	char confirm;
	bool flag = false;
	bool ok = false;

	do {
		nuevoDomicilio.cargarDomicilio();
		cls();

		cout << " -- Nuevo domicilio -- " << endl << endl;
		nuevoDomicilio.mostrarDomicilio();

		cout << endl << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

	aux.setDomicilio(nuevoDomicilio);
	aux.modificarEnDisco(pos);
	cout << endl << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}
void ModificarEmail(User aux, int pos)
{
	char confirm;
	bool flag = false;
	bool ok = false;
	char newMail[30];

	do {
		cout << "Ingrese nuevo E-Mail: ";
		cin.ignore();
		cin.getline(newMail, 29);
		cls();

		cout << "Nuevo E-mail: " << newMail << endl << endl;

		cout << endl << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

	aux.setEmail(newMail);
	aux.modificarEnDisco(pos);
	cout << endl << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}
void ModificarTelefono(User aux, int pos)
{
	char confirm;
	bool flag = false;
	bool ok = false;
	char tel[15];

	do {
		cout << "Ingrese nuevo telefono: ";
		cin.ignore();
		cin.getline(tel, 14);
		cls();

		cout << "Nuevo telefono: " << tel << endl << endl;

		cout << endl << "¿Confirma los cambios? (S/N): ";
		cin >> confirm;

		confirm = (tolower(confirm));

		if (confirm == 's')
		{
			flag = true;
		}
		else
		{
			cls();
			flag = false;
		}
	} while (!flag);

	aux.setTelefono(tel);
	aux.modificarEnDisco(pos);
	cout << endl << " -- Los cambios han sido guardados -- " << endl;
	anykey();
	cls();
}

void listarUserAlfabeticamente() {

	int cantReg = CantidadRegistrosUser();

	if (cantReg == 0) {
		cout << "No hay users registrados";
		anykey();
		return;
	}

	User* vDinamico;
	vDinamico = new User[cantReg];
	if (vDinamico == NULL) return;

	copiarUsers(vDinamico, cantReg);
	ordenarVector(vDinamico, cantReg);
	MostrarVector(vDinamico, cantReg);

	delete vDinamico;

}
void ordenarVector(User* vec, int tam) {
	User aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(vec[i].getApellido(), vec[j].getApellido()) > 0) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
void copiarUsers(User* vec, int tam)
{
	for (int i = 0; i < tam; i++) {
		vec[i].leerDeDisco(i);
	}
}
int CantidadRegistrosUser()
{
	FILE* p = fopen("users.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(User);
	return cant_reg;
}
void MostrarVector(User* vec, int tam) {


	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "APELLIDO";
	cout << setw(20) << "NOMBRE";
	cout << setw(20) << "ESTADO DE CUOTA";
	cout << setw(20) << "FECHA ULTIMO PAGO";
	cout << setw(10) << "FECHA INGRESO" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < tam; i++)
	{
		vec[i].mostrarSimplificado();
	}

}

void listarUserPorFecha() {
	int cantReg = CantidadRegistrosUser();

	if (cantReg == 0) {
		cout << "No hay socios registrados";
		anykey();
		return;
	}

	User* vDinamico;
	vDinamico = new User[cantReg];
	if (vDinamico == NULL) return;


	copiarUsers(vDinamico, cantReg);
	ordenarVectorPorFecha(vDinamico, cantReg);
	MostrarVector(vDinamico, cantReg);

	delete vDinamico;

}
void ordenarVectorPorFecha(User* vec, int tam) {
	User aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vec[j].getFechaIngreso() > vec[i].getFechaIngreso()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

void listadoSolicitudesPendientesPorUser()
{
	int ID = 0;
	int pos = 0;
	bool flag = false;
	User user;
	Renta renta;

	do {

		cls();
		cout << "Ingrese el ID de user a consultar (0 para volver al menu anterior): ";
		cin >> ID;


		if (ID == 0)
		{
			return;
		}

		if (ID < 1)
		{
			cout << endl << "ID invalido. Reintente por favor." << endl;
			flag = false;
			anykey();
		}
		else
		{
			pos = BuscarIdArchivo(ID);

			if (pos < 0)
			{
				cout << endl << "El ID no fue encontrado en el archivo de users" << endl;
				flag = false;
				anykey();
			}

			else
			{
				flag = true;
			}
		}
	} while (!flag);

	//SolicitudesPendientesPorUser(ID);

}

void consulta_Por_Id() {

	int ID = 0;
	int pos = 0;
	bool flag = false;
	User user;

	do {

		cls();
		cout << "Ingrese el ID a consultar (0 para volver al menu anterior): ";
		cin >> ID;


		if (ID == 0)
		{
			return;
		}

		if (ID < 1)
		{
			cout << endl << "ID invalido. Reintente por favor." << endl;
			flag = false;
			anykey();
		}
		else
		{
			pos = BuscarIdArchivo(ID);

			if (pos < 0)
			{
				cout << endl << "El ID no fue encontrado en el archivo de users" << endl;
				flag = false;
				anykey();
			}

			else
			{
				flag = true;
			}
		}
	} while (!flag);

	if (pos > -1) {
		user.leerDeDisco(pos);
		cout << endl;
		user.mostrar();
		anykey();
	}
	else {
		cout << "El ID no fue encontrado en el archivo de users" << endl;
	}
}
int BuscarIdArchivo(int Id) {
	User reg;
	int pos = 0;
	while (reg.leerDeDisco(pos))
	{
		if (reg.getIduser() == Id && reg.getEstado())return pos;
		pos++;
	}
	return -1;
}

void consultaPorDni() {

	int dniConsulta;
	int pos = 0;
	User user;
	bool flag = false;

	do {

		cls();
		cout << "Ingrese el dni a consultar (0 para volver al menu anterior): ";
		cin >> dniConsulta;


		if (dniConsulta == 0)
		{
			return;
		}

		if (dniConsulta < 1)
		{
			cout << endl << "DNI invalido. Reintente por favor." << endl;
			flag = false;
			anykey();
		}
		else
		{
			pos = BuscarDniArchivo(dniConsulta);

			if (pos <= -1)
			{
				cout << endl << "El dni no fue encontrado en el archivo de user" << endl;
				flag = false;
				anykey();
			}

			else
			{
				flag = true;
			}
		}
	} while (!flag);

	user.leerDeDisco(pos);
	cout << endl;
	user.mostrar();
	anykey();

}

int BuscarDniArchivo(int dniconsulta)
{
	User reg;
	int pos = 0;
	while (reg.leerDeDisco(pos))
	{
		if (reg.getDni() == dniconsulta)return pos;
		pos++;
	}
	return -1;
}

void consulta_Por_Apellido() {

	char apellidoConsulta[30];
	int pos = 0;
	User socio;
	cout << "Ingrese el apellido: ";
	cin.ignore();
	cin.getline(apellidoConsulta, 29);

	todoAMayus(apellidoConsulta);

	pos = BuscarApellidoArchivo(apellidoConsulta);

	if (pos == -1) {
		cout << "El apellido " << apellidoConsulta << " no existe en el archivo." << endl;
		anykey();
	}

}
int BuscarApellidoArchivo(const char* apellidoconsulta) {
	User reg;
	int pos = 0;
	bool flag = false;

	while (reg.leerDeDisco(pos))
	{
		if (strcmp(apellidoconsulta, reg.getApellido()) == 0 && reg.getEstado())
		{
			flag = true;
			reg.leerDeDisco(pos);
			reg.mostrar();
			anykey();
			cout << endl;
		};
		pos++;
	}

	if (!flag)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void backup_users()
{
	User aux;
	int pos = 0;

	while (aux.leerDeDisco(pos++))
	{
		aux.grabarBackupUsers();
	}

	cout << "Archivo de backup de socios 'backupUsers.dat' grabado correctamente" << endl;
}

