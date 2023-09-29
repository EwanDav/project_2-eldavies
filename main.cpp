//
// Ewan Davies
// CS2240OL1
// Project 1
// Created by davie on 9/10/2023.
//

#include <vector>
#include <iostream>
#include "Song.h"
#include "Queue.h"
#include "Stack.h"

int main() {
    Song song;

    std::vector<Song> songs;
    std::string fn = "../top1000_songs.tsv";//used tsv file because some songs have
    //commas in their title/album
    if (song.readFile(fn, songs)) {
        std::cout << songs.size() << " records read from file\n" << std::endl;

        Queue<int> intQueue;
        Queue<std::string> strQueue;

        if(intQueue.isEmpty() == true){
            std::cout << "starting intQueue is empty!" << std::endl;
        }
        else{
            std::cout << "ooooohhh nooo its got something..." << std::endl;
        }
        intQueue.enqueue(5);
        intQueue.enqueue(10);
        intQueue.enqueue(15);
        intQueue.print();
        if(intQueue.isEmpty() == true){
            std::cout << "empty? somethings wrong" << std::endl;
        }
        else{
            std::cout << "Weve enqued some stuff so isEmpty = false!"<< std::endl;
        }
        intQueue.dequeue();
        intQueue.print();
        if(intQueue.find(5) == 0){
            std::cout << "intQueue.find(5) returns false because we dequed the first element, 5" << std::endl;
        }
        else{
            std::cout << "oh 5 shouldnt still be here..." << std::endl;
        }
        if(intQueue.find(10) == 1){
            std::cout << "find(10) = true because its now at the front of the queue" << std::endl;
        }
        else{
            std::cout << "bad, we should see 10" << std::endl;
        }
        intQueue.enqueue(115);
        std::cout << "after enqueuing 115:" << std::endl;
        intQueue.print();

        //now testing queue with strings
        //just with asserts this time because it's basically the same thing
        std::cout << "\n\nNow for strQueue:" << std::endl;
        assert(strQueue.isEmpty() == 1);
        strQueue.enqueue("boop");
        strQueue.enqueue("beep");
        strQueue.enqueue("bop");
        strQueue.print();
        strQueue.dequeue();
        strQueue.print();
        strQueue.enqueue("hello");
        strQueue.print();
        assert(strQueue.find("hello") == 1);
        assert(strQueue.isEmpty() == 0);
        std::cout << "\n\n\n" << std::endl;

        Queue<Song> songQueue;
        Stack<Song> songStack;
        //printing and enqueing the first 10 songs
        for (int i = 0; i < 10; ++i) {
            const Song& songToEnqueue = songs[i];
            std::cout << songToEnqueue << "\n" << std::endl;
            songQueue.enqueue(songToEnqueue);
        }
        assert(songQueue.isEmpty() == false);
        //dequeuing the first 10 songs
        for (int i = 0; i < 10; ++i) {
            const Song& songToPush = songQueue.dequeue();
            songStack.push(songToPush);
        }
        for (int i = 0; i < 10; ++i) {
            const Song& songToPrint = songStack.pop();
            std::cout << songToPrint << std::endl;
        }

    }
    else{
        std::cout << "error reading from file:" << fn << std::endl;
    }


//  repurposing old cpp file, only commenting out in case I need to use this code later
//
//    //just a function with asserts to test getters and setters
//    song.testTimeWoo();
//
//    //takes a rank and prints all the data on that track
//    for (Song &song: songs){
//        if (song.getId() == 44){
//            std::cout <<song<< std::endl;
//        }
//    }
//    //test the findNumSongs function to
//    // print the number of songs in the vector in a given decade
//    int newDecade = 1960;
//    std::cout<<"In the decade "<<newDecade<<" there were " << song.findNumSongs(songs, newDecade)<<" songs on the list"<<std::endl;
//    newDecade = 1950;
//    std::cout<<"In the decade "<<newDecade<<" there were " << song.findNumSongs(songs, newDecade)<<" songs on the list"<<std::endl;
//    //if a specific decade is not given it will show 0
//    newDecade = 1928;
//    std::cout<<"In the decade "<<newDecade<<" there were " << song.findNumSongs(songs, newDecade)<<" songs on the list"<<std::endl;

}
