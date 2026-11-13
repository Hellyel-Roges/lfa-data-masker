# 🛡️ Reconhecedor e Transdutor Léxico (Mascarador LGPD)

![C++](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Teoria da Computação](https://img.shields.io/badge/Linguagens_Formais-Automatos-4B0082?style=for-the-badge)
![LGPD](https://img.shields.io/badge/Compliance-LGPD-2EA44F?style=for-the-badge)

Este projeto consiste em um sistema computacional desenvolvido em **C++17** para reconhecimento, classificação e transdução léxica. O sistema atua como um filtro de privacidade para arquivos de *log* e textos não estruturados, mascarando automaticamente Dados Pessoais e Dados Pessoais Sensíveis em conformidade com a **Lei Geral de Proteção de Dados (LGPD)**.

Pesquisa Curricularizada de Graduação (PCG) desenvolvida para o componente curricular de **Linguagens Formais e Autômatos** (6º semestre de Ciência da Computação) na Universidade Católica de Santos (UniSantos).

---

## 📋 Funcionalidades e Padrões Reconhecidos

O sistema utiliza uma arquitetura híbrida que combina varredura de *tokens* via Expressões Regulares e a simulação de uma **Máquina de Mealy** para a ofuscação síncrona dos caracteres e emissão das *tags* de classificação.

**Dados Pessoais Diretos:**
- 📄 **CPF:** `DDD.DDD.DDD-DD` ➔ `***.***.***-**[LGPD:CPF]`
- 📞 **Telefone:** `(DD) DDDDD-DDDD` ➔ `(**) *****-****[LGPD:TEL]`
- 📅 **Data de Nascimento:** `DD/DD/DDDD` ➔ `**/**/****[LGPD:DATA]`
- 📧 **E-mail:** `L+@L+.L³` ➔ `****@***.***[LGPD:EMAIL]`
- 👤 **Sexo/Gênero:** Padrões chave-valor ➔ `sexo:********[LGPD:GENERO]`

**Dados Pessoais Sensíveis:**
- 🏥 **Corpo e Saúde:** `saude:hiv`, `saude:diabetes`, etc. ➔ `saude:***[LGPD:SENSIVEL-SAUDE]`
- ⚖️ **Crenças e Identidade:** Etnia, religião e opinião política ➔ `religiao:*******[LGPD:SENSIVEL-CRENCA]`
- 🤝 **Associações:** Sindicatos e ONGs ➔ `filiacao:*********[LGPD:SENSIVEL-FILIACAO]`

---

## ⚙️ Arquitetura do Sistema

A implementação segue uma estrutura modular para separar a classificação do alfabeto, a matriz de estados e o transdutor:

*   `main.cpp` - Interface de execução e laço principal do motor híbrido.
*   `alfabeto.cpp` - Mapeamento e normalização do Vocabulário de Entrada ($V_{in}$).
*   `automato.cpp` - Estrutura do Autômato Finito Determinístico Mínimo (Matriz de Transições).
*   `transdutor_mealy.cpp` - Função de saída $\lambda(q, a)$ e controle do *buffer* de *rollback*.
*   `relatorio.cpp` - Registro de caminhos computacionais ($q_0 \rightarrow q_1 \dots$) e estatísticas.

---

## 🚀 Como Compilar e Executar

Certifique-se de ter o compilador `g++` e o `make` instalados em seu ambiente Linux, WSL ou VS Code.

**1. Clone o repositório:**
```bash
git clone https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git
cd NOME_DO_REPOSITORIO
```

**2. Compile o projeto via Makefile:**
```bash
make
```

**3. Execute o mascarador:**
```bash
./mascarador
```

---

## 🧪 Exemplo de Uso (Teste de Mesa)

**Entrada (Log original):**
> `Usuario 123.456.789-00 acessou o prontuario contendo saude:hiv e religiao:umbanda`

**Saída Transduzida (Mascarada):**
> `Usuario ***.***.***-**[LGPD:CPF] acessou o prontuario contendo saude:***[LGPD:SENSIVEL-SAUDE] e religiao:*******[LGPD:SENSIVEL-CRENCA]`

---

## 👥 Equipe Desenvolvedora (Grupo 03)

*   **Felipe Mafra dos Santos** - Modelagem formal (AFND/AFD) e elaboração das tabelas de transição teóricas.
*   **Graziela Cristina Soares Antiorio** - Validação experimental, bateria de casos de teste e análise de limitações.
*   **Gustavo Freitas Sampaio** - Implementação C++ do motor lógico do AFD Mínimo e rastreamento de caminhos.
*   **Hellyel Roges dos Passos A. Pereira** - Coordenação, arquitetura do software, formatação ABNT e implementação C++ do Transdutor de Mealy.
*   **Luan Felix Pereira** - Especificação matemática das Expressões Regulares e dicionário de dados sensíveis.

👨‍🏫 **Orientador:** Prof. José Fontebasso Neto
