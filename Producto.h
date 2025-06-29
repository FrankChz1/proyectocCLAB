#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    int stockinicial;
    int cantidadvendida;
    double precio;

public:
    Producto(const std::string& nombre, int stock, double precio);
    void registrarVenta(int cantidad);
    int totalVendido() const;
    double ingresosGenerados() const;
    std::string Desempeno() const;

    std::string getNombre() const;
    double getPrecio() const;
    int getStockInicial() const;
};

#endif
