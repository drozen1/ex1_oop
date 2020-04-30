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

typedef enum {
    RR=0,
    RL=1,
    LL=2,
    LR=3,
    No_Roll_Needed=4
}Roll2_Perform;

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

    void updateHeight ();

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

template<class Element>
void AVL_tree_node<Element>::updateHeight() {
    int left_height,right_height;
    AVL_tree_node* p= this;
    if (p->getLeftSon()==NULL){
        left_height=-1;
    } else{
        left_height=p->getLeftSon()->getHeight();
    }
    if (p->getRightSon()==NULL){
        right_height=-1;
    } else{
        right_height=p->getRightSon()->getHeight();
    }
    p->setHeight(std::max(right_height,left_height)+1);
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

    void updateTree(AVL_tree_node<Element>* start_node);

    Roll2_Perform checkTypeOfRoll(AVL_tree_node<Element>* p);

    void Perform_RR_Roll(AVL_tree_node<Element>* p);

    void Perform_LL_Roll(AVL_tree_node<Element>* p);

    void Perform_LR_Roll(AVL_tree_node<Element>* p);

    void Perform_RL_Roll(AVL_tree_node<Element>* p);

    void PerformRoll(AVL_tree_node<Element>* p,Roll2_Perform roll_needed);
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
    updateTree(&node_toadd);
    return SUCCESS;
}

template<class Element>
Roll2_Perform AVL_tree<Element>::checkTypeOfRoll(AVL_tree_node<Element> *p) {
    if (p->calcBalnceFactor()==-2) {
        if (p->getRightSon()->calcBalnceFactor() == 1) {
            return RL;
        }
        return RR;
    }
    if (p->calcBalnceFactor()==2) {
        if (p->getLeftSon()->calcBalnceFactor() == -1) {
            return LR;
        }
        return LL;
    }
    return No_Roll_Needed;
}

template<class Element>
void AVL_tree<Element>::Perform_RR_Roll(AVL_tree_node<Element> *p) {
    bool updateRoot= false;
    if (p->getParent()==NULL){
        updateRoot=true;
    }
    AVL_tree_node<Element>* OriginalParentOfP=p->getParent(); ///can be NULL
    AVL_tree_node<Element>* leftSonOfRightSonOfP=p->getRightSon()->getLeftSon();
    AVL_tree_node<Element>* RightSonOfP=p->getRightSon();
    RightSonOfP->setLeftSon(p);
    p->setParent(RightSonOfP);
    RightSonOfP->setParent(OriginalParentOfP);
    p->setRightSon(leftSonOfRightSonOfP);
    if (leftSonOfRightSonOfP!=NULL) {
        leftSonOfRightSonOfP->setParent(p);
    }
    if (OriginalParentOfP!=NULL){
        OriginalParentOfP->setRightSon(RightSonOfP);
    }
    ///update the new height
    RightSonOfP->getRightSon()->updateHeight();
    RightSonOfP->getLeftSon()->updateHeight();
    RightSonOfP->updateHeight();

    if(updateRoot){
    this->setRoot(RightSonOfP);
    }
    return;
}

template<class Element>
void AVL_tree<Element>::Perform_LL_Roll(AVL_tree_node<Element> *p) {
    bool updateRoot= false;
    if (p->getParent()==NULL){
        updateRoot=true;
    }

    AVL_tree_node<Element>* OriginalParentOfP=p->getParent(); ///can be NULL

    AVL_tree_node<Element>* RightSonOfLeftSonOfP=p->getLeftSon()->getRightSon();
    AVL_tree_node<Element>* LeftSonOfP=p->getLeftSon();
    LeftSonOfP->setRightSon(p);
    p->setParent(LeftSonOfP);
    LeftSonOfP->setParent(OriginalParentOfP);
    p->setLeftSon(RightSonOfLeftSonOfP);
    if (RightSonOfLeftSonOfP!=NULL) {
        RightSonOfLeftSonOfP->setParent(p);
    }
    if (OriginalParentOfP!=NULL){
        OriginalParentOfP->setLeftSon(LeftSonOfP);
    }
    ///update the new height
    LeftSonOfP->getRightSon()->updateHeight();
    LeftSonOfP->getLeftSon()->updateHeight();
    LeftSonOfP->updateHeight();

    if(updateRoot){
        this->setRoot(LeftSonOfP);
    }
    return;
}

