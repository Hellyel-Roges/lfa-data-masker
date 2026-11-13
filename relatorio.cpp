#include "relatorio.h"
#include <iostream>

std::vector<std::string> caminhoComputacional;

void registrarCaminho(const std::string& estado) {
    caminhoComputacional.push_back(estado);
}

void imprimirRelatorioFinal() {
    std::cout << "Caminho percorrido:\n";
    for(const auto& est : caminhoComputacional) {
        std::cout << est << " -> ";
    }
    std::cout << "Fim\n";
}
