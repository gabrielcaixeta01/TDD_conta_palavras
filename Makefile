# Defina o compilador e as flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./include -I./libs

# Diretórios de destino dos arquivos .o
BUILD_DIR = build
SRC_OBJ_DIR = $(BUILD_DIR)/src
TEST_OBJ_DIR = $(BUILD_DIR)/tests
LIB_OBJ_DIR = $(BUILD_DIR)/libs

# Regra principal: compila e executa os testes
all: testa_conta_palavras
	./testa_conta_palavras

# Compila o executável principal
testa_conta_palavras: $(SRC_OBJ_DIR)/conta_palavras.o $(TEST_OBJ_DIR)/testa_conta_palavras.o $(LIB_OBJ_DIR)/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) $(SRC_OBJ_DIR)/conta_palavras.o $(TEST_OBJ_DIR)/testa_conta_palavras.o $(LIB_OBJ_DIR)/catch_amalgamated.o -o testa_conta_palavras

# Compila o objeto conta_palavras.o
$(SRC_OBJ_DIR)/conta_palavras.o: src/conta_palavras.cpp include/conta_palavras.hpp
	$(CXX) $(CXXFLAGS) -c src/conta_palavras.cpp -o $(SRC_OBJ_DIR)/conta_palavras.o

# Compila o objeto testa_conta_palavras.o
$(TEST_OBJ_DIR)/testa_conta_palavras.o: tests/testa_conta_palavras.cpp
	$(CXX) $(CXXFLAGS) -c tests/testa_conta_palavras.cpp -o $(TEST_OBJ_DIR)/testa_conta_palavras.o

# Compila o objeto catch_amalgamated.o
$(LIB_OBJ_DIR)/catch_amalgamated.o: libs/catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -c libs/catch_amalgamated.cpp -o $(LIB_OBJ_DIR)/catch_amalgamated.o

# Executa os testes
test: testa_conta_palavras
	./testa_conta_palavras

# Gera a cobertura de código usando gcov
gcov: testa_conta_palavras
	./testa_conta_palavras
	gcov src/conta_palavras.cpp tests/testa_conta_palavras.cpp

# Verificação de erros e avisos com cpplint
cpplint:
	cpplint --exclude=libs/catch_amalgamated.hpp --exclude=libs/catch_amalgamated.cpp tests/testa_conta_palavras.cpp src/conta_palavras.cpp include/conta_palavras.hpp

# Verificação de erros e avisos com cppcheck
cppcheck:
	cppcheck --enable=warning tests/testa_conta_palavras.cpp src/conta_palavras.cpp include/conta_palavras.hpp

# Limpeza de arquivos gerados
clean:
	rm -rf $(BUILD_DIR)/*.o *.gc* *.gcda *.gcno testa_conta_palavras