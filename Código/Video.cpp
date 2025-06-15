#include "Video.h"
#include <iostream>

Video::Video(std::string id, std::string nombre, float duracion, std::string genero)
    : id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(0), numCalificaciones(0) {}

void Video::calificar(float valor) {
    if (valor < 1 || valor > 5) throw std::invalid_argument("Calificacion fuera de rango (1-5)");
    calificacion = ((calificacion * numCalificaciones) + valor) / (++numCalificaciones);
}

float Video::getCalificacion() const {
    return calificacion;
}

std::string Video::getGenero() const {
    return genero;
}

std::string Video::getNombre() const {
    return nombre;
}

bool Video::operator>(const Video& otro) const {
    return calificacion > otro.calificacion;
}