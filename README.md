# Trabalho 2 - Métodos de Programação

## Descrição do Projeto
Este projeto implementa um programa capaz de processar arquivos de texto e realizar a contagem de palavras presentes neles. Ele também exibe as palavras em ordem alfabética, juntamente com a frequência de ocorrência, considerando diversos cenários como palavras com caracteres especiais, apóstrofes, e números misturados. O desenvolvimento seguiu os princípios de TDD (Desenvolvimento Orientado a Testes), garantindo robustez e precisão no resultado final.

## Funcionalidades
- Contagem de Palavras: Conta a frequência de cada palavra em arquivos de texto.
- Diferenciação de Maiúsculas e Minúsculas: Trata palavras como “Texto” e “texto” como distintas.
- Ignora Números e Símbolos Inválidos: Apenas palavras são consideradas na contagem.
- Suporte a Diferentes Caracteres: Inclui palavras com acentos, apóstrofes e caracteres Unicode.
- Suporte a Vários Delimitadores: Considera espaços, quebras de linha, e outros delimitadores.
- Ordenação Alfabética: Exibe as palavras em ordem alfabética (com remoção de acentos para efeito de ordenação).

## Tecnologias Utilizadas
- **C++**: Linguagem principal para a implementação do programa.
- **Catch2**: Framework para testes.
- **Doxygen**: Ferramenta para documentação do código.
- **GCOV**: Ferramenta para análise de cobertura de código.
- **CPPCheck**: Ferramenta para análise estática de código.
- **CPPLint**: Ferramenta para verificação de estilo de código.
- **Make**: Gerenciamento de compilação e execução de testes.

## Como Rodar o Projeto

1. **Clonar o Repositório**
   ```bash
   git clone <https://github.com/gabrielcaixeta01/TDD_conta_palavras>
   cd TDD_conta_palavras
   ```

2. **Compilar o Projeto**  
   Utilize o comando abaixo para compilar os arquivos do programa:
   ```bash
   make
   ```

3. **Executar os Testes**  
   Para rodar os testes automatizados e verificar a cobertura das funcionalidades:
   ```bash
   make test
   ```

4. **Limpar os Arquivos Compilados**  
   Caso deseje limpar os arquivos gerados durante a compilação:
   ```bash
   make clean
   ```

## Estrutura do Projeto 
- src/: Contém os arquivos fonte do projeto.
- include/: Contém os cabeçalhos (.hpp) utilizados.
- tests/: Inclui os arquivos de testes unitários com o framework Catch2.
- data/: Contém os arquivos de texto utilizados como exemplos para testes.
- html/: Diretório gerado pelo Doxygen com a documentação do projeto.
- Makefile: Script para automação das tarefas de compilação, testes e geração de documentação.

## Desenvolvedor
- Gabriel Caixeta Romero (https://www.linkedin.com/in/gabriel-caixeta-romero/)


