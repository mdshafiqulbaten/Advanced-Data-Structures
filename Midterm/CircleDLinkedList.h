//CircleDLinkedList.h
#ifndef  CIRCLEDLINKEDLIST_H
#define  CIRCLEDLINKEDLIST_H

#include"DNode.h"



class CircleDLinkedList{
private:

  DNode* cursor;           
  int n; 
  
  void printRecursive(DNode* startNode, DNode* currentNode, bool forward, bool firstCall) const {
        if (empty()) return;

        if (!firstCall && currentNode == startNode)
            return;

        std::cout << currentNode->elem << std::endl;

        if (forward)
            printRecursive(startNode, currentNode->next, forward, false);
        else
            printRecursive(startNode, currentNode->prev, forward, false);
    }
 
public:

  CircleDLinkedList(): cursor(nullptr),n(0)
  {
      
  }     
  ~CircleDLinkedList()
  {
      while(!empty()) remove();
  }    
  bool empty() const
  {
      return cursor == nullptr;
  }      
  int size() const
  {
      return n;
  }        
  void add(const Song& s)
  {
      DNode* newNode = new DNode(s);
        if (cursor == nullptr) 
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            cursor = newNode;
        } else 
        {
            DNode* after = cursor->next;
            newNode->next = after;
            newNode->prev = cursor;
            cursor->next = newNode;
            after->prev = newNode;
            cursor = newNode;
        }
        n++;
  }   
  void remove()
  {
      if (empty()) 
         return;
      DNode* old = cursor;
      if (cursor->next == cursor) 
       {
         cursor = nullptr;
       } else 
       {
            DNode* before = cursor->prev;
            DNode* after = cursor->next;
            before->next = after;
            after->prev = before;
            cursor = after;
        }
        delete old;
        n--;
  }           
  void advance()
  {
      if(!empty()) cursor = cursor -> next;
  }          
  void retreat()
  {
      if(!empty()) cursor = cursor -> prev;
  }          
  Song getCurrentSong() const
  {
      if (cursor == nullptr) return Song();
        return cursor->elem;
  } 
  void print(bool forward = true) const
  {
      if(empty())
      {
          std::cout<< "Playlist is empty!   "<< std::endl;
          return;
      }
      printRecursive(cursor, cursor, forward, true);
  } 
  
  friend class MusicPlayer;
};

#endif