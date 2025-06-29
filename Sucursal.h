#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Producto.h"
#include <vector>
#include <string>

class Sucursal {
private:
    std::string nombre;
    std::vector<Producto*> productos;

public:
    Sucursal(const std::string& nombre);
    ~Sucursal(); // liberar memoria de productos

    void agregarProducto(Producto* producto);
    double calcularIngresosTotales() const;
    Producto* productoMasRentable() const;
    void mostrarResumen() const;

    std::string getNombre() const;
};

#endif
