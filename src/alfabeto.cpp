#include "alfabeto.h"
#include <cctype>

TipoSimbolo classificarSimbolo(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isdigit(uc)) return TipoSimbolo::DIGITO;
    if (std::isalpha(uc)) return TipoSimbolo::LETRA;
    switch (c) {
        case '.': return TipoSimbolo::PONTO;
        case '-': return TipoSimbolo::HIFEN;
        case '/': return TipoSimbolo::BARRA;
        case '@': return TipoSimbolo::ARROBA;
        case '(': return TipoSimbolo::ABRE_PAR;
        case ')': return TipoSimbolo::FECHA_PAR;
        case ' ': return TipoSimbolo::ESPACO;
        case ':': return TipoSimbolo::DOIS_PONTOS;
        default:  return TipoSimbolo::OUTRO;
    }
}

char classificarCaractere(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isdigit(uc)) return 'D';
    if (std::isalpha(uc)) return 'L';
    return c;
}

char normalizarCaractere(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return static_cast<char>(std::tolower(uc));
}

std::string normalizarTexto(const std::string& texto) {
    std::string out;
    out.reserve(texto.size());
    for (char c : texto) {
        out.push_back(normalizarCaractere(c));
    }
    return out;
}
