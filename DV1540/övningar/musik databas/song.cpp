#include "song.h"

Song::Song (std::string title, std::string artist){
	this->title = title;
	this->artist = get_artist(artist);
	this->artist->add_song(this);
}

void Song::pprint(){
	std::cout << title << " - " << artist->get_name() << std::endl;
}
