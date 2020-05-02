//
// Created by Dor on 28/04/2020.
//

#ifndef UNTITLED_AVL_TREE_H
#define UNTITLED_AVL_TREE_H



#include "AVL_tree_node.h"
#include <ostream>


namespace AVL {

    using namespace AVLUtils;


    template<class Element>
    class AVL_tree {
    public:
        void setRoot(AVL_tree_node<Element> *root);

        void handleLeafRemoval(AVL_tree_node<Element> *p);

        void handleRemovalOfVerWithOneKid(AVL_tree_node<Element> *p);

        void handleRemovalOfVerWithTwoKids(AVL_tree_node<Element> *p);

        void setMaximum(AVL_tree_node<Element> *maximum);

        AVL_tree(AVL_tree_node<Element> *root) : root(root) {}

        AVL_tree() : root(nullptr), maximum(nullptr) {}

        AVL_tree_node<Element> *find_node(int key);

        StatusType insert(AVL_tree_node<Element> &node_toadd);

        StatusType remove(AVL_tree<Element> &node_to_remove);

        AVL_tree_node<Element> *getRoot() const;

        void updateTree(AVL_tree_node<Element> *start_node);

        Roll2_Perform checkTypeOfRoll(AVL_tree_node<Element> *p);

        void Perform_RR_Roll(AVL_tree_node<Element> *p);

        void Perform_LL_Roll(AVL_tree_node<Element> *p);

        void Perform_LR_Roll(AVL_tree_node<Element> *p);

        void Perform_RL_Roll(AVL_tree_node<Element> *p);

        void PerformRoll(AVL_tree_node<Element> *p, Roll2_Perform roll_needed);

        void inOrder(AVL_tree_node<Element> *p);

        AVL_tree_node<Element> *searchTreeRemoval(AVL_tree_node<Element> &node_to_remove);

    private:
        AVL_tree_node<Element> *root;
        AVL_tree_node<Element> *maximum;
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
    AVL_tree_node<Element> *AVL_tree<Element>::find_node(int key) {
        AVL_tree_node<Element> *curr = root;
        while (curr != nullptr && (curr->getLeftSon() != nullptr or curr->getRightSon() != nullptr)) {
            if (curr->getKey() == key)
                return curr;

            if (curr->getKey() > key) {
                curr = curr->getLeftSon();
            } else {
                curr = curr->getRightSon();
            }
        }
        if (curr != NULL && curr->getKey() == key) {
            return curr;
        }
        return nullptr;
    }


    template<class Element>
    StatusType AVL_tree<Element>::insert(AVL_tree_node<Element> &node_toadd) {
        int key = node_toadd.getKey();
        if (find_node(key) != nullptr)
            return FAILURE;
        AVL_tree_node<Element> *curr = root;
        AVL_tree_node<Element> *last = root;
        ///root==NULL
        if (curr == nullptr) {
            setRoot(&node_toadd);
            return SUCCESS;
        }
        while (curr != nullptr) {
            if (curr->getKey() > key) {
                last = curr;
                curr = curr->getLeftSon();
            } else {
                last = curr;
                curr = curr->getRightSon();
            }
        }
        if (key > last->getKey()) {
            last->setRightSon(&node_toadd);
        } else {
            last->setLeftSon(&node_toadd);
        }
        node_toadd.setParent(last);
        updateTree(&node_toadd);
        return SUCCESS;
    }


