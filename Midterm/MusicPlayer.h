//MusicPlayer.h
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include"CircleDLinkedList.h"
#include"Song.h"
#include<string>

class MusicPlayer{
    
private:
  std::string type;             
  CircleDLinkedList playlist;   

public:
  MusicPlayer(std::string t):type(t)
  {
      
  }     
  virtual ~MusicPlayer()
  {
      
  }      
  void play()
  {
      std::cout << "Playing: " << playlist.getCurrentSong() << std::endl;
  }                 
  void next()
  {
      playlist.advance();
      play();
      
  }                 
  void previous()
  {
      playlist.retreat();
        play();
  }             
  void addSong(const Song& s)
  {
      
      playlist.add(s);
  }   
  void removeSong()
  {
      playlist.remove();
      
  }           
  int size() const
  {
      
      return playlist.size();
      
  }            
  bool empty() const
  {
      
      return playlist.empty();
      
  }          
  Song getCurrentSong() const
  {
      
      return playlist.getCurrentSong();
      
  }  
  void print(bool forward) 
  {
        playlist.print(forward);
   }
  
};

#endif
