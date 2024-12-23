// Copyright 2024 Gabriel Caixeta Romero

#define CATCH_CONFIG_MAIN
#include "../libs/catch_amalgamated.hpp"  // Incluindo a biblioteca com o caminho correto

#include "../include/conta_palavras.hpp"  // Incluindo o cabeçalho com o diretório correto

TEST_CASE("Testar carregarArquivo", "[carregarArquivo]") {
    ContaPalavras conta;

    SECTION("Arquivo inexistente") {
        REQUIRE_FALSE(conta.carregarArquivo("arquivo_inexistente.txt"));
    }

    SECTION("Arquivo vazio") {
        REQUIRE_FALSE(conta.carregarArquivo("arquivo_vazio.txt"));
    }

    SECTION("Arquivo válido") {
        REQUIRE(conta.carregarArquivo("arquivo_valido.txt"));
    }
}
