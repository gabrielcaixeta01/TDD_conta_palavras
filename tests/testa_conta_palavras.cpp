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

TEST_CASE("Quebras de linha", "[carregarArquivo]") {
    ContaPalavras conta;

    // Testa carregar um arquivo com palavras separadas por quebras de linha
    REQUIRE(conta.carregarArquivo("arquivo_quebra_de_linha.txt"));

    // Verifica se a contagem total está correta (3 palavras)
    REQUIRE(conta.getContagem() == 3);

    // Verifica se cada palavra foi contada corretamente
    REQUIRE(conta.getPalavra("palavra") == 3);
    
}

TEST_CASE("Palavras com números misturados", "[carregarArquivo]") {
    ContaPalavras conta;

    // Carrega o arquivo de teste
    REQUIRE(conta.carregarArquivo("arquivo_com_numeros.txt"));

    // Verifica o total de palavras (números isolados são ignorados)
    REQUIRE(conta.getContagem() == 4);

    // Verifica a contagem específica das palavras válidas
    REQUIRE(conta.getPalavra("teste") == 3);
    REQUIRE(conta.getPalavra("palavra") == 1);
   
    // Números isolados não devem aparecer no dicionário
    REQUIRE(conta.getPalavra("123") == 0);
    REQUIRE(conta.getPalavra("456") == 0);
}

TEST_CASE("Delimitadores não comuns", "[carregarArquivo]") {
    ContaPalavras conta;

    // Testa carregar um arquivo com palavras separadas por delimitadores incomuns
    REQUIRE(conta.carregarArquivo("arquivo_delimitadores.txt"));

    // Verifica se a contagem total está correta (4 palavras no total)
    REQUIRE(conta.getContagem() == 4);

    // Verifica se cada palavra foi contada corretamente
    REQUIRE(conta.getPalavra("palavra") == 4);   
}

TEST_CASE("Palavras separadas por múltiplos delimitadores", "[carregarArquivo]") {
    ContaPalavras conta;

    // Testa carregar o arquivo com múltiplos delimitadores consecutivos
    REQUIRE(conta.carregarArquivo("arquivo_multiplos_delimitadores.txt"));

    // Verifica se a contagem total está correta (5 palavras no total)
    REQUIRE(conta.getContagem() == 5);

    // Verifica se cada palavra foi contada corretamente
    REQUIRE(conta.getPalavra("palavra") == 5);
}

TEST_CASE("Palavras com apóstrofes", "[carregarArquivo]") {
    ContaPalavras conta;

    REQUIRE(conta.carregarArquivo("arquivo_apostrofes.txt"));

    // Contagem esperada (7 palavras no total)
    REQUIRE(conta.getContagem() == 7);

    // Verificação de palavras individuais
    REQUIRE(conta.getPalavra("it's") == 1);
    REQUIRE(conta.getPalavra("don't") == 1);
    REQUIRE(conta.getPalavra("they're") == 1);
    REQUIRE(conta.getPalavra("isn't") == 1);
    REQUIRE(conta.getPalavra("can't") == 1);
    REQUIRE(conta.getPalavra("won't") == 1);
    REQUIRE(conta.getPalavra("shouldn't") == 1);
}

TEST_CASE("Palavras em diferentes idiomas", "[carregarArquivo]") {
    ContaPalavras conta;

    // Testa carregar o arquivo com palavras de diferentes idiomas
    REQUIRE(conta.carregarArquivo("arquivo_idiomas.txt"));

    // Verifica se a contagem total está correta (5 palavras no total)
    REQUIRE(conta.getContagem() == 6);

    // Verifica se cada palavra foi contada corretamente
    REQUIRE(conta.getPalavra("coração") == 1);
    REQUIRE(conta.getPalavra("déjà") == 1);
    REQUIRE(conta.getPalavra("vu") == 1);
    REQUIRE(conta.getPalavra("niño") == 1);
    REQUIRE(conta.getPalavra("über") == 1);
    REQUIRE(conta.getPalavra("jalapeño") == 1);
}

TEST_CASE("Arquivo com apenas delimitadores", "[carregarArquivo]") {
    ContaPalavras conta;

    REQUIRE(conta.carregarArquivo("arquivo_apenas_delimitadores.txt"));

    // Contagem esperada (0 palavras)
    REQUIRE(conta.getContagem() == 0);
}
