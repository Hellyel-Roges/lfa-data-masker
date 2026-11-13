#ifndef TRANSDUTOR_MEALY_H
#define TRANSDUTOR_MEALY_H

#include <string>

class TransdutorMealy {
private:
    std::string bufferLexico;
public:
    TransdutorMealy();
    std::string processarTransdicao(int estadoAtual, char entrada, int proximoEstado);
    void resetarBuffer();
};

#endif // TRANSDUTOR_MEALY_H