template<class Element>
void AVL_tree<Element>::Perform_LR_Roll(AVL_tree_node<Element> *p) {
    bool updateRoot=false;
    if(p->getParent()==NULL){
        updateRoot=true;
    }
    AVL_tree_node<Element>* LeftSonOfP=p->getLeftSon();
    AVL_tree_node<Element>* RightSonOfLeftSonOfP =p->getLeftSon()->getRightSon();
    AVL_tree_node<Element>* OriginalParent=p->getParent();
    AVL_tree_node<Element>* RightTreeOfA=RightSonOfLeftSonOfP->getRightSon(); ///can be NULL
    RightSonOfLeftSonOfP->setRightSon(p);
    p->setParent(RightSonOfLeftSonOfP);
    p->setLeftSon(RightTreeOfA);
    if (RightTreeOfA!=NULL){
        RightTreeOfA->setParent(p);
    }
    LeftSonOfP->setRightSon(RightSonOfLeftSonOfP->getLeftSon());
    if (RightSonOfLeftSonOfP->getLeftSon()!=NULL){
        RightSonOfLeftSonOfP->getLeftSon()->setParent(LeftSonOfP);
    }
    RightSonOfLeftSonOfP->setLeftSon(LeftSonOfP);
    LeftSonOfP->setParent(RightSonOfLeftSonOfP);
    RightSonOfLeftSonOfP->setParent(OriginalParent);
    if(OriginalParent!=NULL) {
        OriginalParent->setRightSon(RightSonOfLeftSonOfP);
    }

    ///update the new height
      p->updateHeight();
      LeftSonOfP->updateHeight();
      RightSonOfLeftSonOfP->updateHeight();
    if (updateRoot){
        this->setRoot(RightSonOfLeftSonOfP);
    }

    return;
}

template<class Element>
void AVL_tree<Element>::Perform_RL_Roll(AVL_tree_node<Element> *p) {
    bool updateRoot=false;
    if(p->getParent()==NULL){
        updateRoot=true;
    }
    AVL_tree_node<Element>* RightSonOfP=p->getRightSon();

    AVL_tree_node<Element>* LeftSonOfRightSonOfP =p->getRightSon()->getLeftSon();
    AVL_tree_node<Element>* OriginalParent=p->getParent();
    AVL_tree_node<Element>* LeftTreeOfA=LeftSonOfRightSonOfP->getLeftSon(); ///can be NULL
    LeftSonOfRightSonOfP->setLeftSon(p);
    p->setParent(LeftSonOfRightSonOfP);
    p->setRightSon(LeftTreeOfA);
    if (LeftTreeOfA!=NULL){
        LeftTreeOfA->setParent(p);
    }
    RightSonOfP->setLeftSon(LeftSonOfRightSonOfP->getRightSon());
    if (LeftSonOfRightSonOfP->getRightSon()!=NULL){
        LeftSonOfRightSonOfP->getRightSon()->setParent(RightSonOfP);
    }
    LeftSonOfRightSonOfP->setRightSon(RightSonOfP);
    RightSonOfP->setParent(LeftSonOfRightSonOfP);
    LeftSonOfRightSonOfP->setParent(OriginalParent);
    if(OriginalParent!=NULL) {
        OriginalParent->setRightSon(LeftSonOfRightSonOfP);
    }
    ///update the new height
    p->updateHeight();
    RightSonOfP->updateHeight();
    LeftSonOfRightSonOfP->updateHeight();
    if (updateRoot){
        this->setRoot(LeftSonOfRightSonOfP);
    }
    return;
}

template<class Element>
void AVL_tree<Element>::PerformRoll(AVL_tree_node<Element> *p, Roll2_Perform roll_needed) {
    if(roll_needed==RR){
        Perform_RR_Roll(p);
    }
    if (roll_needed==LL){
        Perform_LL_Roll(p);
    }
    if (roll_needed==LR){
        Perform_LR_Roll(p);
    }
    if (roll_needed==RL){
        Perform_RL_Roll(p);
    }
    return;
}

/**
 *
 *the following function updates all the parents of a given node not including the node himself
 * @tparam Element
 * @param start_node
 */
template<class Element>
void AVL_tree<Element>::updateTree(AVL_tree_node<Element>* start_node) {
    AVL_tree_node<Element>* p= nullptr;
    AVL_tree_node<Element>* v= start_node;
    while (v!=this->getRoot()) {
        p=v->getParent();
        if(p->getHeight()>=1+v->getHeight()){
            return;
        }
        p->setHeight(1+v->getHeight());
        Roll2_Perform roll_needed = checkTypeOfRoll(p);
        if(roll_needed==No_Roll_Needed){
            v=p;
        }
        else{
            PerformRoll(p,roll_needed);
            return;
        }
    }
    }



#endif //UNTITLED_AVL_TREE_H
