CXX = g++
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TARGET_NAME = sdl_tutorial

SRC_DIR = src
INCLUDE_DIR = include

INCLUDE_PATHS = -IC:\mingw_dev_lib\sdl_v2_x86\include\SDL2
LIBRARY_PATHS = -LC:\mingw_dev_lib\sdl_v2_x86\lib

# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wl,-subsystem,windows
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

_INCLUDE = constants.hpp
INCLUDE = $(patsubst %,$(INCLUDE_DIR)/%,$(_INCLUDE))

_OBJ = main.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
	@echo Building object files
	$(CXX) -c -o $@ $< $(INCLUDE_PATHS) $(COMPILER_FLAGS)

debug: $(OBJ)
	@echo Generating executable with debug flags
	$(CXX) -g -o $(BUILD_DIR)/$(TARGET_NAME) $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

release: $(OBJ)
	@echo Generating executable without debug flags
	$(CXX) -o $(BUILD_DIR)/$(TARGET_NAME) $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

.PHONY: clean

clean:
	@echo Removing object files
	rm -f $(OBJ_DIR)/*.o
