// Copyright 2024 Gabriel Caixeta Romero
#include "../include/conta_palavras.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>  // Para usar isalnum()

using namespace std;

ContaPalavras::ContaPalavras() {
}

bool ContaPalavras::carregarArquivo(const string& nomeArquivo) {
    ifstream arquivo("data/" + nomeArquivo);  // Abre o arquivo com o caminho correto
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
            // Remover caracteres não alfanuméricos do final e início da palavra
            palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c) {
                return !isalnum(c);  // Remove qualquer coisa que não seja alfanumérica
            }), palavra.end());

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

int ContaPalavras::getPalavra(const string& palavra) const {
    // Verifica se a palavra está no mapa e retorna a contagem, senão retorna 0
    auto it = palavras.find(palavra);
    if (it != palavras.end()) {
        return it->second;
    }
    return 0;  // Se a palavra não for encontrada, retorna 0
}
