#include "relatorio.h"
#include <iostream>
#include <sstream>

void Relatorio::registrarOcorrencia(CategoriaLGPD categoria, const std::vector<int>& caminho) {
    contagemCategorias[categoria]++;
    std::ostringstream oss;
    oss << categoriaParaTag(categoria) << " : ";
    for (std::size_t i = 0; i < caminho.size(); ++i) {
        if (i > 0) oss << " -> ";
        oss << "q" << caminho[i];
    }
    caminhosRegistrados.push_back(oss.str());
}

void Relatorio::imprimirResumo() const {
    std::cout << "\n=== Resumo da Execucao ===\n";
    for (const auto& [cat, qtd] : contagemCategorias) {
        std::cout << "  " << categoriaParaTag(cat) << ": " << qtd << "\n";
    }
}

void Relatorio::imprimirComparacaoMinimizacao(const MetricasMinimizacao& m) const {
    std::cout << "\n=== Comparacao AFD Original vs Minimizado ===\n";
    std::cout << "  Estados   : " << m.estadosAntes << " -> " << m.estadosDepois << "\n";
    std::cout << "  Transicoes: " << m.transicoesAntes << " -> " << m.transicoesDepois << "\n";
}

void Relatorio::limpar() {
    caminhosRegistrados.clear();
    contagemCategorias.clear();
}
