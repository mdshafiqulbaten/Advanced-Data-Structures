//DNode.h
#ifndef  DNODE_H
#define  DNODE_H

#include "Song.h"


class DNode{
    
private:
  Song elem;               
  DNode* next;             
  DNode* prev;             
  DNode(const Song& s, DNode* p = nullptr, DNode* n = nullptr): elem(s),next(n), prev(p)  
  {
        activeNodes++;
  }
  ~DNode() 
  {
        activeNodes--;
  }
  friend class CircleDLinkedList;
  
public:
  static int activeNodes;   
  
                            

};

#endif