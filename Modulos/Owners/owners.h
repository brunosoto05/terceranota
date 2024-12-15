#ifndef OWN_H
#define OWN_H

#include <string>
using namespace std;

class Owner {
private:
    string cedula, nombre, apellido, direccion, perros;

public:
Owner() : cedula(""), nombre(""), apellido(""), direccion(""), perros("") {}

  //getter
    string getCedula() const {return cedula; }
    string getNombre() const { return nombre; }
    string getApell() const { return apellido; }
    string getDireccion() const { return direccion; }
    string getPerros() const {return perros; }

  //setters
    void setCedula(const string& c) {cedula = c; }
    void setNombre(const string& n) { nombre = n; }
    void setApell(const string& a) { apellido = a; }
    void setAddr(const string& Ad) { direccion = Ad; }
    void setPerros(const string& p) {perros = p; }

    static Owner* cargarOwn(int& cantidad);
    static void guardarOwn(Owner* owners, int cantidad);

    static void agregarOwn(Owner*& owners, int& cantidad, const Owner& nuevoOwn);
    static void borrarOwn(Owner*& owners, int& cantidad, const string& cedula);
    static void UpdateOwn(Owner* owners, int cantidad, const string& cedula);
    static void leerOwn(Owner* owners, int cantidad);
};

#endif