#include "Serie.h"
#include <iostream>
#include <stdexcept>

Serie::Serie(std::string id, std::string nombre, float duracion, std::string genero)
    : Video(id, nombre, duracion, genero) {}

void Serie::agregarEpisodio(std::string titulo, int temporada) {
    episodios.push_back(Episodio(titulo, temporada));
}

void Serie::mostrarInfo() const {
    std::cout << "Serie: " << nombre
              << "\nDuracion total: " << duracion << " min"
              << "\nGenero: " << genero
              << "\nCalificacion general: " << calificacion << std::endl;
}

void Serie::mostrarEpisodios() const {
    std::cout << "\nLista de episodios:\n";
    for (const auto& ep : episodios) {
        ep.mostrarInfo();
    }
}

void Serie::calificarEpisodio(int index, float valor) {
    if (index < 0 || index >= episodios.size())
        throw std::out_of_range("Indice de episodio invalido");
    episodios[index].calificar(valor);
}
