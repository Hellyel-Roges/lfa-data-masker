#include "minimizador.h"

Automato minimizarAFD(const Automato& original, MetricasMinimizacao& metricas) {
    metricas.estadosAntes = original.totalEstados();
    metricas.transicoesAntes = original.totalTransicoesAtivas();

    // TODO (Gustavo): BFS para alcancaveis + particionamento por classes de equivalencia
    Automato minimizado = original;

    metricas.estadosDepois = minimizado.totalEstados();
    metricas.transicoesDepois = minimizado.totalTransicoesAtivas();
    return minimizado;
}
