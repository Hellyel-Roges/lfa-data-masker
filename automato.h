#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string>

class Automato {
public:
    Automato();
    void inicializarTabela();
    int proximoEstado(int estadoAtual, char entrada);
};

#endif // AUTOMATO_H
