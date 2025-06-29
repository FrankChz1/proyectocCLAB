#ifndef SISTEMA_H
#define SISTEMA_H

#include "Sucursal.h"
#include <vector>

class Sistema {
private:
    std::vector<Sucursal*> sucursales;

public:
    ~Sistema();

    void agregarSucursal(Sucursal* sucursal);
    void mostrarReporteDetallado() const;
    void mostrarRanking() const;
};

#endif
