#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class MovieList{
	std::vector<Movie*> movies;
public:
	// General functions
	void add(Movie*);
	void remove(int);
	void print();
	void pprint();
	// Sorting
	template<typename T>
	void sort();
	// Saving and loading
	bool write_to_file();
	bool load_from_file();
};

#endif