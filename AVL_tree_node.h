//
// Created by Dor on 30/04/2020.
//

#ifndef EX1_DATASTRUCK_AVL_TREE_NODE_H
#define EX1_DATASTRUCK_AVL_TREE_NODE_H


#include <ostream>
#include "AVL_types.h"


namespace AVL {

    using namespace AVLUtils;
template<class Element>
    class AVL_tree_node {
    private:
        Element* element;
        AVL_tree_node *parent;
        AVL_tree_node *right_son;
        AVL_tree_node *left_son;
        int height;
        int key;

    public:
        AVL_tree_node* retreiveFollowingVertexInorder(){
            AVL_tree_node* temp =  this->getRightSon();
            while(temp->getLeftSon()!= NULL){
                temp = temp->getLeftSon();
            }
            return temp;
        }


        int calcBalnceFactor();

        void updateHeight();

        Element *getElement() const;

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
        void delete_redudants_nodes (int* num_of_nodes_to_delete);

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

        AVL_tree_node(Element* e, int receivedKey) {
            element = e;
            parent= (nullptr);
            right_son = (nullptr);
            left_son = (nullptr);
            height =(0);
            key = (receivedKey);

        }

        AVL_tree_node(int key);



        virtual ~AVL_tree_node() {
            delete(&element);
        }


        AVL_tree_node() {
        }

        int getKey() const {
            return key;
        }

        bool isLeaf() {
            return (getRightSon() == NULL && getLeftSon() == NULL);
        }

        int numOfchildren();

        TypeOfSon getTypeOfSon(AVL_tree_node<Element>* Son);



        bool operator==(const AVL_tree_node &rhs) const {
            return key == rhs.key;
        }

//        friend std::ostream &operator<<(std::ostream &os, const AVL_tree_node &node);

        void Print_node();

    void setElement(Element *element);

    void setKey(int key);


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
        if (getLeftSon() == NULL) {
            left_height = -1;
        } else {
            left_height = getLeftSon()->getHeight();
        }
        if (getRightSon() == NULL) {
            right_height = -1;
        } else {
            right_height = getRightSon()->getHeight();
        }
        return left_height - right_height;
    }

    template<class Element>
    void AVL_tree_node<Element>::updateHeight() {
        int left_height, right_height;
        AVL_tree_node *p = this;
        if (p->getLeftSon() == NULL) {
            left_height = -1;
        } else {
            left_height = p->getLeftSon()->getHeight();
        }
        if (p->getRightSon() == NULL) {
            right_height = -1;
        } else {
            right_height = p->getRightSon()->getHeight();
        }
        p->setHeight(std::max(right_height, left_height) + 1);
    }

    template<class Element>
    void AVL_tree_node<Element>::Print_node() {
        std::cout << "Our node is key: " << key<< " ";
        std::cout << "BF: " << calcBalnceFactor() << " ";
        std::cout << "Height: " << getHeight();
        std::cout<<std::endl;
        return;
    }

    template<class Element>
    int AVL_tree_node<Element>::numOfchildren() {
        if (this->getRightSon()!=NULL&& this->getLeftSon()!=NULL){
            return 2;
        }
        if(this->getRightSon()==NULL&& this->getLeftSon()==NULL){
            return 0;
        }
        return 1;
    }

    /**
     * the function works on the parent
     * @tparam Element
     * @param Son-the son we want to check, what type of son it is of the given parent
     * @return
     */
    template<class Element>
    TypeOfSon AVL_tree_node<Element>::getTypeOfSon(AVL_tree_node<Element> *Son) {
        if(this->getLeftSon()!=NULL && this->getLeftSon()->getKey()==Son->getKey())
          return LEFT;
        return RIGHT;
    }

    template<class Element>
    AVL_tree_node<Element>::AVL_tree_node(int key):parent(nullptr), right_son(nullptr), left_son(nullptr),key(key) {}

    template<class Element>
    Element *AVL_tree_node<Element>::getElement() const {
        return element;
    }
    template<class Element>
    void AVL_tree_node<Element>::setKey(int key) {
        AVL_tree_node::key = key;
    }

    template<class Element>
    void AVL_tree_node<Element>::setElement(Element *element) {
        AVL_tree_node::element = element;
    }

    template<class Element>
    void AVL_tree_node<Element>::delete_redudants_nodes(int* num_of_nodes_to_delete) {
        if(*num_of_nodes_to_delete==0|| this==NULL){
            return;
        }
        AVL_tree_node<Element>*right= this->getRightSon();
        right->delete_redudants_nodes(num_of_nodes_to_delete);
                //->delete_redudants_nodes(num_of_nodes_to_delete);
        ///delete if it is leaf
        if (isLeaf()){
            *num_of_nodes_to_delete=*num_of_nodes_to_delete-1;
            if(this->getParent()->getRightSon()!=NULL){
                this->getParent()->setRightSon(NULL);
                delete this;
            }
            else{
                this->getParent()->setLeftSon(NULL);
                this->getParent()->setHeight(this->getParent()->getHeight()-1);
                delete this;
            }
            return;
        }

        this->getLeftSon()->delete_redudants_nodes(num_of_nodes_to_delete);
    }





//    template<class Element>
//    TypeOfSon AVL_tree_node<Element>::getTypeOfSon() {
//        if(this->getRightSon()!=NULL) {
//            return RIGHT_SON;
//        }
//        if(this->getLeftSon()!=NULL) {
//            return LEFT_SON;
//        }
//        return LEFT_SON;
//    }






//    template<class Element>
//    std::ostream& AVL_tree_node<Element>:: operator<<(std::ostream &os, const AVL_tree_node <Element> &node) {
//        os << "height: " << node.getHeight() << " key: " << node.getKey();
//        return os;
//    }


}




#endif //EX1_DATASTRUCK_AVL_TREE_NODE_H
