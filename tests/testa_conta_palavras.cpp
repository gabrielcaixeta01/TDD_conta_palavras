// Copyright 2024 Gabriel Caixeta Romero

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../libs/catch_amalgamated.hpp"
#include "../include/conta_palavras.hpp"

/**
 * @brief Teste em arquivo vazio.
 */
TEST_CASE("Arquivo vazio", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_vazio.txt"));
    std::cout << "Arquivo: arquivo_vazio.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 0);
}

/**
 * @brief Teste com arquivo válido.
 */
TEST_CASE("Arquivo válido", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_valido.txt"));
    std::cout << "Arquivo: arquivo_valido.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 8);
}

/**
 * @brief Teste com arquivo inexistente.
 */
TEST_CASE("Arquivo inexistente", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE_FALSE(conta.carregarArquivo("arquivo_inexistente.txt"));
    std::cout << "Arquivo: arquivo_inexistente.txt" << std::endl;
    conta.printPalavras();
}

/**
 * @brief Teste com palavras repetidas no arquivo.
 */
TEST_CASE("Arquivo com palavras repetidas", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_repetido.txt"));
    std::cout << "Arquivo: arquivo_repetido.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 10);
}

/**
 * @brief Teste diferenciação de maiúsculas e minúsculas.
 */
TEST_CASE("Diferenciação de maiúsculas e minúsculas", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_maiusculas_minusculas.txt"));
    std::cout << "Arquivo: arquivo_maiusculas_minusculas.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getPalavra("Texto") == 1);
    REQUIRE(conta.getPalavra("texto") == 1);
}

/**
 * @brief Teste com caracteres especiais.
 */
TEST_CASE("Palavras com caracteres especiais", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_com_acento.txt"));
    std::cout << "Arquivo: arquivo_com_acento.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getPalavra("é") == 1);
    REQUIRE(conta.getPalavra("será") == 1);
}

/**
 * @brief Teste com varias quebras de linha no arquivo.
 */
TEST_CASE("Quebras de linha", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_quebra_de_linha.txt"));
    std::cout << "Arquivo: arquivo_quebra_de_linha.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 3);
    REQUIRE(conta.getPalavra("palavra") == 3);
}

/**
 * @brief Teste com palavras misturadas a números.
 */
TEST_CASE("Palavras com números misturados", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_com_numeros.txt"));
    std::cout << "Arquivo: arquivo_com_numeros.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 4);
    REQUIRE(conta.getPalavra("teste") == 3);
    REQUIRE(conta.getPalavra("palavra") == 1);
    REQUIRE(conta.getPalavra("123") == 0);
}

/**
 * @brief Teste com delimitadores não comuns.
 */
TEST_CASE("Delimitadores não comuns", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_delimitadores.txt"));
    std::cout << "Arquivo: arquivo_delimitadores.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 4);
    REQUIRE(conta.getPalavra("palavra") == 4);
}

/**
 * @brief Teste com múltiplos delimitadores consecutivos.
 */
TEST_CASE("Múltiplos delimitadores", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_multiplos_delimitadores.txt"));
    std::cout << "Arquivo: arquivo_multiplos_delimitadores.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 5);
    REQUIRE(conta.getPalavra("palavra") == 5);
}

/**
 * @brief Teste com palavras contendo apóstrofes.
 */
TEST_CASE("Palavras com apóstrofes", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_apostrofes.txt"));
    std::cout << "Arquivo: arquivo_apostrofes.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 7);
    REQUIRE(conta.getPalavra("it's") == 1);
    REQUIRE(conta.getPalavra("don't") == 1);
}

/**
 * @brief Teste com palavras em diferentes idiomas.
 */
TEST_CASE("Palavras em diferentes idiomas", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_idiomas.txt"));
    std::cout << "Arquivo: arquivo_idiomas.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 6);
    REQUIRE(conta.getPalavra("coração") == 1);
    REQUIRE(conta.getPalavra("déjà") == 1);
    REQUIRE(conta.getPalavra("jalapeño") == 1);
}

/**
 * @brief Teste com arquivo contendo apenas delimitadores.
 */
TEST_CASE("Arquivo com apenas delimitadores", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_apenas_delimitadores.txt"));
    std::cout << "Arquivo: arquivo_apenas_delimitadores.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 0);
}

/**
 * @brief Teste com palavras muito longas.
 */
TEST_CASE("Palavras muito longas", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_palavras_longas.txt"));
    std::cout << "Arquivo: arquivo_palavras_longas.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 6);
    REQUIRE(conta.getPalavra("supercalifragilisticexpialidocious") == 2);
    REQUIRE(conta.getPalavra("floccinaucinihilipilification") == 1);
}

/**
 * @brief Teste de ordem alfabética na listagem de palavras.
 */
TEST_CASE("Teste ordem alfabética", "[ordem_alfabetica]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_alfabetico.txt"));
    std::cout << "Arquivo: arquivo_alfabetico.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getPalavra("abelha") == 2);
    REQUIRE(conta.getPalavra("zebra") == 2);
}

/**
 * @brief Teste com palavras misturadas a símbolos.
 */
TEST_CASE("Palavras com símbolos misturados", "[carregarArquivo]") {
    ContaPalavras conta;
    REQUIRE(conta.carregarArquivo("arquivo_palavras_simbolos.txt"));
    std::cout << "Arquivo: arquivo_palavras_simbolos.txt" << std::endl;
    conta.printPalavras();
    REQUIRE(conta.getContagem() == 9);
    REQUIRE(conta.getPalavra("palavra") == 3);
    REQUIRE(conta.getPalavra("valida") == 1);
}
