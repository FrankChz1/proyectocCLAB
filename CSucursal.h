#ifndef CSUCURSALES_H
#define CSUCURSALES_H

// 1. Incluir las cabeceras necesarias
#include <vector>
#include <string>
#include "CProducto.h" // 2. Incluir la definición de la clase CProducto

// Es una buena práctica usar el espacio de nombres std
using std::vector;
using std::string;
// O bien, usar std::vector y std::string directamente en el código.

class CSurcursales {
private:
    vector<CProducto> productos;
    string nombreSurcursal;

public:
    // Constructor por defecto
    CSurcursales() : nombreSurcursal("") {}

    // ¡A esta clase le falta funcionalidad! (Ver sección 2)
};

#endif //CSUCURSALES_H