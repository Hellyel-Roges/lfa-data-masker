#include "transdutor_mealy.h"

TransdutorMealy::TransdutorMealy() = default;

std::string TransdutorMealy::processarTransducao(int estadoAtual, char entrada, int proximoEstado, CategoriaLGPD categoriaFinal) {
    (void)estadoAtual;
    (void)entrada;
    (void)proximoEstado;
    (void)categoriaFinal;
    // TODO (Hellyel): implementar funcao lambda(q, a) + buffer/rollback
    return "";
}

std::string TransdutorMealy::mascararToken(const std::string& token, CategoriaLGPD categoria) const {
    (void)token;
    (void)categoria;
    // TODO (Hellyel): ofuscar preservando separadores e chaves sensiveis
    return "";
}

std::string TransdutorMealy::executarRollback() {
    std::string original = bufferLexico;
    resetarBuffer();
    return original;
}

void TransdutorMealy::resetarBuffer() {
    bufferLexico.clear();
    saidaParcial.clear();
}
