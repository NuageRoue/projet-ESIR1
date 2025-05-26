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

# Répertoires à exclure
EXCLUDE_DIRS = $(SRC_DIR)/combat 

# Tous les fichiers .cpp
ALL_SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')

# Supprimer les fichiers qui sont dans les dossiers exclus
EXCLUDED_SOURCES = $(foreach dir,$(EXCLUDE_DIRS),$(shell find $(dir) -name '*.cpp'))
SOURCES = $(filter-out $(EXCLUDED_SOURCES),$(ALL_SOURCES))

# Chemins objets (dans build/bin)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Cibles par défaut
all: debug

# Lien final (debug)
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
