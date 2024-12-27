// Copyright 2024 Gabriel Caixeta Romero

#include "../include/conta_palavras.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <codecvt>
#include <cctype>
#include <vector>
#include <utility>
#include <string>

/**
 * @brief Namespace para funções auxiliares internas.
 */
namespace {
/**
 * @brief Verifica se um caractere é válido (letra, número ou caractere Unicode).
 * 
 * @param c Caractere a ser verificado.
 * @return true Se o caractere for válido.
 * @return false Caso contrário.
 */
bool isCaracterValido(char c) {
    return (std::isalpha(c) || std::isdigit(c) || (unsigned char)c >= 128);
}

/**
 * @brief Remove acentos de uma string.
 * 
 * @param palavra String com possíveis acentos.
 * @return std::string String sem acentos.
 */
std::string removerAcentos(const std::string& palavra) {
    std::locale loc("en_US.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring palavraWide = converter.from_bytes(palavra);
    for (auto& c : palavraWide) {
        if (c >= L'à' && c <= L'ÿ') {
            switch (c) {
                case L'à': case L'á': case L'â': case L'ã': case L'ä':
                case L'å': c = L'a'; break;
                case L'è': case L'é': case L'ê': case L'ë': c = L'e'; break;
                case L'ì': case L'í': case L'î': case L'ï': c = L'i'; break;
                case L'ò': case L'ó': case L'ô': case L'õ': case L'ö':
                    c = L'o'; break;
                case L'ù': case L'ú': case L'û': case L'ü': c = L'u'; break;
                case L'ç': c = L'c'; break;
                case L'ñ': c = L'n'; break;
                default: break;
            }
        }
    }
    return converter.to_bytes(palavraWide);
}
}  // namespace

/**
 * @brief Construtor da classe ContaPalavras.
 * 
 * Configura o locale global para UTF-8.
 */
ContaPalavras::ContaPalavras() {
    std::locale::global(std::locale("en_US.UTF-8"));
}

/**
 * @brief Carrega um arquivo de texto e conta as palavras presentes nele.
 * 
 * @param nomeArquivo Nome do arquivo a ser carregado (localizado na pasta "data").
 * @return true Se o arquivo foi carregado e processado com sucesso.
 * @return false Se o arquivo não pôde ser aberto.
 */
bool ContaPalavras::carregarArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo("data/" + nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }
    palavras.clear();
    char c;
    std::string palavra = "";
    while (arquivo.get(c)) {
        if (std::isalpha(c, std::locale("")) ||
            (c == '\'' && !palavra.empty() && std::isalpha(palavra.back())) ||
            (unsigned char)c >= 128) {
            palavra += c;
        } else {
            if (!palavra.empty()) {
                palavras[palavra]++;
                palavra = "";
            }
        }
    }
    if (!palavra.empty()) {
        palavras[palavra]++;
    }
    return true;
}

/**
 * @brief Obtém o total de palavras contadas no arquivo carregado.
 * 
 * @return int Número total de palavras.
 */
int ContaPalavras::getContagem() const {
    int contagem = 0;
    for (const auto& par : palavras) {
        contagem += par.second;
    }
    return contagem;
}

/**
 * @brief Obtém a contagem de uma palavra específica.
 * 
 * @param palavra Palavra a ser buscada no dicionário.
 * @return int Número de ocorrências da palavra. Retorna 0 se a palavra não
 * estiver presente.
 */
int ContaPalavras::getPalavra(const std::string& palavra) const {
    auto it = palavras.find(palavra);
    return (it != palavras.end()) ? it->second : 0;
}

/**
 * @brief Imprime as palavras e suas respectivas contagens em ordem alfabética.
 */
void ContaPalavras::printPalavras() const {
    std::vector<std::pair<std::string, int>> palavrasOrdenadas(
        palavras.begin(), palavras.end());
    std::sort(palavrasOrdenadas.begin(), palavrasOrdenadas.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
            return removerAcentos(a.first) < removerAcentos(b.first);
        });
    for (const auto& par : palavrasOrdenadas) {
        std::cout << par.first << ": " << par.second << std::endl;
    }
}
