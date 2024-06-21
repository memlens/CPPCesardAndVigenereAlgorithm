#ifndef __CRYPT__

#define __CRYPT__

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>  // For std::isdigit
#include <cstdlib>  // For exit


	class Crypt{

		public :
			Crypt();

			virtual void display();

			virtual void decrypt();

			virtual void decrypt2();

			char decrypt3(char charOfchainToCrypt, int shifter);

			void decrypt4();

			virtual void Introduction();

			virtual void encrypt();

			virtual void encrypt2();

			char encrypt3(char charOfchainToCrypt, int shifter);

			void encrypt4();

			bool matchChar(char charactere);

		protected :
			char lesCaractres[15] = {' ', '\'', '_', '{', '}', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			std::string chainToCrypt;
			int shifter;
	};

	class Vigenere : public Crypt{
		public :
			Vigenere();

			void encrypt();

			void encrypt2();

			void decrypt();

			void Introduction();

		private :
			std::string key;
	};

#endif
