#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <array>
#include <string>
#include <vector>

enum class CategoriaLGPD {
    NENHUMA = 0,
    CPF,
    TEL,
    DATA,
    EMAIL,
    GENERO,
    SENSIVEL_CRENCA,
    SENSIVEL_FILIACAO,
    SENSIVEL_SAUDE
};

std::string categoriaParaTag(CategoriaLGPD cat);

struct ResultadoReconhecimento {
    bool aceito = false;
    CategoriaLGPD categoria = CategoriaLGPD::NENHUMA;
    std::vector<int> caminhoEstados;
};

class Automato {
public:
    static constexpr int TAM_ALFABETO = 128;
    static constexpr int ESTADO_MORTO = -1;

private:
    std::vector<std::array<int, TAM_ALFABETO>> tabelaTransicao;
    std::vector<CategoriaLGPD> categoriaEstadoFinal;
    int estadoInicial = 0;

public:
    Automato();
    void inicializarTabela();

    int adicionarEstado(CategoriaLGPD categoria = CategoriaLGPD::NENHUMA);
    void definirTransicao(int origem, char simbolo, int destino);
    void definirTransicaoDigitos(int origem, int destino);
    void definirTransicaoLetras(int origem, int destino);

    int proximoEstado(int estadoAtual, char entrada) const;
    CategoriaLGPD obterCategoriaFinal(int estado) const;
    bool ehFinal(int estado) const;

    int totalEstados() const;
    int totalTransicoesAtivas() const;
    int getEstadoInicial() const;

    ResultadoReconhecimento reconhecerToken(const std::string& token) const;
};

#endif // AUTOMATO_H
