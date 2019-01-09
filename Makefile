CXX = g++
BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release
DEBUG_OBJ_DIR = $(DEBUG_DIR)/obj
RELEASE_OBJ_DIR = $(RELEASE_DIR)/obj
TARGET_NAME = sdl_tutorial

SRC_DIR = src
INCLUDE_DIR = include

INCLUDE_PATHS = -IC:/mingw_dev_lib/sdl_v2_x86/include/SDL2
LIBRARY_PATHS = -LC:/mingw_dev_lib/sdl_v2_x86/lib

# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wl,-subsystem,windows
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

INCLUDE = -Iinclude

_OBJ = main.o game.o
DEBUG_OBJ = $(patsubst %,$(DEBUG_OBJ_DIR)/%,$(_OBJ))
RELEASE_OBJ = $(patsubst %,$(RELEASE_OBJ_DIR)/%,$(_OBJ))

all: debug release

debug: $(DEBUG_OBJ)
	@echo Generating executable with debug flags
	$(CXX) -g -Wall -Wextra -o $(DEBUG_DIR)/$(TARGET_NAME) $^ $(INCLUDE) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

$(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building object files with debug flags
	$(CXX) -c -g -Wall -Wextra -o $@ $< $(INCLUDE) $(INCLUDE_PATHS) $(COMPILER_FLAGS)

release: $(RELEASE_OBJ)
	@echo Generating executable with optimization
	$(CXX) -O3 -mwindows -o $(RELEASE_DIR)/$(TARGET_NAME) $^ $(INCLUDE) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

$(RELEASE_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building object files with optimization
	$(CXX) -c -O3 -o $@ $< $(INCLUDE) $(INCLUDE_PATHS) $(COMPILER_FLAGS)

.PHONY: clean

clean:
	@echo Removing object files
	rm -f $(DEBUG_OBJ_DIR)/*.o
	rm -f $(RELEASE_OBJ_DIR)/*.o
