#include "administrador.h"

using namespace std;
using namespace rlutil;

///Constructor
Administrador::Administrador(int id, int dni, const char* apellido, const char* nombre, const char* contrasenia, bool estado)
{
	_idAdministrador = id;
	_dni = dni;
	strcpy(_apellido, apellido);
	strcpy(_nombre, nombre);
	strcpy(_contrasenia, contrasenia);
	_estado = estado;
}

/// Setters
void Administrador::setIdAdmin(int idAdmin)
{
	_idAdministrador = idAdmin;
}

void Administrador::setDNI(int dni)
{
	_dni = dni;
}

void Administrador::setNombre(const char* nombre)
{
	strcpy(_nombre, nombre);
}

void Administrador::setApellido(const char* apellido)
{
	strcpy(_apellido, apellido);
}

void Administrador::setContrasenia(const char* contrasenia)
{
	strcpy(_contrasenia, contrasenia);
}

void Administrador::setEstado(bool estado)
{
	_estado = estado;
}

/// Getters
int Administrador::getIdAdmin()
{
	return _idAdministrador;
}

int Administrador::getDNI()
{
	return _dni;
}

const char* Administrador::getContrasenia()
{
	return _contrasenia;
}

const char* Administrador::getApellido()
{
	return _apellido;
}

const char* Administrador::getNombre()
{
	return _nombre;
}

bool Administrador::getEstado()
{
	return _estado;
}

void Administrador::cargar()
{
}

void Administrador::mostrar()
{
}

void Administrador::listar()
{
}

bool Administrador::grabarEnDisco()
{
	return false;
}

bool Administrador::leerDeDisco(int)
{
	return false;
}

bool Administrador::modificarEnDisco(int pos)
{
	return false;
}

void crear_nuevo_admin()
{
}

void modificar_admin()
{
}

void baja_admin()
{
}

void listado_general_admin()
{
}

int buscarAdministradorPorDni(int)
{
	return 0;
}

int buscarAdministradorPorID(int)
{
	return 0;
}

int buscarCantidadRegistrosAdmin()
{
	return 0;
}

int checkArchivoAdmins()
{
	return 0;
}

void ModificarDNIAdmin(Administrador aux, int pos)
{
}

void ModificarNombreAdmin(Administrador aux, int pos)
{
}

void ModificarApellidoAdmin(Administrador aux, int pos)
{
}

void ModificarContrasenia(Administrador aux, int pos)
{
}

void consulta_admin_Por_ID()
{
}

string pedirContrasenia()
{
	return string();
}
