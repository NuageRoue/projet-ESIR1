# Compilateur et options
CXX = g++
CXXFLAGS_DEBUG = -pedantic -Wnull-dereference -Wall -Wextra -std=c++11 -ggdb `pkg-config --cflags sdl2 SDL2_ttf SDL2_gfx SDL2_image` -I./include
LDFLAGS = `pkg-config --libs sdl2 SDL2_ttf SDL2_gfx SDL2_image`

# Répertoires
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build/bin
BIN_DIR = build
EXEC = $(BIN_DIR)/jeu

# Récupération des fichiers source (.cpp) récursivement
SOURCES  = $(shell find $(SRC_DIR) -name '*.cpp')

# Transformation des chemins source -> objets (dans build/bin)
OBJECTS  = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Cibles par défaut (mode debug)
all: debug

# Lien final (mode debug)
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(EXEC)

# Lien final
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compilation individuelle des .cpp vers .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean debug
