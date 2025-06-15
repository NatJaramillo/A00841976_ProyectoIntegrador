#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(std::string id, std::string nombre, float duracion, std::string genero)
    : Video(id, nombre, duracion, genero) {}

void Pelicula::mostrarInfo() const {
    std::cout << "Pelicula: " << nombre
              << "\nDuracion: " << duracion << " min"
              << "\nGenero: " << genero
              << "\nCalificacion: " << calificacion << std::endl;
}