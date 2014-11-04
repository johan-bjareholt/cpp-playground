#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <vector>
#include <map>

class Song;

class Artist {
	std::string name;
	std::vector<Song*> songs;
public:
	Artist(std::string);
	std::string get_name();
	void add_song(Song*);
	void pprint();
};

extern std::map<std::string, Artist*> artists;

Artist* get_artist(std::string name);

#include "song.h"

#endif