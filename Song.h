//
// Ewan Davies
// CS2240OL1
// Project 1
// Created by davie on 9/10/2023.
//

#ifndef WEEK2_SONG_H
#define WEEK2_SONG_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>

class Song {
private:
    std::string trackName;
    std::string artist;
    std::string album;
    int decade;
    int id;
public:
    //default constructor
    Song(){
        id = 0;
        trackName = "PLACEHOLDER_SONG";
        artist = "NOBODY";
        album = "THE_INCREDIBLE_WORKS_OF_NO_ONE";
        decade = 0;
    }

    Song(int id, std::string trackName, std::string artist, std::string album, int decade){
        this->id = id;
        this->trackName = trackName;
        this->artist = artist;
        this->album = album;
        this->decade = decade;
    }
    //SETTERS
    //setter for trackName
    void setName(std::string trackName){
        this -> trackName = trackName;
    }
    //setter for artist
    void setArtist(std::string artist){
        this -> artist = artist;
    }
    //setter for album
    void setAlbum(std::string album){
        this -> album = album;
    }
    //setter for decade
    void setDecade(int decade){
        this -> decade = decade;
    }
    //setter for id
    void setId(int id){
        this -> id = id;
    }

    //GETTERS
    //getter for trackName
    std::string getName() const {
        return trackName;
    }
    //getter for artist
    std::string getArtist() const {
        return artist;
    }
    //getter for album
    std::string getAlbum() const {
        return album;
    }
    //getter for decade
    int getDecade() const {
        return decade;
    }
    //getter for id
    int getId() const {
        return id;
    }
    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& outs, const Song& song) {
        outs
        <<std::left
        <<std::setw(10) << "id: " << song.id << std::endl
        <<std::setw(9) << "Track: " << song.trackName << std::endl
        <<std::setw(10) << "Artist: " << song.artist << std::endl
        <<std::setw(10) << "Album: " << song.album << std::endl
        <<std::setw(10) << "Decade: " << song.decade << std::endl;
        return outs;
    }
    // Overload the == operator
    bool operator==(const Song& other) const {
        // Compare all the attributes for equality
        return (id == other.id) &&
               (trackName == other.trackName) &&
               (artist == other.artist) &&
               (album == other.album) &&
               (decade == other.decade);
    }
    // Overload the < operator
    bool operator < (const Song& other) const {
        if(id < other.id){
            return true;
        }
        return false;
    }
    // Overload the > operator
    bool operator > (const Song& other) const {
        if(id > other.id){
            return true;
        }
        return false;
    }
    // Overload the <= operator
    bool operator <= (const Song& other) const {
        if(id <= other.id){
            return true;
        }
        return false;
    }
    // Overload the >= operator
    bool operator >= (const Song& other) const {
        if(id >= other.id){
            return true;
        }
        return false;
    }
    //reading the file
    bool readFile(std::string fn, std::vector<Song>& objects) {
        std::ifstream fin;
        fin.open(fn);
        if (!fin) {
            std::cout << "Couldn't open file :(" << std::endl;
            return false;
        }

        std::string header;
        getline(fin, header);  // Read and discard the header line

        int counter = 1;
        while (fin) {
            std::string tab = "\t";
            Song song;

            // Read the id
            fin >> song.id;
            fin >> tab;  // Read the tab after id

            // Read the rest of the fields
            getline(fin, song.trackName, '\t');
            getline(fin, song.artist, '\t');
            getline(fin, song.album, '\t');
            fin >> song.decade;

            objects.push_back(song);
            counter += 1;
        }

        fin.close();
        return true;
    }

    //function to find the number of songs in a decade
    int findNumSongs(const std::vector<Song>& songs, int inputDecade){
        int counter = 0;
        for (const Song& song : songs) {
            if (song.getDecade() == inputDecade) {
                counter += 1;
            }
        }
        return counter;
    }

    //just makes sure all the getters and setters work
    void testTimeWoo(){
        Song testerSong = Song();
        testerSong.setId(1);
        assert(testerSong.getId() == 1);

        testerSong.setName("boots n cats");
        assert(testerSong.getName() == "boots n cats");

        testerSong.setArtist("super cool and sick def real person");
        assert(testerSong.getArtist() == "super cool and sick def real person");

        testerSong.setAlbum("bing bong wong dong");
        assert(testerSong.getAlbum() == "bing bong wong dong");

        testerSong.setDecade(40000);
        assert(testerSong.getDecade() == 40000);
    }

};

#endif //WEEK2_SONG_H
