#pragma once
#include "Monopatin.h"
#include "Fecha.h"
class Renta
{
private:
	int _idRenta;
	int _idAdmin;
	int _idUser;
	Monopatin _monopatinAusar;
	Fecha _fechaRenta;
public:
	Renta();

	void setIdRenta(int idRenta);
	void setIdAdmin(int idAdmin);
	void setIdUser(int idUser);
	void setMonopatinAusar(Monopatin monopatinAusar);
	void setFechaRenta(Fecha fechaRenta);

	int getIdRenta();
	int getIdAdmin();
	int getIdUser();
	Monopatin getMonopatinAusar();
	Fecha getFechaRenta();

	void Cargar();
	void Mostrar();

	bool GrabarEnDisco();
	bool LeerDeDisco(int);
};

