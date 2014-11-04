#include "movie.h"
#include "movielist.h"

/*
	Movie list class
*/

void MovieList::add(Movie* movie){
	this->movies.push_back(movie);
}

void MovieList::remove(int i){
	this->movies.erase(movies.begin()+i);
}

void MovieList::print(){
	for (int n=0; n<movies.size(); n++)
		std::cout << "Film " << n << ": " << movies[n]->name << std::endl;
	std::cout << std::endl;	
}

void MovieList::pprint(){
	for (int n=0; n<movies.size(); n++)
		std::cout 	<< "Film " << n 	<< std::endl
					<< "\t" << movies[n]->name 	<< std::endl
					<< "\t" << movies[n]->genre << std::endl
					<< "\t" << movies[n]->rating << std::endl;
	std::cout << std::endl;
}

template <typename T>
void MovieList::sort(){

}



bool MovieList::write_to_file(){
	std::ofstream file;
	file.open("movies.txt");
	if (file){
		for (int n=0; n<movies.size(); n++){
			file << movies[n]->name << "," << movies[n]->genre << "," << movies[n]->rating << '\n';
		}
		return true;
	}
	return false;
}

bool MovieList::load_from_file(){
	std::ifstream file;
	file.open("movies.txt");
	if (file){
		while (file.good()){
			std::string rawmovieinfo;
			std::getline(file, rawmovieinfo);

			std::string name, genre, rating;

			int n = 0;
			for (int cat=0; cat<2; cat++){
				while( rawmovieinfo[n] != ',' ){
					switch (cat){
						case 0:
							name.push_back(rawmovieinfo[n]);
							break;
						case 1:
							genre.push_back(rawmovieinfo[n]);
							break;
					}
					n++;
				}
				n++;
			}
			rating.push_back(rawmovieinfo[n]);

			this->add(new Movie(name, genre, rating.c_str()[0]-'0'));
		}
		file.close();
		return true;
	}
	file.close();
	return false;
}



