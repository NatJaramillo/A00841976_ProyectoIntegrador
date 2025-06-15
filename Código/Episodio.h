#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>

class Episodio {
private:
    std::string titulo;
    int temporada;
    float calificacion;

public:
    Episodio(std::string titulo, int temporada, float calificacion = 0);
    void mostrarInfo() const;
    void calificar(float valor);
    float getCalificacion() const;
    int getTemporada() const;
};

#endif
