#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"

int main() {

    AVL::Doubly_Linked_List<int> list;
    AVL::Link_Node<int> node1= AVL::Link_Node<int>(1);
    AVL::Link_Node<int> node2= AVL::Link_Node<int>(2);
    AVL::Link_Node<int> node3= AVL::Link_Node<int>(3);
    AVL::Link_Node<int> node4= AVL::Link_Node<int>(4);
    AVL::Link_Node<int> node5= AVL::Link_Node<int>(5);
    AVL::Link_Node<int> node6= AVL::Link_Node<int>(6);
    AVL::Link_Node<int> node7= AVL::Link_Node<int>(7);
    AVL::Link_Node<int> node8= AVL::Link_Node<int>(8);

    list.setNewNodeAfterNode(NULL,&node1);
    list.setNewNodeAfterNode(&node1,&node2);
    list.setNewNodeAfterNode(&node2,&node3);
    list.setNewNodeAfterNode(&node2,&node4);
    list.setNewNodeAfterNode(NULL,&node5);
    list.setNewNodeAfterNode(&node3,&node6);



    AVL::Link_Node<int>* ptr=list.getHead();
    int i=1;
    while(ptr!=NULL){
        std::cout<<"Node number "<<i<< " is: "<<ptr->getNum()<<std::endl;
        ptr=ptr->getNext();
        i++;
    }
    std::cout<<"The Head is: "<<list.getHead()->getNum()<<std::endl;
    std::cout<<"The Last is: "<<list.getLast()->getNum()<<std::endl;











AVL::AVL_tree_node<int> node_temp5 =   AVL::AVL_tree_node<int>(2,5);
AVL::AVL_tree_node<int> node_temp2 =   AVL::AVL_tree_node<int>(2,2);
AVL::AVL_tree_node<int> node_temp8 =   AVL::AVL_tree_node<int>(2,8);
AVL::AVL_tree_node<int> node_temp1 =   AVL::AVL_tree_node<int>(2,1);
AVL::AVL_tree_node<int> node_temp4 =   AVL::AVL_tree_node<int>(2,4);
AVL::AVL_tree_node<int> node_temp6 =   AVL::AVL_tree_node<int>(2,6);
AVL::AVL_tree_node<int> node_temp10 =   AVL::AVL_tree_node<int>(2,10);
AVL::AVL_tree_node<int> node_temp3 =   AVL::AVL_tree_node<int>(2,3);
AVL::AVL_tree_node<int> node_temp7 =   AVL::AVL_tree_node<int>(2,7);
AVL::AVL_tree_node<int> node_temp9 =   AVL::AVL_tree_node<int>(2,9);
AVL::AVL_tree_node<int> node_temp12 =   AVL::AVL_tree_node<int>(2,12);
AVL::AVL_tree_node<int> node_temp11 =   AVL::AVL_tree_node<int>(2,11);


AVL::AVL_tree<int> check;;
check.insert(node_temp5);
check.insert(node_temp2);
check.insert(node_temp8);
check.insert(node_temp1);
check.insert(node_temp4);
check.insert(node_temp6);
check.insert(node_temp10);
check.insert(node_temp3);
check.insert(node_temp7);
check.insert(node_temp9);
check.insert(node_temp12);
check.insert(node_temp11);


//check.remove(node_temp1);
//StatusType AVL_tree<Element>::remove(AVL::AVL_tree<Element> &node_to_remove)
    //    StatusType AVL_tree<Element>::insert(AVL_tree_node<Element> &node_toadd) {

   ////////////////////////////////////////////////////////neet to update height in the remove function at the way back

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