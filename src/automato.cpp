#include "automato.h"

std::string categoriaParaTag(CategoriaLGPD cat) {
    switch (cat) {
        case CategoriaLGPD::CPF:               return "[LGPD:CPF]";
        case CategoriaLGPD::TEL:               return "[LGPD:TEL]";
        case CategoriaLGPD::DATA:              return "[LGPD:DATA]";
        case CategoriaLGPD::EMAIL:             return "[LGPD:EMAIL]";
        case CategoriaLGPD::GENERO:            return "[LGPD:GENERO]";
        case CategoriaLGPD::SENSIVEL_CRENCA:   return "[LGPD:SENSIVEL-CRENCA]";
        case CategoriaLGPD::SENSIVEL_FILIACAO: return "[LGPD:SENSIVEL-FILIACAO]";
        case CategoriaLGPD::SENSIVEL_SAUDE:    return "[LGPD:SENSIVEL-SAUDE]";
        default:                               return "";
    }
}

Automato::Automato() {
    adicionarEstado(CategoriaLGPD::NENHUMA); // q0
}

void Automato::inicializarTabela() {
    // TODO (Gustavo): popular ramos do AFD (CPF, Data, Tel, Email e Dicionario LGPD)
}

int Automato::adicionarEstado(CategoriaLGPD categoria) {
    std::array<int, TAM_ALFABETO> linha;
    linha.fill(ESTADO_MORTO);
    tabelaTransicao.push_back(linha);
    categoriaEstadoFinal.push_back(categoria);
    return static_cast<int>(tabelaTransicao.size()) - 1;
}

void Automato::definirTransicao(int origem, char simbolo, int destino) {
    unsigned char idx = static_cast<unsigned char>(simbolo);
    if (origem >= 0 && origem < totalEstados() && idx < TAM_ALFABETO) {
        tabelaTransicao[origem][idx] = destino;
    }
}

void Automato::definirTransicaoDigitos(int origem, int destino) {
    for (char c = '0'; c <= '9'; ++c) definirTransicao(origem, c, destino);
}

void Automato::definirTransicaoLetras(int origem, int destino) {
    for (char c = 'a'; c <= 'z'; ++c) definirTransicao(origem, c, destino);
}

int Automato::proximoEstado(int estadoAtual, char entrada) const {
    unsigned char idx = static_cast<unsigned char>(entrada);
    if (estadoAtual < 0 || estadoAtual >= totalEstados() || idx >= TAM_ALFABETO) {
        return ESTADO_MORTO;
    }
    return tabelaTransicao[estadoAtual][idx];
}

CategoriaLGPD Automato::obterCategoriaFinal(int estado) const {
    if (estado < 0 || estado >= totalEstados()) return CategoriaLGPD::NENHUMA;
    return categoriaEstadoFinal[estado];
}

bool Automato::ehFinal(int estado) const {
    return obterCategoriaFinal(estado) != CategoriaLGPD::NENHUMA;
}

int Automato::totalEstados() const {
    return static_cast<int>(tabelaTransicao.size());
}

int Automato::totalTransicoesAtivas() const {
    int count = 0;
    for (const auto& linha : tabelaTransicao) {
        for (int dest : linha) {
            if (dest != ESTADO_MORTO) ++count;
        }
    }
    return count;
}

int Automato::getEstadoInicial() const {
    return estadoInicial;
}

ResultadoReconhecimento Automato::reconhecerToken(const std::string& token) const {
    ResultadoReconhecimento res;
    int atual = estadoInicial;
    res.caminhoEstados.push_back(atual);

    for (char c : token) {
        atual = proximoEstado(atual, c);
        res.caminhoEstados.push_back(atual);
        if (atual == ESTADO_MORTO) {
            return res;
        }
    }

    res.categoria = obterCategoriaFinal(atual);
    res.aceito = (res.categoria != CategoriaLGPD::NENHUMA);
    return res;
}
