//Song.h
#ifndef  SONG_H
#define  SONG_H

#include<iostream>
#include<string>



class Song{
    
private:
  std::string songTitle;  
  std::string singerName;  

public:
  Song(std::string sTitle = "", std::string sName = ""): songTitle(sTitle),singerName(sName)
  {
      
  }
  ~Song()
  {
      
  }                        
  std::string getSongTitle() const
  {
      return songTitle;
      
  }  
      
  std::string getSingerName()const
  {
      return singerName;
  }     
  
  void setSongTitle(std::string sTitle)
  {
      songTitle=sTitle;
  }  
  
  void setSingerName(std::string sName)
  {
      singerName=sName;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const Song& song)
  {
        os << "\"" << song.songTitle << "\" by " << song.singerName;
        return os;
  }
 
};

#endif