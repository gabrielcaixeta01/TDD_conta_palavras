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
 * @param c Caractere a ser verificado.
 * @return true Se o caractere for válido.
 * @return false Caso contrário.
 */

/**
 * @brief Remove acentos de uma string.
 * @param palavra String com possíveis acentos.
 * @return std::string String sem acentos.
 */
std::string removerAcentos(const std::string& palavra) {
    std::wstring palavraWide;
    for (char c : palavra) {
        switch (static_cast<unsigned char>(c)) {
            case '\xE0': case '\xE1': case '\xE2': case '\xE3': case '\xE4': case '\xE5': c = 'a'; break; // à, á, â, ã, ä, å
            case '\xE8': case '\xE9': case '\xEA': case '\xEB': c = 'e'; break; // è, é, ê, ë
            case '\xEC': case '\xED': case '\xEE': case '\xEF': c = 'i'; break; // ì, í, î, ï
            case '\xF2': case '\xF3': case '\xF4': case '\xF5': case '\xF6': c = 'o'; break; // ò, ó, ô, õ, ö
            case '\xF9': case '\xFA': case '\xFB': case '\xFC': c = 'u'; break; // ù, ú, û, ü
            case '\xE7': c = 'c'; break; // ç
            case '\xF1': c = 'n'; break; // ñ
            default: break;
        }
        palavraWide += c;
    }
    return std::string(palavraWide.begin(), palavraWide.end());
}
}  // namespace

/**
 * @brief Construtor da classe ContaPalavras.
 * Configura o locale global para UTF-8.
 */
ContaPalavras::ContaPalavras() {
    std::locale::global(std::locale("en_US.UTF-8"));
}

/**
 * @brief Carrega um arquivo de texto e conta as palavras presentes nele.
 * @param nomeArquivo Nome do arquivo a ser carregado (localizado na pasta 
 * "data").
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
