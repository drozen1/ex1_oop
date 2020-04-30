#include <iostream>
#include "AVL_tree.h"

int main() {

    AVL_tree_node<int> node_temp10 =  AVL_tree_node<int>(2,10);
    AVL_tree_node<int> node_temp11 =  AVL_tree_node<int>(2,11);
    AVL_tree_node<int> node_temp12 =  AVL_tree_node<int>(2,12);
    AVL_tree_node<int> node_temp3 =  AVL_tree_node<int>(2,3);
    AVL_tree_node<int> node_temp4 =  AVL_tree_node<int>(2,4);
    AVL_tree_node<int> node_temp5 =  AVL_tree_node<int>(2,5);
    AVL_tree_node<int> node_temp6 =  AVL_tree_node<int>(2,6);
    AVL_tree_node<int> node_temp2N =  AVL_tree_node<int>(2,-2);
    AVL_tree_node<int> node_temp8 =  AVL_tree_node<int>(2,8);
    AVL_tree_node<int> node_temp9 =  AVL_tree_node<int>(2,9);
    AVL_tree_node<int> node_temp7 =  AVL_tree_node<int>(2,7);

    //AVL_tree_node<AVL_tree<int>> super_tree =  AVL_tree_node<AVL_tree<int>>();

    AVL_tree<int> check;
    check.find_node(2);
    check.insert(node_temp12);
    check.insert(node_temp11);
    check.insert(node_temp4);
   check.insert(node_temp10);
    check.insert(node_temp5);
    check.insert(node_temp6);
    check.insert(node_temp8);

    check.insert(node_temp7);
    check.insert(node_temp12);
    check.insert(node_temp2N);
    check.insert(node_temp9);
    check.insert(node_temp11);
    check.insert(node_temp4);


//    AVL_tree_node<int>* node_temp3=check.find_node(8);
   std::cout << node_temp10.calcBalnceFactor() << std::endl;
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