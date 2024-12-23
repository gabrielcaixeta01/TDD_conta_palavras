// Copyright 2024 Gabriel Caixeta Romero

#define CATCH_CONFIG_MAIN
#include "../libs/catch_amalgamated.hpp"  // Incluindo a biblioteca com o caminho correto

#include "../include/conta_palavras.hpp"  // Incluindo o cabeçalho com o diretório correto

// Teste em arquivo vazio
TEST_CASE("Arquivo vazio", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo vazio
    REQUIRE(conta.carregarArquivo("arquivo_vazio.txt"));  // Certifique-se de que está usando o caminho correto

    // Verificando que a contagem de palavras é zero
    REQUIRE(conta.getContagem() == 0);  // Esperado que a contagem seja 0 para um arquivo vazio
}

// Teste contando errado o numero de palavras
TEST_CASE("Arquivo válido", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo válido
    REQUIRE(conta.carregarArquivo("arquivo_valido.txt"));  // Certifique-se de que está usando o caminho correto

    // Verificando a contagem de palavras
    REQUIRE(conta.getContagem() == 8);  // Esperado que o arquivo tenha 6 palavras, por exemplo
}

// Teste com arquivo inexistente
TEST_CASE("Arquivo inexistente", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo inexistente
    REQUIRE_FALSE(conta.carregarArquivo("arquivo_inexistente.txt"));  // Esperado: false
}

// Teste arquivo com palavras repetidas
TEST_CASE("Arquivo com palavras repetidas", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo com palavras repetidas
    REQUIRE(conta.carregarArquivo("arquivo_repetido.txt"));

    // Verificando as contagens esperadas (substitua pelos valores reais de contagem no seu arquivo)
    REQUIRE(conta.getContagem() == 10);  // Exemplo de contagem de palavras
}

// Teste com letras maiúsculas e minúsculas
TEST_CASE("Diferenciação de maiúsculas e minúsculas", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo com maiúsculas e minúsculas
    REQUIRE(conta.carregarArquivo("arquivo_maiusculas_minusculas.txt"));

    // Verificando que "Texto" e "texto" são contados separadamente
    REQUIRE(conta.getPalavra("Texto") == 1);  // Esperado: 1
    REQUIRE(conta.getPalavra("texto") == 1);  // Esperado: 1
}

// Teste com com caracteres especiais
TEST_CASE("Palavras com caracteres especiais", "[carregarArquivo]") {
    ContaPalavras conta;

    // Simulando o carregamento de um arquivo com caracteres especiais
    REQUIRE(conta.carregarArquivo("arquivo_com_acento.txt"));

    // Verificando a contagem de palavras com acentos
    REQUIRE(conta.getPalavra("é") == 1);  // Esperado: 1
    REQUIRE(conta.getPalavra("será") == 1);  // Esperado: 1
}