#ifndef __CRYPT__

#define __CRYPT__

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>  // For std::isdigit
#include <cstdlib>  // For exit


	class Crypt{

		public :
		//constructeur Pour l'algorithme de chiffrement de cesard
			Crypt();
		//Affiche la chaine peut etre utilisé avant ou après le chiffrement
			virtual void display();

		//Fonction test pour le déchiffrement, PS: incomplet pour certaines rotations
			virtual void decrypt();

		//Fonction un peux plus fonctionnelle basé sur les corespondances entre les decimaux et les caractères de la table ASCII
		//Décode toute la chaine en une fois
			virtual void decrypt2();

		//Module de la fonction decrypt2
		//Décoode caractère par caractère
			char decrypt3(char charOfchainToCrypt, int shifter);

		//Controle le décodage de toute la chaine en faisant appel à la fonction decrypt3 pour chaque caractère
			void decrypt4();

		//Affiche un message
			virtual void Introduction();

		//Fonction test pour le chiffrement, PS: incomplet pour certaines rotations
			virtual void encrypt();

		//Fonction un peux plus fonctionnelle basé sur les corespondances entre les decimaux et les caractères de la table ASCII
		//Code toute la chaine en une fois
			virtual void encrypt2();


		//Module de la fonction decrypt2
		//Décoode caractère par caractère
			char encrypt3(char charOfchainToCrypt, int shifter);

		//Controle le codage de toute la chaine en faisant appel à la fonction decrypt3 pour chaque caractère
			void encrypt4();

		//Vérifie si le caractère à coder est dans la liste des caractère à coder ou pas
			bool matchChar(char charactere);

		protected :
		//Les caractères à ignoere lors du chiffrement et du dechiffrement
			char lesCaractres[15] = {' ', '\'', '_', '{', '}', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
		//Variable pour stocker la chaine de caractère
			std::string chainToCrypt;
		//Variable pour indiquer le nombre de rotation
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
