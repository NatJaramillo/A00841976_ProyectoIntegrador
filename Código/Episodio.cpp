#include "Episodio.h"
#include <iostream>
#include <stdexcept>

Episodio::Episodio(std::string titulo, int temporada, float calificacion)
    : titulo(titulo), temporada(temporada), calificacion(calificacion) {}

void Episodio::mostrarInfo() const {
    std::cout << "Episodio: " << titulo
              << " | Temporada: " << temporada
              << " | Calificacion: " << calificacion << std::endl;
}

void Episodio::calificar(float valor) {
    if (valor < 1 || valor > 5)
        throw std::invalid_argument("Calificacion fuera de rango (1-5)");
    calificacion = valor;
}

float Episodio::getCalificacion() const {
    return calificacion;
}

int Episodio::getTemporada() const {
    return temporada;
}
