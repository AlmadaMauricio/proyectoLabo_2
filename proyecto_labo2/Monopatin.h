#pragma once
class Monopatin {
private:
	int  _idMonopatin;
	char _modelo[30];
	int  _idPaisFabricacion;
	int  _numSerie;
	bool _estado;
public:
	Monopatin();
	void setId(int id);
	void setModelo(char* modelo);
	void setPais(int idPais);
	void setNSerie(int numSerie);
	void setEstado(bool estado);
	int  getIdMonopatin();
	char* getModelo();
	int  getIdPais();
	int  getNumSerie();
	bool getEstado();
	void Cargar();
	void Mostrar();
	bool GrabarEnDisco();
	bool LeerDeDisco(int);
};


