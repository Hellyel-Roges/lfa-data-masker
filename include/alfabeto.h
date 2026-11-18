#ifndef ALFABETO_H
#define ALFABETO_H

#include <string>

enum class TipoSimbolo {
    DIGITO,
    LETRA,
    PONTO,
    HIFEN,
    BARRA,
    ARROBA,
    ABRE_PAR,
    FECHA_PAR,
    ESPACO,
    DOIS_PONTOS,
    OUTRO
};

TipoSimbolo classificarSimbolo(char c);
char classificarCaractere(char c);
char normalizarCaractere(char c);
std::string normalizarTexto(const std::string& texto);

#endif // ALFABETO_H
