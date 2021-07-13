CC := g++
STD := c++17
CFLAGS := -Wall -Wextra -std=$(STD)
SOURCE_EXT := cpp

TARGET_NAME := text-justifier
BUILD_PATH := ./build
SOURCE_PATH := ./src
LIB_PATH := ./include

SAMPLE_INPUT := ./input/01.in
VALGRIND_OUTPUT := ./output/mem.log

TARGET_PATH=$(BUILD_PATH)/$(TARGET_NAME)

SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.$(SOURCE_EXT) $(LIB_PATH)/%.hpp
	mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.$(SOURCE_EXT)
	$(CC) $(CFLAGS) -o $(TARGET_PATH) ./main.$(SOURCE_EXT) $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*

run:
	$(TARGET_PATH) < $(SAMPLE_INPUT)
	
mem:
	valgrind --leak-check=full --show-leak-kinds=all --log-file="$(VALGRIND_OUTPUT)" $(TARGET_PATH) < $(SAMPLE_INPUT)