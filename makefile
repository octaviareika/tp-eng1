# Diretórios
SRC_DIR = src
UNIT_TEST_DIR = test/unit
FUNC_TEST_DIR = test/funcional
BIN_DIR = bin

# Compilador e flags
CC = g++
CFLAGS = -Wall -Wextra -I$(SRC_DIR)

# Arquivos fonte e objetos
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))

UNIT_FILES = $(wildcard $(UNIT_TEST_DIR)/*.cpp)
UNIT_OBJS = $(patsubst $(UNIT_TEST_DIR)/%.cpp, $(BIN_DIR)/unit_%.o, $(UNIT_FILES))

FUNC_FILES = $(wildcard $(FUNC_TEST_DIR)/*.cpp)
FUNC_OBJS = $(patsubst $(FUNC_TEST_DIR)/%.cpp, $(BIN_DIR)/funcional_%.o, $(FUNC_FILES))

# Target padrão
all: $(BIN_DIR)/unit_tests $(BIN_DIR)/funcional_tests

# Compilando binários
$(BIN_DIR)/unit_tests: $(SRC_OBJS) $(UNIT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/funcional_tests: $(SRC_OBJS) $(FUNC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilando objetos das fontes
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/unit_%.o: $(UNIT_TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/funcional_%.o: $(FUNC_TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/unit_tests $(BIN_DIR)/funcional_tests