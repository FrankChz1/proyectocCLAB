#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    int opcion;
    while (true) {
        cout <<"Menu:\n";
        cout <<"1. Ingresar sucursales.\n";
        cout <<"2. Salir.\n";
        cout <<"Opcion:";
        cin >> opcion;
        cin.ignore();

        if (opcion == 2) {
            return 0;
        }
        cout <<"\nNumero de sucursales:";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            int cant;
            cout<< "\nCantidad de productos de sucursal "<<i+1<<":";
            cin>>cant;
            cin.ignore();

            for (int j = 0; j < cant; j++) {
                string producto;
                cout<<"Producto "<<j+1<<":";
                cin>>producto;
                //mas datos
            }
        }
    }

    return 0;
}
