# Nom du programme
PROGRAM = esme-pwm-gpio12

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Répertoire d'installation par défaut
INSTALL_DIR ?= ./.install

# Liste des fichiers sources
SOURCES = pwm_control.c
OBJECTS = $(SOURCES:.c=.o)

# Cible par défaut
all: $(PROGRAM)

# Règle implicite pour créer l'exécutable
$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Installation
install: $(PROGRAM)
	mkdir -p $(INSTALL_DIR)
	cp $(PROGRAM) $(INSTALL_DIR)

# Nettoyage des fichiers générés
clean:
	rm -f $(PROGRAM) $(OBJECTS)

.PHONY: all clean install
