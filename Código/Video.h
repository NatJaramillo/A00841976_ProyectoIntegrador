#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class Video {
protected:
    std::string id;
    std::string nombre;
    float duracion;
    std::string genero;
    float calificacion;
    int numCalificaciones;

public:
    Video(std::string id, std::string nombre, float duracion, std::string genero);
    virtual ~Video() {}

    virtual void mostrarInfo() const = 0;
    virtual void calificar(float valor);
    float getCalificacion() const;
    std::string getGenero() const;
    std::string getNombre() const;

    bool operator>(const Video& otro) const;
};

#endif