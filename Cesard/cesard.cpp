#include "cesard.hpp"

Crypt::Crypt() : shift(0) {}

void Crypt::introduction() {
    std::cout << "Welcome! This is a simple Caesar cipher based on the ASCII table.\n";
    std::cout << "Please enter some content for encryption:\n\t";
    std::getline(std::cin, this->chainToCrypt);
    std::cout << "Now enter the shift value you desire:\n\t";
    std::cin >> this->shift;
    this->shift %= 26;
    std::cin.ignore();  // Ignore leftover newline character from std::cin
}

void Crypt::display() {
    std::cout << this->chainToCrypt << std::endl;
}

void Crypt::encrypt() {
    for (char& c : chainToCrypt) {
        c = encryptCharacter(c, shift);
    }
}

char Crypt::encryptCharacter(char character, int shift) {
    if (isIgnorableCharacter(character)) {
        return character;
    }

    if (std::isupper(character)) {
        character = (character - 'A' + shift) % 26 + 'A';
    } else if (std::islower(character)) {
        character = (character - 'a' + shift) % 26 + 'a';
    }

    return character;
}

void Crypt::decrypt() {
    for (char& c : chainToCrypt) {
        c = decryptCharacter(c, shift);
    }
}

char Crypt::decryptCharacter(char character, int shift) {
    if (isIgnorableCharacter(character)) {
        return character;
    }

    if (std::isupper(character)) {
        character = (character - 'A' - shift + 26) % 26 + 'A';
    } else if (std::islower(character)) {
        character = (character - 'a' - shift + 26) % 26 + 'a';
    }

    return character;
}

bool Crypt::isIgnorableCharacter(char character) {
    return std::find(ignorableCharacters.begin(), ignorableCharacters.end(), character) != ignorableCharacters.end();
}
