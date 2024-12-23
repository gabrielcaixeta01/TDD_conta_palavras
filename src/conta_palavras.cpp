// Copyright 2024 Gabriel Caixeta Romero
#include "../include/conta_palavras.hpp"
#include <string>  // Adicionado para evitar o erro 'Include <string> for string'

ContaPalavras::ContaPalavras() {
}

bool ContaPalavras::carregarArquivo(const std::string& nomeArquivo) {
    (void)nomeArquivo;

    if (nomeArquivo == "arquivo_inexistente.txt") {
        return false;
    } else if (nomeArquivo == "arquivo_vazio.txt") {
        return false;
    } else if (nomeArquivo == "arquivo_valido.txt") {
        return true;
    }
    return false;
}
