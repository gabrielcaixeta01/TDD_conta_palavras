// Copyright 2024 Gabriel Caixeta Romero
#ifndef INCLUDE_CONTA_PALAVRAS_HPP_
#define INCLUDE_CONTA_PALAVRAS_HPP_

#include <string>
#include <unordered_map>

using namespace std;

class ContaPalavras {
     public:
        ContaPalavras();
        bool carregarArquivo(const string& nomeArquivo);
        int getContagem() const;
        int getPalavra(const string& palavra) const;
        void printPalavras() const;  // Adicionado aqui

     private:
        unordered_map<string, int> palavras;
};

#endif  // INCLUDE_CONTA_PALAVRAS_HPP_