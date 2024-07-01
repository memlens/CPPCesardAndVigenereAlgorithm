#ifndef __VIGENERE__
    #define __VIGENERE__

#include "../Cesard/cesard.hpp"


class Vigenere : public Crypt {
public:
    Vigenere();

    // Surcharger les méthodes d'encryption/décryption
    void encrypt() override;
    void decrypt() override;

    // Introduction spécifique pour la clé de Vigenere
    void introduction() override;

private:
    // La clé de chiffrement
    std::string key;
};

#endif