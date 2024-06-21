#include "cesard.hpp"

Crypt::Crypt(){}

void Crypt::Introduction(){
  std::cout << "Welcome you, I bet you wanna crypt some thing, this is my cypher use it wisely o_O\n" <<std::endl;
  std::cout << "It is based on the ASCII table so we don't manage non-English letters" <<std::endl;
  std::cout << "Tap some content for encryption \n\t";

		std::getline(std::cin, this->chainToCrypt, '\n');

	   std:: cout << "Now enter the shifter you desire : \n \t";

		std::cin>> this->shifter;
    shifter %= 26;
}

void Crypt::display(){
  std::cout<< this->chainToCrypt << std::endl;
}

void Crypt::encrypt(){
  for(int i = 0; i < chainToCrypt.size(); i++){

    if(std::isalpha(chainToCrypt[i])){
      chainToCrypt[i] += shifter;

        if(!std::isalpha(chainToCrypt[i])){
            chainToCrypt[i] -= 26;
        }
    }

    }
}

void Crypt::encrypt2(){
  for(int i = 0; i < chainToCrypt.size(); i++){

    if(matchChar(chainToCrypt[i])){
      if(std::isupper(chainToCrypt[i])){
      chainToCrypt[i] += shifter;

        if(chainToCrypt[i] > 'Z'){
            chainToCrypt[i] -= 26;
        }
    }else{
      int temp = int(chainToCrypt[i]);

      temp += shifter;

      if(temp > 122){
        temp -= 26;
      }
      chainToCrypt[i] = char(temp);
    }
    }
    }
}

char Crypt::encrypt3(char charOfchainToCrypt, int shifter){

      if(matchChar(charOfchainToCrypt)){
        if(std::isupper(charOfchainToCrypt)){
        charOfchainToCrypt += shifter;

          if(charOfchainToCrypt > 'Z'){
              charOfchainToCrypt -= 26;
          }
      }else{
        int temp = int(charOfchainToCrypt);

        temp += shifter;

        if(temp > 122){
          temp -= 26;
        }
        charOfchainToCrypt = char(temp);
        }
      }
      return charOfchainToCrypt;
}

void Crypt::encrypt4(){
  for(int i = 0; i < chainToCrypt.size(); i++){
    chainToCrypt[i] = encrypt3(chainToCrypt[i], shifter);
  }
}

void Crypt::decrypt(){
  for(int i = 0; i < chainToCrypt.size(); i++){

    if(std::isalpha(chainToCrypt[i])){
      chainToCrypt[i] -= shifter;

        if(!std::isalpha(chainToCrypt[i])){
            chainToCrypt[i] += 26;
        }
    }

    }
}

void Crypt::decrypt2(){
  for(int i = 0; i < chainToCrypt.size(); i++){

    if(matchChar(chainToCrypt[i])){
      int temp = int(chainToCrypt[i]);
      
      temp -= shifter;
      if (!std::isupper(chainToCrypt[i]) && temp < 97)
      {
        temp += 26;
      }
      if (std::isupper(chainToCrypt[i]) && temp < 65)
      {
        temp += 26;
      }
      chainToCrypt[i] = char(temp);
    }
    }
}

char Crypt::decrypt3(char charOfchainToCrypt, int shifter){
  if(matchChar(charOfchainToCrypt)){
      int temp = int(charOfchainToCrypt);
      
      temp -= shifter;
    if (!std::isupper(charOfchainToCrypt) && temp < 97)
      {
        temp += 26;
      }
    if (std::isupper(charOfchainToCrypt) && temp < 65)
      {
        temp += 26;
      }
      charOfchainToCrypt = char(temp);
  }
  return charOfchainToCrypt;
}

void Crypt::decrypt4(){
  for(int i = 0; i < chainToCrypt.size(); i++){
    chainToCrypt[i] = decrypt3(chainToCrypt[i], shifter);
  }
}

bool Crypt::matchChar(char charactere){
  for (int i = 0; i < strlen(lesCaractres); i++){
    if(charactere == lesCaractres[i])
      return false;
  }
  return true;
}

/*#
#**************************************************#
#                        VIGENERE                  #
#**************************************************#
#*/

Vigenere::Vigenere(){}

void Vigenere::encrypt(){
  int j = 0;

  for(int i = 0; i < chainToCrypt.size(); i++){

  		shifter = (int(key[j]) - int('a'));

  		if(std::isalpha(chainToCrypt[i])){
  			chainToCrypt[i] += (shifter%26);

  			  if(!std::isalpha(chainToCrypt[i])){
  			  		chainToCrypt[i] -= 26;
  			  }
  		}
  		j++;
  		if(j >= key.size()){
  			j = 0;
  		}

  }

}


void Vigenere::encrypt2(){
  int j = 0;

  for(int i = 0; i < chainToCrypt.size(); i++){

  		shifter = (int(key[j]) - int('a'));

      chainToCrypt[i] = encrypt3(chainToCrypt[i], shifter);

      j++;
  		if(j >= key.size()){
  			j = 0;
  		}

  }

}

void Vigenere::decrypt(){
    int j = 0;

  for(int i = 0; i < chainToCrypt.size(); i++){

  		shifter = (int(key[j]) - int('a'));

      chainToCrypt[i] = decrypt3(chainToCrypt[i], shifter);

      j++;
  		if(j >= key.size()){
  			j = 0;
  		}

  }
}


void Vigenere::Introduction() {
  std::cout << "Welcome you, I bet you wanna crypt some thing, this is my cypher use it wisely o_O" <<std::endl;

	std::cout << "Tap some content for encryption \n\t";

		std::getline(std::cin, this->chainToCrypt, '\n');

  std:: cout << "Now enter the key you desire : \n \t";

		std::getline(std::cin, this->key, '\n');
}
