#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class Artist;

class Song {
	std::string title;
	Artist* artist;
public:
	Song(std::string, std::string);
	void pprint();
};

#include "artist.h"

#endif