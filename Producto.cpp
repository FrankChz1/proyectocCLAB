#include "Producto.h"

Producto::Producto(const std::string& nombre, int stock, double precio)
    : nombre(nombre), stockinicial(stock), precio(precio), cantidadvendida(0) {}

void Producto::registrarVenta(int cantidad) {
    cantidadvendida += cantidad;
}

int Producto::totalVendido() const {
    return cantidadvendida;
}

double Producto::ingresosGenerados() const {
    return cantidadvendida * precio;
}

std::string Producto::Desempeno() const {
    double porcentaje = static_cast<double>(cantidadvendida) / stockinicial;

    if (porcentaje > 0.7) return "Alta rotacion";
    if (porcentaje < 0.1) return "Baja demanda";
    return "Demanda estable";
}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio ; }
int Producto::getStockInicial() const { return stockinicial; }
