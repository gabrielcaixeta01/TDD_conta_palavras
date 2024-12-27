// Copyright 2024 Gabriel Caixeta Romero

#ifndef INCLUDE_CONTA_PALAVRAS_HPP_
#define INCLUDE_CONTA_PALAVRAS_HPP_

#include <string>
#include <unordered_map>
#include <locale>
#include <vector>

class ContaPalavras {
 public:
    ContaPalavras();
    bool carregarArquivo(const std::string& nomeArquivo);
    int getContagem() const;
    int getPalavra(const std::string& palavra) const;
    void printPalavras() const;

 private:
    std::unordered_map<std::string, int> palavras;
};

#endif  // INCLUDE_CONTA_PALAVRAS_HPP_
