#include "Sistema.h"
#include <iostream>
#include <limits>
using namespace std;

void validarEntero(int& valor, const string& mensaje) {
    cin >> valor;
    while (cin.fail() || valor <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEntrada invalida! intente de nuevo!!\n";
        cout << mensaje;
        cin >> valor;
    }
}

void validarDouble(double& valor, const string& mensaje) {
    cin >> valor;
    while (cin.fail() || valor <= 0.0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEntrada invalida! intente de nuevo!!\n";
        cout << mensaje;
        cin >> valor;
    }
}

void menu(int &op) {
    cout <<"========  MENU  ========\n";
    cout <<"1. Ingresar sucursales.\n";
    cout <<"2. Salir.\n";
    cout <<"Opcion:";
    cin >> op;

    while (cin.fail() || (op != 1 && op != 2)) {
        cin.clear(); //limpia el estado de error, cuando se ingreso un tipo
        //incorrecto, "desbloquea" el cin para seguir leyendo
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora
        //la basura del buffer, si se ingreso skdjf, lo ingora hasta \n
        cout << "\nOpcion invalida! intente de nuevo!!\n";
        cout <<"Opcion:";
        cin >> op;
    }

    cin.ignore();
    cout << "------------------------\n";
}

int main() {
    Sistema sistema;

    while (true) {
        int opcion;
        menu(opcion);

        if (opcion == 2) return 0;

        int n;
        cout << "Numero de sucursales:";
        validarEntero(n, "Numero de sucursales:");

        for (int i = 0; i < n; ++i) {
            cin.ignore();
            string nombresucursal;

            cout << "\n--- SUCURSAL #" << i + 1 << " ---\n";
            cout << "Nombre: ";
            getline(cin, nombresucursal);

            Sucursal* sucursal = new Sucursal(nombresucursal);

            int numproductos;
            cout << "Cantidad de productos:";
            validarEntero(numproductos, "Cantidad de productos:");

            for (int j = 0; j < numproductos; ++j) {
                cin.ignore();
                string nombreproducto;
                int stock;
                double precio;

                cout << "\nProducto #" << j + 1;
                cout << "\nNombre:";
                getline(cin, nombreproducto);

                cout << "Stock inicial:";
                validarEntero(stock, "Stock inicial:");

                cout << "Precio unitario (S/):";
                validarDouble(precio, "Precio unitario (S/):");

                Producto* producto = new Producto(nombreproducto, stock, precio);

                int ventadia;
                cout << "Ventas por dia:";
                validarEntero(ventadia, "Ventas por dia:");

                producto->registrarVenta(ventadia);
                sucursal->agregarProducto(producto);
            }

            sistema.agregarSucursal(sucursal);
        }

        sistema.mostrarReporteDetallado();
        sistema.mostrarRanking();
    }
}