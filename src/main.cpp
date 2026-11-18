#include <iostream>
#include <regex>
#include <string>
#include "alfabeto.h"
#include "automato.h"
#include "minimizador.h"
#include "transdutor_mealy.h"
#include "relatorio.h"

int main() {
    std::cout << "====================================================\n";
    std::cout << "  MASCARADOR DE DADOS LGPD - ENTREGAVEL 2 (C++17)   \n";
    std::cout << "====================================================\n\n";

    // Regexes alinhadas a Secao 4.3 do Entregavel 1
    const std::regex cpf_regex(R"(^\d{3}\.\d{3}\.\d{3}-\d{2}$)");
    const std::regex data_regex(R"(^\d{2}/\d{2}/\d{4}$)");
    const std::regex tel_regex(R"(^\(\d{2}\) \d{4,5}-\d{4}$)");

    std::string cpf  = "123.456.789-00";
    std::string data = "25/12/1998";
    std::string tel  = "(13) 98877-6655";

    std::cout << "[Sanity Check ERs Entregavel 1]\n";
    std::cout << "  CPF      (" << cpf  << "): " << (std::regex_match(cpf, cpf_regex)   ? "ACEITO" : "REJEITADO") << "\n";
    std::cout << "  Data     (" << data << "): " << (std::regex_match(data, data_regex) ? "ACEITA" : "REJEITADA") << "\n";
    std::cout << "  Telefone (" << tel  << "): " << (std::regex_match(tel, tel_regex)   ? "ACEITO" : "REJEITADO") << "\n";

    Automato afd;
    afd.inicializarTabela();

    MetricasMinimizacao metricas;
    Automato afdMin = minimizarAFD(afd, metricas);
    (void)afdMin;

    Relatorio rel;
    rel.imprimirComparacaoMinimizacao(metricas);

    return 0;
}
