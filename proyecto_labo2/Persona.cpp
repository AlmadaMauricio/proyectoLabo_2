#include "Persona.h"

using namespace std;

Persona::Persona() {

	_dni = 0;
	strcpy(_nombre, " ");
	strcpy(_apellido, " ");
	Fecha _fecha_nacimiento;
	Domicilio _domicilio;
	strcpy(_email, " ");
	strcpy(_telefono, " ");
	_estado = true;
}

//SETTER
void Persona::setDni(int dni) { _dni = dni; }
void Persona::setNombre(char* nombre) { strcpy(_nombre, nombre); }
void Persona::setApellido(char* apelldo) { strcpy(_apellido, apelldo); }
void Persona::setFechanacimiento(Fecha fecha_nacimiento) { _fecha_nacimiento = fecha_nacimiento; }
void Persona::setDomicilio(Domicilio domicilio) { _domicilio = domicilio; }
void Persona::setEmail(char* email) { strcpy(_email, email); }
void Persona::setTelefono(char* telefono) { strcpy(_telefono, telefono); }
void Persona::setEstado(bool estado) { _estado = estado; }

//GETTER
int  Persona::getDni() { return _dni; }
const char* Persona::getNombre() { return _nombre; }
const char* Persona::getApellido() { return _apellido; }
Fecha Persona::getFechaNacimiento() { return _fecha_nacimiento; }
Domicilio Persona::getDomicilio() { return _domicilio; }
const char* Persona::getEmail() { return _email; }
const char* Persona::getTelefono() { return _telefono; }
bool Persona::getEstado() { return _estado; }

int Persona::CargarPersona()
{
	return 0;
}

void Persona::MostrarPersona()
{
}

