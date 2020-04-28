//
// Created by Dor on 28/04/2020.
//
#include <algorithm>
#include <iostream>
#ifndef UNTITLED_AVL_TREE_H
#define UNTITLED_AVL_TREE_H

//copy from library
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;

template <class Element>
class AVL_tree_node{
private:
    Element element;
    AVL_tree_node* parent;
    AVL_tree_node* right_son;
    AVL_tree_node* left_son;
    int height;
    int key;

public:

    int calcBalnceFactor();

    Element getElement() const {
        return element;
    }
    void setElement(Element element) {
        AVL_tree_node::element = element;
    }
    AVL_tree_node *getParent() const {
        return parent;
    }
    void setParent(AVL_tree_node *parent) {
        AVL_tree_node::parent = parent;
    }

    AVL_tree_node *getRightSon() const {
        return right_son;
    }
    void setRightSon(AVL_tree_node *rightSon) {
        right_son = rightSon;
    }
    AVL_tree_node *getLeftSon() const {
        return left_son;
    }
    void setLeftSon(AVL_tree_node *leftSon) {
        left_son = leftSon;
    }
    int getHeight() const {
        return height;
    }
    void setHeight(int height) {
        AVL_tree_node::height = height;
    }

    AVL_tree_node(Element e,int key):element(e),parent(nullptr),right_son(nullptr),left_son(nullptr),height(0),key(key){
    }

    virtual ~AVL_tree_node() {

   }


    AVL_tree_node() {
    }

    int getKey() const {
        return key;
    }

    bool isLeaf(){
        return (getRightSon()==NULL&& getLeftSon()==NULL);
    }

    bool operator==(const AVL_tree_node &rhs) const {
        return key == rhs.key;
    }



};

/**
 * clc BF = left_height-right_height
 * @tparam Element
 * @return
 */
template<class Element>
int AVL_tree_node<Element>::calcBalnceFactor() {
    int left_height;
    int right_height;
    if (getLeftSon()==NULL){
        left_height=-1;
    } else{
        left_height=getLeftSon()->getHeight();
    }
    if (getRightSon()==NULL){
        right_height=-1;
    } else{
        right_height=getRightSon()->getHeight();
    }
    return left_height-right_height;
}

template <class Element>
class AVL_tree{
public:
    void setRoot(AVL_tree_node<Element> *root);

    void setMaximum(AVL_tree_node<Element> *maximum);

    AVL_tree(AVL_tree_node<Element> *root) : root(root) {}
    AVL_tree():root(nullptr),maximum(nullptr) {}

    AVL_tree_node<Element>* find_node(int key);

    StatusType insert(AVL_tree_node<Element>& node_toadd);

    AVL_tree_node<Element> *getRoot() const;

    void updateHeights(AVL_tree_node<Element>* start_node);



private:
    AVL_tree_node<Element>* root;
    AVL_tree_node<Element>* maximum;
    //AVL_tree_node<Element>* min;


};
template<class Element>
AVL_tree_node<Element> *AVL_tree<Element>::getRoot() const {
    return root;
}

template<class Element>
void AVL_tree<Element>::setRoot(AVL_tree_node<Element> *root) {
    AVL_tree::root = root;
}

template<class Element>
void AVL_tree<Element>::setMaximum(AVL_tree_node<Element> *maximum) {
    AVL_tree::maximum = maximum;
}


/**
 *
 * @tparam Element
 * @param key
 * @return pointer to the node we want. nullptr- in case the key doesn't exists
 */
template<class Element>
AVL_tree_node<Element>* AVL_tree<Element>::find_node(int key) {
    AVL_tree_node<Element>* curr = root;
    while (curr!=nullptr && (curr->getLeftSon() != nullptr or curr->getRightSon() != nullptr)) {
        if (curr->getKey() == key)
            return curr;

        if (curr->getKey() > key) {
            curr = curr->getLeftSon();
        } else {
            curr = curr->getRightSon();
        }
    }
    if (curr!=NULL && curr->getKey() == key){
        return curr;
    }
    return nullptr;
}



template<class Element>
StatusType AVL_tree<Element>::insert(AVL_tree_node<Element>& node_toadd) {
    int key=node_toadd.getKey();
    if (find_node(key)!= nullptr)
        return FAILURE;
    AVL_tree_node<Element>* curr = root;
    AVL_tree_node<Element>* last = root;
    ///root==NULL
    if(curr== nullptr){
        setRoot(&node_toadd);
        return SUCCESS;
    }
    while (curr != nullptr) {
        if (curr->getKey()>key) {
            last=curr;
            curr = curr->getLeftSon();
        }
         else{
            last=curr;
            curr = curr->getRightSon();
         }
    }
    if (key>last->getKey()){
        last->setRightSon(&node_toadd);
    }
    else{
        last->setLeftSon(&node_toadd);
    }
    node_toadd.setParent(last);
    ///update height
    updateHeights(&node_toadd);
    return SUCCESS;
}

/**
 *
 *the following function updates all the parents of a given node not including the node himself
 * @tparam Element
 * @param start_node
 */
template<class Element>
void AVL_tree<Element>::updateHeights(AVL_tree_node<Element>* start_node) {
    AVL_tree_node<Element>* cur= start_node->getParent();
    int left_height;
    int right_height;
    while (cur!=NULL){
        if (cur->getLeftSon()==NULL){
            left_height=-1;
        } else{
            left_height=cur->getLeftSon()->getHeight();
        }
        if (cur->getRightSon()==NULL){
            right_height=-1;
        } else{
            right_height=cur->getRightSon()->getHeight();
        }
        cur->setHeight(std::max(right_height,left_height)+1);
        cur=cur->getParent();
    }

}


#endif //UNTITLED_AVL_TREE_H
