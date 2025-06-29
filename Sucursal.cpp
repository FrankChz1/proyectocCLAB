#include "Sucursal.h"
#include <iostream>

Sucursal::Sucursal(const std::string& nombre) : nombre(nombre) {}

Sucursal::~Sucursal() {
    for (Producto* p : productos) {
        delete p;
    }
}

void Sucursal::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

double Sucursal::calcularIngresosTotales() const {
    double total = 0;
    for (Producto* p : productos) {
        total += p->ingresosGenerados();
    }
    return total;
}

Producto* Sucursal::productoMasRentable() const {
    if (productos.empty()) return nullptr;

    Producto* mejor = productos[0];
    for (Producto* p : productos) {
        if (p->ingresosGenerados() > mejor->ingresosGenerados()) {
            mejor = p;
        }
    }
    return mejor;
}

void Sucursal::mostrarResumen() const {
    std::cout << "\nSucursal: " << nombre << "\n";
    std::cout << "----------------------------------\n";
    for (Producto* p : productos) {
        std::cout << "Producto: " << p->getNombre()
                  << " | Cant. Vendida: " << p->totalVendido()
                  << " | Ingreso: S/ " << p->ingresosGenerados()
                  << " | Evaluacion: " << p->Desempeno() << "\n";
    }

    std::cout << "Ingreso total: S/ " << calcularIngresosTotales() << "\n";

    Producto* rentable = productoMasRentable();
    if (rentable != nullptr) {
        std::cout << "Producto mas rentable: " << rentable->getNombre() << "\n";
    }
}

std::string Sucursal::getNombre() const { return nombre; }
