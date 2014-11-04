#include "artist.h"

std::map<std::string, Artist*> artists;

Artist::Artist (std::string name) {
	this->name = name;
}

std::string Artist::get_name(){
	return name;
}

void Artist::add_song(Song* song){
	songs.push_back(song);
}

void Artist::pprint(){
	std::cout << name << std::endl;
	std::cout << "Songs: " << std::endl;
	for (auto songit = songs.begin(); songit != songs.end(); songit++){
		Song* song = (*songit);
		std::cout << "\t";
		song->pprint();
	}
}


Artist* get_artist(std::string name){
	Artist* artist;

	auto it = artists.find(name);
	
	if (it == artists.end()){
		artists[name] = new Artist(name);
	}
	artist = artists.find(name)->second;

	return artist;
}