# compilación
CC = g++
CPPFLAGS = -Isrc -std=c++11

# vars
SRC = src
BIN = bin
BUILD = build
NWK = NewickTree
RND = Random
NWKNODE = NewickNode
MAIN = tree_gen_main

.PHONY: all dirs clean

all: dirs $(MAIN)

# 
$(MAIN): $(SRC)/$(MAIN).cpp $(BUILD)/$(RND).o $(BUILD)/$(NWKNODE).o $(SRC)/$(NWK).hpp
	$(CC) $(SRC)/$(MAIN).cpp $(BUILD)/$(RND).o $(BUILD)/$(NWKNODE).o $(SRC)/$(NWK).hpp -o $(BIN)/$(MAIN) $(CPPFLAGS)

$(BUILD)/$(RND).o: $(SRC)/$(RND).hpp $(SRC)/$(RND).cpp
	$(CC) -c $(SRC)/$(RND).cpp -o $(BUILD)/$(RND).o $(CPPFLAGS)

$(BUILD)/$(NWKNODE).o: $(SRC)/$(NWKNODE).hpp $(SRC)/$(NWKNODE).cpp
	$(CC) -c $(SRC)/$(NWKNODE).cpp -o $(BUILD)/$(NWKNODE).o $(CPPFLAGS)

dirs:
	mkdir -p $(BIN) $(BUILD)

clean:
	rm -rfv $(BIN) $(BUILD)