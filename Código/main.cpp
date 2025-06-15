#include <iostream>
#include <vector>
#include <limits>
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Video*> videos;

    int opcion;
    do {
        cout << "\nMENU\n";
        cout << "1. Agregar Pelicula\n";
        cout << "2. Agregar Serie\n";
        cout << "3. Mostrar todos los videos\n";
        cout << "4. Mostrar episodios de una serie\n";
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        limpiarEntrada();

        if (opcion == 1) {
            string id, nombre, genero;
            float duracion;
            cout << "ID: "; getline(cin, id);
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Duracion: "; cin >> duracion; limpiarEntrada();
            cout << "Genero: "; getline(cin, genero);

            videos.push_back(new Pelicula(id, nombre, duracion, genero));
            cout << "Pelicula agregada.\n";

        } else if (opcion == 2) {
            string id, nombre, genero;
            float duracion;
            int numEp;
            cout << "ID: "; getline(cin, id);
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Duracion: "; cin >> duracion; limpiarEntrada();
            cout << "Genero: "; getline(cin, genero);

            Serie* nuevaSerie = new Serie(id, nombre, duracion, genero);
            cout << "Cuantos episodios deseas agregar? ";
            cin >> numEp;
            limpiarEntrada();

            for (int i = 0; i < numEp; i++) {
                string titulo;
                int temporada;
                cout << "Titulo del episodio " << (i + 1) << ": ";
                getline(cin, titulo);
                cout << "Temporada: ";
                cin >> temporada;
                limpiarEntrada();
                nuevaSerie->agregarEpisodio(titulo, temporada);
            }

            videos.push_back(nuevaSerie);
            cout << "Serie agregada.\n";

        } else if (opcion == 3) {
            for (auto v : videos) {
                v->mostrarInfo();
                cout << "----------------\n";
            }

        } else if (opcion == 4) {
            string nombre;
            cout << "Nombre de la serie: ";
            getline(cin, nombre);
            for (auto v : videos) {
                if (v->getNombre() == nombre) {
                    Serie* s = dynamic_cast<Serie*>(v);
                    if (s) s->mostrarEpisodios();
                }
            }

        } else if (opcion == 5) {
            string nombre;
            float valor;
            cout << "Nombre del video a calificar: ";
            getline(cin, nombre);
            cout << "Calificacion (1-5): ";
            cin >> valor;
            limpiarEntrada();

            for (auto v : videos) {
                if (v->getNombre() == nombre) {
                    try {
                        v->calificar(valor);
                        cout << "Calificacion registrada.\n";
                    } catch (const exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                }
            }
        }

    } while (opcion != 0);

    // Liberar memoria
    for (auto v : videos) delete v;

    cout << "Programa finalizado.\n";
    return 0;
}
