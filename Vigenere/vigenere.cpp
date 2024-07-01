#include "vigenere.hpp"

Vigenere::Vigenere() {}

void Vigenere::introduction() {
    std::cout << "Welcome! This is a Vigenere cipher.\n";
    std::cout << "Please enter some content for encryption:\n\t";
    std::getline(std::cin, this->chainToCrypt);
    std::cout << "Now enter the key you desire:\n\t";
    std::getline(std::cin, this->key);
}

void Vigenere::encrypt() {
    int keyLength = key.size();
    for (size_t i = 0; i < chainToCrypt.size(); i++) {
        int shift = (key[i % keyLength] - 'a');
        chainToCrypt[i] = encryptCharacter(chainToCrypt[i], shift);
    }
}

void Vigenere::decrypt() {
    int keyLength = key.size();
    for (size_t i = 0; i < chainToCrypt.size(); i++) {
        int shift = (key[i % keyLength] - 'a');
        chainToCrypt[i] = decryptCharacter(chainToCrypt[i], shift);
    }
}
