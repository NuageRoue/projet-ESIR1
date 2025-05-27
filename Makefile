# Compilateur et options
CXX = g++
CXXFLAGS_BASE = -pedantic -Wnull-dereference -Wall -Wextra -std=c++11 -ggdb -g
PKG_CFLAGS = `pkg-config --cflags sdl2 SDL2_ttf SDL2_gfx SDL2_image`
PKG_LIBS = `pkg-config --libs sdl2 SDL2_ttf SDL2_gfx SDL2_image`

CXXFLAGS_DEBUG = $(CXXFLAGS_BASE) $(PKG_CFLAGS) -I./include
CXXFLAGS_GUI   = $(CXXFLAGS_BASE) $(PKG_CFLAGS) -I./include -I./imgui
LDFLAGS = $(PKG_LIBS)

# Répertoires
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build/bin
BIN_DIR = build
EXEC = $(BIN_DIR)/jeu
EXEC_GUI = $(BIN_DIR)/jeu_gui

# Tous les fichiers .cpp dans src/
ALL_SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')

### Exclusions pour debug
DEBUG_EXCLUDE_DIRS = $(SRC_DIR)/combat
DEBUG_EXCLUDE_FILES = $(SRC_DIR)/mainC.cpp $(SRC_DIR)/mainM.cpp
DEBUG_EXCLUDED_FROM_DIRS = $(foreach dir,$(DEBUG_EXCLUDE_DIRS),$(shell find $(dir) -name '*.cpp'))
DEBUG_EXCLUDED_SOURCES = $(DEBUG_EXCLUDE_FILES) $(DEBUG_EXCLUDED_FROM_DIRS)
DEBUG_SOURCES = $(filter-out $(DEBUG_EXCLUDED_SOURCES), $(ALL_SOURCES))
DEBUG_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(DEBUG_SOURCES))

### Exclusions pour gui
GUI_EXCLUDE_DIRS = 
GUI_EXCLUDE_FILES = $(SRC_DIR)/mainC.cpp $(SRC_DIR)/mainM.cpp
GUI_EXCLUDED_FROM_DIRS = $(foreach dir,$(GUI_EXCLUDE_DIRS),$(shell find $(dir) -name '*.cpp'))
GUI_EXCLUDED_SOURCES = $(GUI_EXCLUDE_FILES) $(GUI_EXCLUDED_FROM_DIRS)
GUI_SOURCES = $(filter-out $(GUI_EXCLUDED_SOURCES), $(ALL_SOURCES))
GUI_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(GUI_SOURCES))

# Fichiers ImGui
IMGUI_SRC = imgui/imgui.cpp \
            imgui/imgui_draw.cpp \
            imgui/imgui_tables.cpp \
            imgui/imgui_widgets.cpp \
            imgui/backends/imgui_impl_sdl2.cpp \
            imgui/backends/imgui_impl_sdlrenderer2.cpp
IMGUI_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(IMGUI_SRC))

# Cible par défaut
all: debug

# Debug = sans ImGui
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(EXEC)

$(EXEC): $(DEBUG_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# GUI = avec ImGui
gui: CXXFLAGS = $(CXXFLAGS_GUI)
gui: $(EXEC_GUI)

$(EXEC_GUI): $(GUI_OBJECTS) $(IMGUI_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compilation pour src/ fichiers
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation pour ImGui
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(EXEC) $(EXEC_GUI)

.PHONY: all clean debug gui
