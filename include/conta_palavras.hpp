// Copyright 2024 Gabriel Caixeta Romero

#ifndef INCLUDE_CONTA_PALAVRAS_HPP_
#define INCLUDE_CONTA_PALAVRAS_HPP_

#include <string>
#include <unordered_map>

using namespace std;  // Adiciona isso para não precisar usar "std::" toda hora

class ContaPalavras {
    public:
        ContaPalavras();
        bool carregarArquivo(const string& nomeArquivo);  // Usa string diretamente
        int getContagem() const;  // Método para obter a contagem de palavras
    private:
        unordered_map<string, int> palavras;  // Usa unordered_map diretamente
};

#endif  // INCLUDE_CONTA_PALAVRAS_HPP_
