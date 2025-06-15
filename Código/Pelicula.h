#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(std::string id, std::string nombre, float duracion, std::string genero);
    void mostrarInfo() const override;
};

#endif