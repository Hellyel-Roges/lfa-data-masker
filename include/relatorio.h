#ifndef RELATORIO_H
#define RELATORIO_H

#include <map>
#include <string>
#include <vector>
#include "automato.h"
#include "minimizador.h"

class Relatorio {
private:
    std::vector<std::string> caminhosRegistrados;
    std::map<CategoriaLGPD, int> contagemCategorias;

public:
    void registrarOcorrencia(CategoriaLGPD categoria, const std::vector<int>& caminho);
    void imprimirResumo() const;
    void imprimirComparacaoMinimizacao(const MetricasMinimizacao& m) const;
    void limpar();
};

#endif // RELATORIO_H
