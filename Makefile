# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2
#LDFLAGS = 
EXEC = prog
SRC = main.cpp Cesard/cesard.cpp Vigenere/vigenere.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Cesard/cesard.hpp Vigenere/vigenere.hpp

# Règle par défaut pour construire le programme
all: $(EXEC)

# Règle pour lier l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Règle pour compiler les fichiers objets
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour nettoyer tout, y compris les fichiers générés
dist-clean: clean

# Règles pour forcer le recompilation des fichiers spécifiques (optionnel)
.PHONY: all clean dist-clean
