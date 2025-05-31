#ifndef ESTUDOS_H
#define ESTUDOS_H

#include <string>

class Estudos {
public:
    std::string nomeEstudo;
    std::string inicioEstudo;
    std::string fimEstudo;

    Estudos() = default;

    Estudos(std::string nome, std::string inicio, std::string fim)
        : nomeEstudo(nome), inicioEstudo(inicio), fimEstudo(fim) {}
};

#endif