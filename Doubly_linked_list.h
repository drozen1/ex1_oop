//
// Created by Dor on 04/05/2020.
//

#ifndef EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H
#define EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H

#include "Link_node.h"


namespace AVL {

    using namespace AVLUtils;
    template<class T>
    class Doubly_Linked_List {
    private:
        Link_Node<T>* Head;
        Link_Node<T>* Last;
    public:
        Doubly_Linked_List();

        Doubly_Linked_List(Link_Node<T> *head);

        virtual ~Doubly_Linked_List();

        Link_Node<T> *getHead() const;

        void setHead(Link_Node<T> *head);

        Link_Node<T> *getLast() const;

        void setLast(Link_Node<T> *last);

       void setNewNodeAfterNode(Link_Node<T> *push_after_node,Link_Node<T>* newNode);
    };

    template<class T>
    Doubly_Linked_List<T>::Doubly_Linked_List():Head(NULL),Last(NULL) {

    }

    template<class T>
    Doubly_Linked_List<T>::Doubly_Linked_List(Link_Node<T> *head):Head(head) {}

    template<class T>
    Doubly_Linked_List<T>::~Doubly_Linked_List() {

    }

    template<class T>
    Link_Node<T> *Doubly_Linked_List<T>::getHead() const {
        return Head;
    }

    template<class T>
    void Doubly_Linked_List<T>::setHead(Link_Node<T> *head) {
        Head = head;
    }

    template<class T>
    Link_Node<T> *Doubly_Linked_List<T>::getLast() const {
        return Last;
    }

    template<class T>
    void Doubly_Linked_List<T>::setLast(Link_Node<T> *last) {
        Last = last;
    }

    /**
     * in case node==NULL we want to push in the head
     * @tparam T
     * @param push_after_node
     * @param newNode- the address of the new node..
     */
    template<class T>
    void Doubly_Linked_List<T>::setNewNodeAfterNode(Link_Node<T> *push_after_node,Link_Node<T>* newNode) {
        ///treat head is newNode
        if (push_after_node==NULL){
            if(this->getHead()!=NULL) {
                newNode->setNext(this->getHead());
                if(this->getHead()->getNext()!=NULL) {
                    this->getHead()->getNext()->setPrev(newNode);
                }
            }
            else{
                setLast(newNode);
            }
            this->setHead(newNode);
            return;

        }
        ///treat last
        if (push_after_node->getNum()==getLast()->getNum()){
            push_after_node->setNext(newNode);
            setLast(newNode);
            newNode->setPrev(push_after_node);
            return;
        }
        ///treat middle case
        Link_Node<T>* push_before_node=push_after_node->getNext();
        push_after_node->setNext(newNode);
        newNode->setPrev(push_after_node);
        push_before_node->setPrev(newNode);
        newNode->setNext(push_before_node);
        return;

    }

}

#endif //EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H
