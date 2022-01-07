PROJECT := key_finder
SRC_DIR := src/
BUILD_DIR := build/
BIN_DIR := bin/
# Un uso delle wildcard è ottenere un elenco di tutti i file sorgente C
# in una directory, come qui
SRC := $(wildcard $(SRC_DIR)*.c)
# Aggiunta di una regola
OBJ := $(SRC:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
CC := gcc
LD := gcc
CFLAGS := -I include/
MKDIR := mkdir --parents build

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	@echo $< -> $@
	$(CC) $(THREADS_FLAG) $(CFLAGS) -c $< -o $@

$(PROJECT): $(OBJ)
	@echo Linking $(PROJECT)
	$(LD) $(THREADS_FLAG) $(LDFLAGS) $(OBJ) -o $(BUILD_DIR)$(PROJECT)

all: $(PROJECT)

$(BUILD_DIR):
	$(MKDIR) $@

install:
	$(MKDIR) $(BIN_DIR)
	cp $(BUILD_DIR)$(PROJECT) $(BIN_DIR)

doc:
	@echo "Generating doc"
	doxygen doxygen.cfg

# "Target specific"
threads: THREADS_FLAG := -D THREADS -pthread
threads: all

help:
	@echo "all: Compila il programma"
	@echo "clean: Rimuovi i file oggetto"
	@echo "doc: Genera la documentazione"
	@echo "install: Copia l'eseguibile nella cartella /bin"
	@echo "threads: Compila il codice usando le threads"

clean:
	@echo Clean
	rm -f $(OBJ) $(BUILD_DIR)$(PROJECT)

# Target che NON vanno associare ai file
.PHONY: all clean doc help install threads
