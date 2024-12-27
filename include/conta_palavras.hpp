// Copyright 2024 Gabriel Caixeta Romero

#ifndef INCLUDE_CONTA_PALAVRAS_HPP_
#define INCLUDE_CONTA_PALAVRAS_HPP_

#include <string>
#include <unordered_map>
#include <locale>
#include <vector>

/**
 * @class ContaPalavras
 * @brief Classe responsável por carregar um arquivo de texto, contar as palavras
 * presentes nele e apresentar os resultados.
 */
class ContaPalavras {
 public:
    /**
     * @brief Construtor da classe ContaPalavras.
     * Configura o locale necessário para suportar UTF-8.
     */
    ContaPalavras();

    /**
     * @brief Carrega um arquivo de texto e conta as palavras presentes nele.
     * 
     * @param nomeArquivo Nome do arquivo a ser carregado (localizado na pasta "data").
     * @return true Se o arquivo foi carregado e processado com sucesso.
     * @return false Se o arquivo não pôde ser aberto.
     */
    bool carregarArquivo(const std::string& nomeArquivo);

    /**
     * @brief Obtém o total de palavras contadas no arquivo carregado.
     * 
     * @return int Número total de palavras.
     */
    int getContagem() const;

    /**
     * @brief Obtém a contagem de uma palavra específica.
     * 
     * @param palavra Palavra a ser buscada no dicionário.
     * @return int Número de ocorrências da palavra. Retorna 0 se a palavra não
     * estiver presente.
     */
    int getPalavra(const std::string& palavra) const;

    /**
     * @brief Imprime as palavras e suas respectivas contagens em ordem alfabética.
     */
    void printPalavras() const;

 private:
    /**
     * @brief Dicionário que mapeia cada palavra para o número de ocorrências.
     */
    std::unordered_map<std::string, int> palavras;
};

#endif  // INCLUDE_CONTA_PALAVRAS_HPP_
