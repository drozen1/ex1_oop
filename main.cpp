#include <iostream>
#include "AVL_tree.h"

int main() {

    AVL_tree_node<int> node_temp =  AVL_tree_node<int>(2,0);
    AVL_tree_node<int> node_temp1 =  AVL_tree_node<int>(2,1);
    AVL_tree_node<int> node_temp2 =  AVL_tree_node<int>(2,2);
    AVL_tree_node<int> node_temp3 =  AVL_tree_node<int>(2,3);
    AVL_tree_node<int> node_temp4 =  AVL_tree_node<int>(2,4);
    AVL_tree_node<int> node_temp5 =  AVL_tree_node<int>(2,5);


    //AVL_tree_node<AVL_tree<int>> super_tree =  AVL_tree_node<AVL_tree<int>>();

    AVL_tree<int> check;
    check.find_node(2);
    check.insert(node_temp);
    check.insert(node_temp1);
    check.insert(node_temp2);
    check.insert(node_temp3);
    check.insert(node_temp4);
    check.insert(node_temp5);

//    AVL_tree_node<int>* node_temp3=check.find_node(8);
   std::cout << node_temp3.calcBalnceFactor() << std::endl;
    //node_temp1=check.find_node(7);

//    check.insert(node_temp1);
//    check.insert(node_temp2);
//    check.insert(node_temp3);
//    check.insert(node_temp4);

//    AVL_tree_node<int>* curr = &node_temp;
//    if(curr!=NULL && (curr->getLeftSon() != NULL or curr->getRightSon() != nullptr)){
//        std::cout << "Hello, World!" << std::endl;
//    }

    return 0;
}