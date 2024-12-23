// Copyright 2024 Gabriel Caixeta Romero
#include "../include/conta_palavras.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <locale>  // Para configurar o locale UTF-8
#include <cctype>  // Para funções de caracteres

using namespace std;

// Função personalizada para verificar se o caractere é válido
bool isCaracterValido(char c) {
    // Verifica se é uma letra ou número (incluindo caracteres com acentos no intervalo Unicode)
    return (isalpha(c) || isdigit(c) || (unsigned char)c >= 128);
}

ContaPalavras::ContaPalavras() {
    // Configura o locale global para UTF-8
    locale::global(locale("en_US.UTF-8"));
}

bool ContaPalavras::carregarArquivo(const string& nomeArquivo) {
    ifstream arquivo("data/" + nomeArquivo);  // Abre o arquivo com o caminho correto
    if (!arquivo.is_open()) {
        return false;  // Se o arquivo não for aberto corretamente, retorna falso
    }

    // Limpa o mapa de palavras antes de contar novamente
    palavras.clear();

    char c;  // Caractere atual
    string palavra = "";  // Palavra em construção

    while (arquivo.get(c)) {  // Lê caractere por caractere
        if (isCaracterValido(c)) {  // Usa a função personalizada para verificar o caractere
            palavra += c;  // Adiciona o caractere à palavra atual
        } else {  // Encontrou um delimitador (espaço, vírgula, ponto, etc.)
            if (!palavra.empty()) {  // Se houver uma palavra em construção
                palavras[palavra]++;  // Adiciona a palavra ao dicionário

                // Depuração: imprime a palavra adicionada
                cout << "Palavra adicionada: " << palavra << endl;

                palavra = "";  // Zera a palavra para começar outra
            }
        }
    }

    // Adiciona a última palavra, se houver (caso o arquivo não termine com um delimitador)
    if (!palavra.empty()) {
        palavras[palavra]++;
        cout << "Palavra adicionada (final): " << palavra << endl;  // Depuração
    }

    // Depuração: imprime todas as palavras no mapa
    cout << "Palavras no dicionário:" << endl;
    for (const auto& par : palavras) {
        cout << par.first << ": " << par.second << endl;
    }

    return true;  // Retorna true porque o arquivo foi processado corretamente
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