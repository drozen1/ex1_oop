//
// Created by Dor on 30/04/2020.
//

#ifndef EX1_DATASTRUCK_AVL_TREE_NODE_H
#define EX1_DATASTRUCK_AVL_TREE_NODE_H

namespace AVL {

    template<class Element>
    class AVL_tree_node {
    private:
        Element element;
        AVL_tree_node *parent;
        AVL_tree_node *right_son;
        AVL_tree_node *left_son;
        int height;
        int key;

    public:

        int calcBalnceFactor();

        void updateHeight();

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

        AVL_tree_node(Element e, int key) : element(e), parent(nullptr), right_son(nullptr), left_son(nullptr),
                                            height(0), key(key) {
        }

        virtual ~AVL_tree_node() {
        }


        AVL_tree_node() {
        }

        int getKey() const {
            return key;
        }

        bool isLeaf() {
            return (getRightSon() == NULL && getLeftSon() == NULL);
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


}




#endif //EX1_DATASTRUCK_AVL_TREE_NODE_H
