#include <iostream>

#include "movie.h"
#include "movielist.h"

int main(){
	MovieList movielist = MovieList();

	bool running = true;
	char choice;
	std::cout << "Välkommen till johans film databas!"	<< std::endl;
	while (running){
		std::cout	<< "Meny:"								<< std::endl
					<< "1. Lägg till film"					<< std::endl
					<< "2. Ta bort film"					<< std::endl
					<< "3. Sök efter film"					<< std::endl
					<< "4. Sortera filer efter egenskap"	<< std::endl
					<< "5. Visa filmer"						<< std::endl
					<< "6. Spara databas till fil"			<< std::endl
					<< "7. Läs in databas från fil"			<< std::endl
					<< "q. Avsluta"							<< std::endl
					<< "Vad vill du göra? ";

		std::cin >> choice;

		switch(choice){
			case '1':
				movielist.add(create_movie_dialog());
				break;
			case '2':
				movielist.print();
				int removechoice;
				std::cin.clear(); std::cin.ignore();
				std::cout << "Vilken film vill du ta bort? ";
				std::cin >> removechoice;
				movielist.remove(removechoice);
				break;
			case '5':
				movielist.pprint();
				break;
			case '6':
				if (movielist.write_to_file())
					std::cout << "Filmdatabasen sparades" << std::endl;
				else
					std::cout << "Filmdatabasen kunde inte sparas" << std::endl;
				break;
			case '7':
				if (movielist.load_from_file())
					std::cout << "Filmdatabas laddad" << std::endl;
				else
					std::cout << "Filmdatabasen kunde inte laddas" << std::endl;
				break;
			case 'q':
				running=false;
				break;
			default:
				std::cout << "Funktionen är inte implementerad än!" << std::endl;
		}
	}
	return 0;
}