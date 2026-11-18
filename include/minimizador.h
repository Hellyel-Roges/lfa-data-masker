#ifndef MINIMIZADOR_H
#define MINIMIZADOR_H

#include "automato.h"

struct MetricasMinimizacao {
    int estadosAntes = 0;
    int estadosDepois = 0;
    int transicoesAntes = 0;
    int transicoesDepois = 0;
    int inacessiveisRemovidos = 0;
    int equivalentesFundidos = 0;
};

Automato minimizarAFD(const Automato& original, MetricasMinimizacao& metricas);

#endif // MINIMIZADOR_H
