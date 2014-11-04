#ifndef MOVIE_H
#define MOVIE_H


#include <iostream>


class Movie
{
public:
	std::string name;
	std::string genre;
	short rating = 0;

	Movie(std::string, std::string, int);
	void rate(short);
	
};

Movie* create_movie_dialog();

#endif