    template<class Element>
    StatusType AVL_tree<Element>::remove(AVL::AVL_tree<Element> &node_to_remove) {
        AVL_tree_node<Element> *parentOfRemovedNode = searchTreeRemoval(node_to_remove);
        if (parentOfRemovedNode == NULL) {
            return SUCCESS;
        }
        AVL_tree_node<Element> *v = parentOfRemovedNode;
        while (v!= NULL){
            int previousHeightOfV = v->getHeight();
            v->updateHeight();
            Roll2_Perform roll_needed = checkTypeOfRoll(v);
           if (roll_needed == No_Roll_Needed) {
//            v = p;
//        } else {
//            PerformRoll(p, roll_needed);
//            return;
        }

    }


    template<class Element>
    Roll2_Perform AVL_tree<Element>::checkTypeOfRoll(AVL_tree_node<Element> *p) {
        if (p->calcBalnceFactor() == -2) {
            if (p->getRightSon()->calcBalnceFactor() == 1) {
                return RL;
            }
            return RR;
        }
        if (p->calcBalnceFactor() == 2) {
            if (p->getLeftSon()->calcBalnceFactor() == -1) {
                return LR;
            }
            return LL;
        }
        return No_Roll_Needed;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_RR_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node<Element> *OriginalParentOfP = p->getParent(); ///can be NULL
        AVL_tree_node<Element> *leftSonOfRightSonOfP = p->getRightSon()->getLeftSon();
        AVL_tree_node<Element> *RightSonOfP = p->getRightSon();
        RightSonOfP->setLeftSon(p);
        p->setParent(RightSonOfP);
        RightSonOfP->setParent(OriginalParentOfP);
        p->setRightSon(leftSonOfRightSonOfP);
        if (leftSonOfRightSonOfP != NULL) {
            leftSonOfRightSonOfP->setParent(p);
        }
        if (OriginalParentOfP != NULL) {
            OriginalParentOfP->setRightSon(RightSonOfP);
        }
        ///update the new height
        RightSonOfP->getRightSon()->updateHeight();
        RightSonOfP->getLeftSon()->updateHeight();
        RightSonOfP->updateHeight();

        if (updateRoot) {
            this->setRoot(RightSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_LL_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }

        AVL_tree_node<Element> *OriginalParentOfP = p->getParent(); ///can be NULL

        AVL_tree_node<Element> *RightSonOfLeftSonOfP = p->getLeftSon()->getRightSon();
        AVL_tree_node<Element> *LeftSonOfP = p->getLeftSon();
        LeftSonOfP->setRightSon(p);
        p->setParent(LeftSonOfP);
        LeftSonOfP->setParent(OriginalParentOfP);
        p->setLeftSon(RightSonOfLeftSonOfP);
        if (RightSonOfLeftSonOfP != NULL) {
            RightSonOfLeftSonOfP->setParent(p);
        }
        if (OriginalParentOfP != NULL) {
            OriginalParentOfP->setLeftSon(LeftSonOfP);
        }
        ///update the new height
        LeftSonOfP->getRightSon()->updateHeight();
        LeftSonOfP->getLeftSon()->updateHeight();
        LeftSonOfP->updateHeight();

        if (updateRoot) {
            this->setRoot(LeftSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_LR_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node<Element> *LeftSonOfP = p->getLeftSon();
        AVL_tree_node<Element> *RightSonOfLeftSonOfP = p->getLeftSon()->getRightSon();
        AVL_tree_node<Element> *OriginalParent = p->getParent();
        AVL_tree_node<Element> *RightTreeOfA = RightSonOfLeftSonOfP->getRightSon(); ///can be NULL
        RightSonOfLeftSonOfP->setRightSon(p);
        p->setParent(RightSonOfLeftSonOfP);
        p->setLeftSon(RightTreeOfA);
        if (RightTreeOfA != NULL) {
            RightTreeOfA->setParent(p);
        }
        LeftSonOfP->setRightSon(RightSonOfLeftSonOfP->getLeftSon());
        if (RightSonOfLeftSonOfP->getLeftSon() != NULL) {
            RightSonOfLeftSonOfP->getLeftSon()->setParent(LeftSonOfP);
        }
        RightSonOfLeftSonOfP->setLeftSon(LeftSonOfP);
        LeftSonOfP->setParent(RightSonOfLeftSonOfP);
        RightSonOfLeftSonOfP->setParent(OriginalParent);
        if (OriginalParent != NULL) {
            OriginalParent->setRightSon(RightSonOfLeftSonOfP);
        }

        ///update the new height
        p->updateHeight();
        LeftSonOfP->updateHeight();
        RightSonOfLeftSonOfP->updateHeight();
        if (updateRoot) {
            this->setRoot(RightSonOfLeftSonOfP);
        }

        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_RL_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node<Element> *RightSonOfP = p->getRightSon();

        AVL_tree_node<Element> *LeftSonOfRightSonOfP = p->getRightSon()->getLeftSon();
        AVL_tree_node<Element> *OriginalParent = p->getParent();
        AVL_tree_node<Element> *LeftTreeOfA = LeftSonOfRightSonOfP->getLeftSon(); ///can be NULL
        LeftSonOfRightSonOfP->setLeftSon(p);
        p->setParent(LeftSonOfRightSonOfP);
        p->setRightSon(LeftTreeOfA);
        if (LeftTreeOfA != NULL) {
            LeftTreeOfA->setParent(p);
        }
        RightSonOfP->setLeftSon(LeftSonOfRightSonOfP->getRightSon());
        if (LeftSonOfRightSonOfP->getRightSon() != NULL) {
            LeftSonOfRightSonOfP->getRightSon()->setParent(RightSonOfP);
        }
        LeftSonOfRightSonOfP->setRightSon(RightSonOfP);
        RightSonOfP->setParent(LeftSonOfRightSonOfP);
        LeftSonOfRightSonOfP->setParent(OriginalParent);
        if (OriginalParent != NULL) {
            OriginalParent->setRightSon(LeftSonOfRightSonOfP);
        }
        ///update the new height
        p->updateHeight();
        RightSonOfP->updateHeight();
        LeftSonOfRightSonOfP->updateHeight();
        if (updateRoot) {
            this->setRoot(LeftSonOfRightSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::PerformRoll(AVL_tree_node<Element> *p, Roll2_Perform roll_needed) {
        if (roll_needed == RR) {
            Perform_RR_Roll(p);
        }
        if (roll_needed == LL) {
            Perform_LL_Roll(p);
        }
        if (roll_needed == LR) {
            Perform_LR_Roll(p);
        }
        if (roll_needed == RL) {
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
    void AVL_tree<Element>::updateTree(AVL_tree_node<Element> *start_node) {
        AVL_tree_node<Element> *p = nullptr;
        AVL_tree_node<Element> *v = start_node;
        while (v != this->getRoot()) {
            p = v->getParent();
            if (p->getHeight() >= 1 + v->getHeight()) {
                return;
            }
            p->setHeight(1 + v->getHeight());
            Roll2_Perform roll_needed = checkTypeOfRoll(p);
            if (roll_needed == No_Roll_Needed) {
                v = p;
            } else {
                PerformRoll(p, roll_needed);
                return;
            }
        }
    }

    template<class Element>
    void AVL_tree<Element>::inOrder(AVL_tree_node<Element> *p) {

        if (p==NULL){
            return;
        }
        inOrder(p->getLeftSon());
        p->Print_node();
        inOrder(p->getRightSon());
    }

    /**
     *
     * @tparam Element
     * @param node_toremove
     * @return Null if the node was not found or if he is the only node
     */
    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::searchTreeRemoval(AVL_tree_node<Element> &node_to_remove) {
        AVL_tree_node<Element>* p=find_node(node_to_remove.getKey());
        if (p==NULL){
            return NULL;
        }
        AVL_tree_node<Element>* parentOfp= p->getParent();

        if (p->isLeaf()){
            handleLeafRemoval(p);
            return parentOfp;
        }
        if (p->numOfchildren() == 1){
            handleRemovalOfVerWithOneKid(p);
            return parentOfp;
        }
        handleRemovalOfVerWithTwoKids(p);
    return parentOfp; // temporary and should be changed
    }

template<class Element>
void AVL_tree<Element>::handleRemovalOfVerWithTwoKids(AVL_tree_node<Element> *p){ //Should be tested more!
    AVL_tree_node<Element>* parentOfp = p->getParent();
    bool shouldResetRoot = false;
        if(parentOfp==NULL){
            shouldResetRoot = true;
        }
            AVL_tree_node<Element>* followingVerInorder = p->retreiveFollowingVertexInorder();
            if ( followingVerInorder->getKey() == p->getRightSon()->getKey()){
                AVL_tree_node<Element>* leftSonOfp = p->getLeftSon();
                followingVerInorder->setLeftSon(leftSonOfp);
                leftSonOfp->setParent(followingVerInorder);
                if(shouldResetRoot){
                    followingVerInorder->setParent(NULL);
                    setRoot(followingVerInorder) ;
                }
                else{
                    followingVerInorder->setParent(parentOfp);
                    if(parentOfp->getTypeOfSon(p)==RIGHT){
                        parentOfp->setRightSon(followingVerInorder);
                    }
                    else{
                        parentOfp->setLeftSon(followingVerInorder);
                    }
                }
                delete(p);
                return;

            }
            AVL_tree_node<Element>* parentOfFollowingVer = followingVerInorder->getParent();
            if (followingVerInorder->isLeaf()) { //handle the case the following vertex is a leaf
                if(parentOfFollowingVer->getKey()!=p->getKey()) {
                    if (parentOfFollowingVer->getTypeOfSon(followingVerInorder) == RIGHT) {
                        parentOfFollowingVer->setRightSon(NULL);
                    } else {
                        parentOfFollowingVer->setLeftSon(NULL);
                    }
                }
            }
            AVL_tree_node<Element>* rightSonOfFollowingVer = followingVerInorder->getRightSon();
            if(followingVerInorder->numOfchildren() == 1){ //surely a right son of the given vertex, if there's one
                parentOfFollowingVer->setLeftSon (rightSonOfFollowingVer);
                rightSonOfFollowingVer->setParent(parentOfFollowingVer);
            }
            if (p->getLeftSon()->getKey()!=followingVerInorder->getKey()) {
                followingVerInorder->setLeftSon(p->getLeftSon());
                p->getLeftSon()->setParent(followingVerInorder);
            }
            if (p->getRightSon()->getKey()!=followingVerInorder->getKey()) {
                followingVerInorder->setRightSon(p->getRightSon());
                p->getRightSon()->setParent(followingVerInorder);
            }

                if(shouldResetRoot){
                    setRoot(followingVerInorder);
                    followingVerInorder->setParent(NULL);
                }
                else{
                    followingVerInorder->setParent(parentOfp);
                    if(parentOfp->getTypeOfSon(p)==RIGHT){
                        parentOfp->setRightSon(followingVerInorder);
                    }
                    else{
                        parentOfp->setLeftSon(followingVerInorder);
                    }
                }
                delete (p);
    return;
        }



template<class Element>
void AVL_tree<Element>::handleLeafRemoval(AVL_tree_node<Element> *p){
    AVL_tree_node<Element>* parentOfp= p->getParent();
    bool shouldResetRoot = false;
    if(parentOfp==NULL){
        shouldResetRoot = true;
    }
    if(shouldResetRoot) { //handle root case
        setRoot(NULL);
        delete(p);
        return;
    }
    if (parentOfp->getTypeOfSon(p)==RIGHT){
        parentOfp->setRightSon(NULL);
    }
    if (parentOfp->getTypeOfSon(p)==LEFT){
        parentOfp->setLeftSon(NULL);
    }
    delete(p);
    return;
}

    template<class Element>
    void AVL_tree<Element>::handleRemovalOfVerWithOneKid(AVL_tree_node<Element> *p){
        bool shouldResetRoot = false;
        if(p->getParent()==NULL){
            shouldResetRoot = true;
        }
        if(shouldResetRoot){ // Handle the root removal case
            if (p->getLeftSon()!=NULL){
                setRoot(p->getLeftSon());
                p->getLeftSon()->setParent(NULL);
            }
            else {
                setRoot(p->getRightSon()); // the son of p is surely it's right one
                p->getRightSon()->setParent(NULL);
            }
            delete (p);
            return;
        }
        AVL_tree_node<Element>* parentOfp= p->getParent();
        if(parentOfp->getTypeOfSon(p)==LEFT){
            if(p->getLeftSon()!=NULL){
                parentOfp->setLeftSon(p->getLeftSon());
                p->getLeftSon()->setParent(parentOfp);
            }
            else{
                parentOfp->setLeftSon(p->getRightSon());
                p->getRightSon()->setParent(parentOfp);
            }
        }

        else{ //p is the right son of his parent
            if(p->getLeftSon()!=NULL){
                parentOfp->setRightSon(p->getLeftSon());
                p->getLeftSon()->setParent(parentOfp);
            }
            else{
                parentOfp->setRightSon(p->getRightSon());
                p->getRightSon()->setParent(parentOfp);
            }
        }
         delete(p);
        return;
    }

//    template<class Element>
//    void AVL_tree<Element>::handleRemovalOfVerWithTwoKids(AVL_tree_node<Element> *p){ //BUGGY!!! needs repair
//        AVL_tree_node<Element>* parentOfp= p->getParent(); //surely isn't null because the root case is being taken care of earlier
//        AVL_tree_node<Element>* followingVerInorder = p->retreiveFollowingVertexInorder();
//        AVL_tree_node<Element>* parentOfFollowingVer = followingVerInorder->getParent();
//        if (followingVerInorder->isLeaf()) { //handle the case the following vertex is a leaf
//            if (parentOfFollowingVer->getTypeOfSon(followingVerInorder) == LEFT) {
//                parentOfFollowingVer->setLeftSon(NULL);
//            }
//        }
//
//        AVL_tree_node<Element>* rightSonOfFollowingVer = followingVerInorder->getRightSon();
//        if(followingVerInorder->numOfchildren() == 1){ //surely a right son of the given vertex, if there's one
//            parentOfFollowingVer->setLeftSon (rightSonOfFollowingVer);
//            rightSonOfFollowingVer->setParent(parentOfFollowingVer);
//
//        }
//        followingVerInorder->setLeftSon( p->getLeftSon());
//        if (p->getKey()!=parentOfFollowingVer->getKey()) {
//            followingVerInorder->setRightSon(p->getRightSon());
//        }
//        p->getLeftSon()->setParent(followingVerInorder);
//        if (p->getKey()!=parentOfFollowingVer->getKey()) {
//            p->getRightSon()->setParent(followingVerInorder);
//        }
//        followingVerInorder->setParent(parentOfp);
//        if (parentOfp->getTypeOfSon(p)==RIGHT){
//            parentOfp->setRightSon(followingVerInorder);
//        }
//        else{
//            parentOfp->setLeftSon(followingVerInorder);
//        }
//        delete (p);
//        return;
//    }

    }


#endif //UNTITLED_AVL_TREE_H
