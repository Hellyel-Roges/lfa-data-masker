#ifndef TRANSDUTOR_MEALY_H
#define TRANSDUTOR_MEALY_H

#include <string>
#include "automato.h"

class TransdutorMealy {
private:
    std::string bufferLexico;
    std::string saidaParcial;

public:
    TransdutorMealy();

    std::string processarTransducao(int estadoAtual, char entrada, int proximoEstado, CategoriaLGPD categoriaFinal);
    std::string mascararToken(const std::string& token, CategoriaLGPD categoria) const;

    std::string executarRollback();
    void resetarBuffer();
};

#endif // TRANSDUTOR_MEALY_H
