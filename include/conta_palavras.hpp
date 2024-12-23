// Copyright 2024 Gabriel Caixeta Romero

#ifndef INCLUDE_CONTA_PALAVRAS_HPP_
#define INCLUDE_CONTA_PALAVRAS_HPP_

#include <string>

class ContaPalavras {
    public:
        ContaPalavras();
        bool carregarArquivo(const std::string& nomeArquivo);
};

#endif  // INCLUDE_CONTA_PALAVRAS_HPP_
