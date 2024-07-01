#include "Vigenere/vigenere.hpp"


int main() {
  while (true) {
    std::cout << "****** Menu ****" << std::endl;
    std::cout << "1.Chiffrement de Cesard" << std::endl;
    std::cout << "2.Chiffrement de Vigenere" << std::endl;
    std::cout << "3.Quitter" << std::endl;
    std::cout << "\t >";
    int choix = 0;
    std::cin >> choix;
    std::cin.ignore(); 
    int sous_choix = 0;
    switch (choix) {
    case 1:
      std::cout << "1.Chiffrer" << std::endl;
      std::cout << "2.Dechiffrer" << std::endl;
      std::cout << "\t >";
      std::cin >> sous_choix;
      std::cin.ignore(); 
      if (sous_choix == 1) {
          Crypt A1;
          A1.introduction();
          A1.encrypt();
          A1.display();
          A1.decrypt();
          A1.display();
      }
      else if (sous_choix == 2)
      {
          Crypt A1;
          A1.introduction();
          A1.decrypt();
          A1.display();
      }
      break;

    case 2:
      std::cout << "1.Chiffrer" << std::endl;
      std::cout << "2.Dechiffrer" << std::endl;
      std::cout << "\t >";
      std::cin >> sous_choix;
      std::cin.ignore(); 
      if (sous_choix == 1) {
          Vigenere A2;
          A2.introduction();
          A2.encrypt();
          A2.display();
          A2.decrypt();
          A2.display();
      }
      else if (sous_choix == 2)
      {
          Vigenere A2;
          A2.introduction();
          A2.decrypt();
          A2.display();
      }
      break;

    case 3:
      std::cout << "Bye Bye o_0 !" << std::endl;
      return 0;
    default:
      break;
    }
  }
  return 0;
}
