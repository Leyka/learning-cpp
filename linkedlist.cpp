#include <iostream>

using namespace std;

class Node {
  public:
    string message;
    Node* next;

    Node(string msg) {
      message = msg;
      next = nullptr;
    }
};

// TODO : Remove Node, Sort
class LinkedList {
  public:
    Node* head;
    
    LinkedList() {
      head = nullptr;
    }

    void addNode(string message) {
      if(!head) {
        head = new Node(message);
      } else {
        Node* newHead = new Node(message);
        newHead->next = head;
        head = newHead;
      }
    }

    void print() {
      Node* node = head;
      while(node) {
        cout << node->message << endl;
        node = node->next;
      };
    }
};

int main() {
  LinkedList myLinkedList;
  myLinkedList.addNode("Hello");
  myLinkedList.addNode("Bonjour");
  myLinkedList.print(); // head->next->next->message would be "Hello"

  return 0;
}