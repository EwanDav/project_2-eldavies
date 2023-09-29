//
// Ewan Davies
// CS2240OL1
// Created by davie on 9/27/2023.
//

#ifndef SONG_QUEUE_H
#define SONG_QUEUE_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include "Node.h"

template <typename Object>
class Queue{
private:
    Node <Object>* front;
    Node<Object>* rear;
public:
    //constructor
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    //deconstructor
    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
        rear = nullptr;
    }
    //isEmpty function
    bool isEmpty() const{
        return front == nullptr;
    }
    //enqueue function
    void enqueue(const Object& newItem){
        Node<Object>* newNode = new Node<Object>(newItem, nullptr);
        if (isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->setNext(newNode);
            rear = newNode;
        }
    }
    //dequeue function
    Object dequeue() {
        if (!isEmpty()) {
            // Create a pointer to the front of the queue
            Node<Object>* hold = front;
            Object item = front->getItem();
            front = front->getNext();
            delete hold; // Deallocate the front node
            return item; // Return the dequeued item
        }
        else {
            return Object();
        }
    }
    // find function
    bool find(const Object& hider) const {
        Node<Object>* current = front;
        while (current != nullptr) {
            if (current->getItem() == hider) {
                return true; // Found the item
            }
            current = current->getNext();
        }
        return false;
    }
    //print
    void print() const{
        Node<Object>* current = front;
        while(current != nullptr){
            std::cout << current->getItem() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }

};

#endif //SONG_QUEUE_H
