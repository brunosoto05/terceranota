#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class Pet {
private:
    string nombre;
    string raza;
    string nombreOwn;

public:
Pet() : nombre(""), raza(""), nombreOwn("") {}

    string getNombre() const { return nombre; }
    string getRaza() const { return raza; }
    string getnombreOwn() const { return nombreOwn; }

    void setNombre(const string& n) { nombre = n; }
    void setraza(const string& r) { raza = r; }
    void setnombreOwn(const string& nO) { nombreOwn = nO; }

    static Pet* cargarPets(int& cantidad);
    static void guardarPet(Pet* pets, int cantidad);

    static void agregarPet(Pet*& pets, int& cantidad, const Pet& nuevoPet);
    static void borrarPet(Pet*& pets, int& cantidad, const string& nombre, const string& nombreOwn);
    static void UpdatePet(Pet* pets, int cantidad, const string& nombre, const string& nombreOwn);
    static void leerPets(Pet* pets, int cantidad);
};

#endif
