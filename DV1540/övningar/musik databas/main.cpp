#include <iostream>
#include <string>

#include "song.h"
#include "artist.h"


std::string ask(std::string question){
	std::string answer;
	std::cout << question;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, answer);
	return answer;
}


int main(){
	bool running = true;

	Song mysong = Song("poop", "foo");
	Song mysong1 = Song("poop2", "foo");
	Song mysong2 = Song("poop3", "foo");
	Song mysong3 = Song("poop wannabe", "chris");
	mysong.pprint();
	get_artist("foo")->pprint();


	while (running){
		std::cout 	<< "1. Get artist info" << std::endl
					<< "2. Get song info" << std::endl
					<< "q. Quit" << std::endl;

		char choice;
		std::string artist;

		std::cout << "What would you like to do? ";
		std::cin >> choice;
		switch (choice){
			case '1':
				artist = ask("Which artist would you like to get information about? ");
				get_artist(artist)->pprint();
				break;
			case '2':
				break;
			case '3':
				break;
			case 'q':
				running = false;
				break;
			default:
				std::cout << "Invalid choice";
				break;
		}
	}
}