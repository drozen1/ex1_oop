#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {



AVL::AVL_tree<int> check;
int x=-999;
    AVL_tree_node<int> node_temp6 =  AVL_tree_node<int>(&x,6);
    AVL_tree_node<int> node_temp1 =  AVL_tree_node<int>(&x,1);
    AVL_tree_node<int> node_temp2 =  AVL_tree_node<int>(&x,2);
    AVL_tree_node<int> node_temp3 =  AVL_tree_node<int>(&x,3);
    AVL_tree_node<int> node_temp4 =  AVL_tree_node<int>(&x,4);
    AVL_tree_node<int> node_temp5 =  AVL_tree_node<int>(&x,5);


    check.insert(node_temp6);
    check.insert(node_temp4);
    check.insert(node_temp3);
    check.insert(node_temp5);
    check.insert(node_temp1);
    check.insert(node_temp2);

    AVL_tree_node<int> *cur=check.getMinimum();
    AVL_tree_node<int> *last=cur->getParent();
    check.print_from_min(cur,NULL);

//    check.inOrder(check.getRoot());
//    AVL::AVL_tree<int> tree2(12);
//    tree2.inOrder(tree2.getRoot());
//check.insert(node_temp7);
//check.insert(node_temp9);
//check.insert(node_temp12);
//check.insert(node_temp11);


//check.remove(node_temp1);
//StatusType AVL_tree<Element>::remove(AVL::AVL_tree<Element> &node_to_remove)
    //    StatusType AVL_tree<Element>::insert(AVL_tree_node<Element> &node_toadd) {



//    AVL_tree_node<int>* node_temp3=check.find_node(8);
    //   check.inOrder(check.getRoot());
    //std::cout << "node_temp10.calcBalnceFactor() "<< std::endl;
    //node_temp1=check.find_node(7);

//    check.insert(node_temp1);
//    check.insert(node_temp2);
//    check.insert(node_temp3);
//    check.insert(node_temp4);

//    AVL_tree_node<int>* curr = &node_temp;
//    if(curr!=NULL && (curr->getLeftSon() != NULL or curr->getRightSon() != nullptr)){
//        std::cout << "the root is: " << check.getRoot()->getKey() << std::endl;
//    }

    return 0;
}