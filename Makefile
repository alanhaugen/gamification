#############################################################################
# Executable name
#############################################################################

TARGET = lexiblocks

#############################################################################
# Libraries 
#############################################################################

LIBS = \
    -lcore

#############################################################################
# Source and header files
#############################################################################

SOURCES = \
    $(wildcard source/*.cpp)

#############################################################################
# Setup Asset Conditioning Pipeline
#############################################################################

PROJECT_FILES = $(SOURCES) data/project.json

#############################################################################
# Setup build platform rules 
#############################################################################

SOLIDCORE=../solid

include $(SOLIDCORE)/Makefile.rules

#############################################################################
# Build as executable
#############################################################################

debug: bin/$(OUTPUT_DIR)/$(TARGET)$(EXE)
release: bin/$(OUTPUT_DIR)/$(TARGET)$(EXE)

bin/$(OUTPUT_DIR)/$(TARGET)$(EXE): $(DEPS)
