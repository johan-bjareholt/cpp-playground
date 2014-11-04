#include "movie.h"

/*
	Movie class
*/

Movie::Movie(std::string name, std::string genre, int rating){
	this->name = name;
	this->genre = genre;
	rate(rating);
}

void Movie::rate(short rating){
	if (rating > 0 && rating <= 5){
		this->rating = rating;
	}
}



/*
	Helper functions
*/

Movie* create_movie_dialog(){
	std::string name, genre;

	std::cin.clear();std::cin.ignore();
	std::cout << "Name:";
	std::getline(std::cin, name);
	std::cout << "Genre:";
	std::getline(std::cin, genre);

	return new Movie(name, genre, 0);
}