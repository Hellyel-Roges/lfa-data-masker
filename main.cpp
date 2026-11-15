#include <iostream>
#include <string>
#include <vector>
#include "alfabeto.h"
#include "automato.h"
#include "transdutor_mealy.h"
#include "relatorio.h"

int main() {
    std::cout << "====================================================\n";
    std::cout << " INICIANDO SISTEMA MASCARADOR LGPD \n";
    std::cout << "====================================================\n\n";

    std::cout << "Esqueleto C++ criado com sucesso!\n";

    std::regex cpf_regex(R"(^\d{3}\.?\d{3}\.?\d{3}-?\d{2}$)");
    std::regex data_regex(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
    std::regex tel_regex(R"(^\(?\d{2}\)?\s?(?:9\d{4}|\d{4})-?\d{4}$)");

    std::string cpf = "123.456.789-00";
    std::string data = "14/11/2026";
    std::string tel = "(11) 98765-4321";

    std::cout << "CPF: " << (std::regex_match(cpf, cpf_regex) ? "Valido" : "Invalido") << "\n";
    std::cout << "Data: " << (std::regex_match(data, data_regex) ? "Valida" : "Invalida") << "\n";
    std::cout << "Telefone: " << (std::regex_match(tel, tel_regex) ? "Valido" : "Invalido") << "\n";

    return 0;
}
