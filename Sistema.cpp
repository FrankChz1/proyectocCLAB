#include "Sistema.h"
#include <iostream>
#include <algorithm>

Sistema::~Sistema() {
    for (Sucursal* s : sucursales) {
        delete s;
    }
}

void Sistema::agregarSucursal(Sucursal* sucursal) {
    sucursales.push_back(sucursal);
}

void Sistema::mostrarReporteDetallado() const {
    std::cout << "\n\n==== REPORTE DETALLADO ====\n";
    for (Sucursal* s : sucursales) {
        s->mostrarResumen();
    }
}

void Sistema::mostrarRanking() const {
    std::vector<Sucursal*> ordenadas = sucursales;

    //std::sort(inicio, fin, criterio (2 parametros))

    //Estructura lambda
    //[captura](parámetros) -> tipo_retorno { cuerpo;}

    std::sort(ordenadas.begin(), ordenadas.end(), [](Sucursal* a, Sucursal* b) {
        return a->calcularIngresosTotales() > b->calcularIngresosTotales();
    });

    std::cout << "\n\n==== RANKING NACIONAL ====\n";
    for (Sucursal* s : ordenadas) {
        std::cout << "Sucursal: " << s->getNombre()
                  << " | Ingresos: S/ " << s->calcularIngresosTotales() << "\n";
    }
    std::cout << "\n\núúóú-úúóúú-úú-óóú-óúúú-úúó-úóúú-óóúó-úúóú-úúú-úúóó-úú\n\n\n";
}

