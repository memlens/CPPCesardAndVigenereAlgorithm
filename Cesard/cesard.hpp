#ifndef __CRYPT__

#define __CRYPT__

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>


class Crypt{

  public:
    Crypt();

    // Affiche la chaîne actuelle
    virtual void display();

    // Chiffre la chaîne entière
    virtual void encrypt();

    // Chiffre un seul caractère
    char encryptCharacter(char character, int shift);

    // Déchiffre la chaîne entière
    virtual void decrypt();

    // Déchiffre un seul caractère
    char decryptCharacter(char character, int shift);

    // Affiche une introduction et récupère les entrées de l'utilisateur
    virtual void introduction();


    protected :

    // Vérifie si le caractère doit être ignoré pendant le chiffrement/déchiffrement
    bool isIgnorableCharacter(char character);

    // Les caractères à ignorer
    std::vector<char> ignorableCharacters{' ', '\'', '_', '{', '}', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // La chaîne à chiffrer ou déchiffrer
    std::string chainToCrypt;

    // Le nombre de rotations pour le chiffrement
    int shift;

	};
#endif
