//main.cpp

#include<iostream>
#include"MusicPlayer.h"

int DNode::activeNodes = 0;

int main(){
    
    MusicPlayer myPlayer("My Player");
    myPlayer.addSong(Song("Song 1 ", "Artist 1"));
    myPlayer.addSong(Song("Song 2 ", "Artist 2"));
    myPlayer.addSong(Song("Song 3 ", "Artist 3"));
    
    std::cout << "\nInitial Playback:\n";
    myPlayer.play(); 
    myPlayer.next(); 
    myPlayer.next();
    myPlayer.next();
    myPlayer.previous();
    
    std::cout << "\nPlaylist Forward:\n";
    myPlayer.print(true);
    std::cout << "\nPlaylist Reverse:\n";
    myPlayer.print(false);
    
    std::cout << "\nRemoving current song...\n";
    myPlayer.removeSong();
    myPlayer.play(); 
    myPlayer.next(); 
    myPlayer.next(); 
    myPlayer.next(); 
    
    std::cout << "\nFinal Playlist Forward:\n";
    myPlayer.print(true);
    std::cout << "\nFinal Playlist Reverse:\n";
    myPlayer.print(false);
    
    
    std::cout<<"\n Active Nodes:  " << DNode::activeNodes << std::endl;
    

    return 0;

    
    
}