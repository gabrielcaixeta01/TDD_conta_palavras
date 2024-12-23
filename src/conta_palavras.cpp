// Copyright 2024 Gabriel Caixeta Romero
#include "../include/conta_palavras.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ContaPalavras::ContaPalavras() {
}

bool ContaPalavras::carregarArquivo(const string& nomeArquivo) {
    // Agora vamos garantir que estamos referenciando o caminho correto
    ifstream arquivo("data/" + nomeArquivo);  // Adiciona o diretório "data/"
    if (!arquivo.is_open()) {
        return false;  // Se o arquivo não for aberto corretamente, retorna falso
    }

    // Limpa o mapa de palavras antes de contar novamente
    palavras.clear();

    string linha;
    while (getline(arquivo, linha)) {
        // Para cada linha, dividimos as palavras
        stringstream ss(linha);
        string palavra;
        while (ss >> palavra) {
            // Incrementa a contagem da palavra
            palavras[palavra]++;
        }
    }

    // Se o arquivo estiver vazio, a contagem será zero, mas o arquivo foi processado corretamente
    if (palavras.empty()) {
        return true;  // Retorna true porque o arquivo foi processado, mas não tem palavras
    }

    return true;  // Se o arquivo contiver palavras, retorna true após processá-lo
}

int ContaPalavras::getContagem() const {
    int contagem = 0;
    // Soma a contagem de todas as palavras
    for (const auto& par : palavras) {
        contagem += par.second;
    }
    return contagem;
}
