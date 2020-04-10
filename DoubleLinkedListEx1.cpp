#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : Cache {
    public:
    LRUCache(const int& inCapacity) {
        cp = inCapacity;
        head = NULL;
        tail = NULL;
    }
    void set(int k, int v);
    int get(int k);
};

void LRUCache::set(int k, int v) {
    auto it = mp.find(k); 
    if (it == mp.end()) {
        if (mp.size() == 0) {
            head = new Node(k,v);
            tail = head;
        }else if (mp.size() < cp) {
            Node * newNode = new Node(NULL, head, k, v);
            head->prev = newNode;
            head = newNode;
        }else {
            tail->next = head;
            head->prev = tail;

            tail = tail->prev;
            head = head->prev;

            tail->next = NULL;
            head->prev = NULL;

            mp.erase(head->key);
            head->key = k;
            head->value = v;
        }

        mp.insert(make_pair(k,head));
    }
    else {
        Node *foundNode = it->second;

        if (foundNode == head) {
            head->value = v;
        }else if (foundNode == tail) {
            tail->next = head;
            head->prev = tail;

            tail = tail->prev;
            head = head->prev;

            tail->next = NULL;
            head->prev = NULL;

            head->value = v;
        }else {
            foundNode->next->prev=foundNode->prev;
            foundNode->prev->next = foundNode->next;

            foundNode->prev = NULL;
            foundNode->next = head;

            head->prev = foundNode;
            head = head->prev;

            head->value = v;
        }
    }
}
int LRUCache::get(int k){

    int ret = -1;
    auto it = mp.find(k); 
    if (it != mp.end()) {ret = it->second->value;}
    return ret;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
