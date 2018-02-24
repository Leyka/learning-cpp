#include <iostream>

using namespace std;

struct Node {
  int id;
  string message;
  Node* next;

  Node(int id, string message) {
    this->id = id;
    this->message = message;
    this->next = nullptr;
  }
};

struct LinkedList {
  int currentId;
  Node* head;
  
  LinkedList() {
    currentId = 0;
    head = nullptr;
  }

  void addNode(string message) {
    currentId++;
    if(!head) {
      head = new Node(currentId, message);
    } else {
      Node* newHead = new Node(currentId, message);
      newHead->next = head;
      head = newHead;
    }
  }

  void removeNode(int id) {
    Node* current = head;

    if(current->id == id) {
      head = current->next;
      delete current;
    } 
    else {
      Node* previous;
      while(current->id != id) {
        previous = current;
        current = current->next;
      }
      previous->next = current->next;
      delete current;
    }
  }

  // Order message ascending [ O(N²) ]
  void sortAsc() {
    Node* current = head;
    while(current != nullptr) {
      Node* explorer = current->next;
      string temp;
      // Basically, I'll have an explorer cursor that will loop through the list
      // and check if it finds a lower value than the current
      while (explorer != nullptr) {
        if (current->message > explorer->message) {
          // Swap
          temp = current->message;
          current->message = explorer->message;
          explorer->message = temp;
        }
        explorer = explorer->next;
      }
      current = current->next;
    }
  }

  void print() {
    Node *node = head;
    while(node) {
      cout << node->id  << ": " << node->message << endl;
      node = node->next;
    };
  }
};

int main() {
  LinkedList myLinkedList;
  
  myLinkedList.addNode("Hello"); // Id:1
  myLinkedList.addNode("Bonjour"); // Id:2
  myLinkedList.addNode("To be Deleted..."); // Id:3 
  myLinkedList.addNode("The End"); // Id:4
  myLinkedList.print();

  cout << "Deleting node 3.." << endl; 
  myLinkedList.removeNode(3);
  myLinkedList.print();

  cout << "Sorting.." << endl;
  myLinkedList.sortAsc();
  myLinkedList.print();

  return 0;
}