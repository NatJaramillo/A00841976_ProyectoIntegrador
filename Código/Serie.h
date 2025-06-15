#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

class Serie : public Video {
private:
    std::vector<Episodio> episodios;

public:
    Serie(std::string id, std::string nombre, float duracion, std::string genero);
    void agregarEpisodio(std::string titulo, int temporada);
    void mostrarInfo() const override;
    void mostrarEpisodios() const;
    void calificarEpisodio(int index, float valor);
};

#endif
