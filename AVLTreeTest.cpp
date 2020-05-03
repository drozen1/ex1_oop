/*
 * testAVLTree.cpp
 *
 *  Created on: 19 ���� 2013
 *      Author: shirel
 */



#include "AVL_tree.h"

int main(){
    AVL::AVL_tree<int> tree;;

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
	//Specific Cases

	/*correct output for the four next cases
	1 BF: 0 Height: 0
	2 BF: 0 Height: 1
	3 BF: 0 Height: 0 */

	//basic LL root change
//	tree.insert(node_temp3);
//	tree.insert(node_temp2);
//	tree.insert(node_temp1);
//	tree.inOrder(tree.getRoot());
	//tree.treeClear();

//	//basic LR root change
//	tree.insert(3,3);
//	tree.insert(1,1);
//	tree.insert(2,2);
//	tree.inOrder(tree.getRoot());
//	tree.treeClear();
//
//	//basic RR root change
//	tree.insert(1,1);
//	tree.insert(2,2);
//	tree.insert(3,3);
//	tree.inOrder();
//	tree.treeClear();
//
//	//basic RL root change
//	tree.insert(1,1);
//	tree.insert(3,3);
//	tree.insert(2,2);
//	tree.inOrder();
//	tree.treeClear();
//
//	//basic LR not root change
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	6 BF: 1 Height: 3
//	7 BF: 0 Height: 0
//	8 BF: 1 Height: 1 */
//	tree.insert(6,6);
//	tree.insert(4,4);
//	tree.insert(8,8);
//	tree.insert(3,3);
//	tree.insert(5,5);
//	tree.insert(7,7);
//	tree.insert(1,1);
//	tree.insert(2,2);
//	tree.inOrder();
//	tree.treeClear();
//
//	//basic LL not root change
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	6 BF: 1 Height: 3
//	7 BF: 0 Height: 0
//	8 BF: 1 Height: 1 */
//	tree.insert(6,6);
//	tree.insert(4,4);
//	tree.insert(8,8);
//	tree.insert(3,3);
//	tree.insert(5,5);
//	tree.insert(7,7);
//	tree.insert(2,2);
//	tree.insert(1,1);
//	tree.inOrder();
//	tree.treeClear();
//
//	//basic RR not root change
//	/*correct output
//	 * 1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	5 BF: 1 Height: 2
//	7 BF: 0 Height: 0*/
//	tree.insert(5,5);
//	tree.insert(7,7);
//	tree.insert(1,1);
//	tree.insert(2,2);
//	tree.insert(3,3);
//	tree.inOrder();
//	tree.treeClear();
//
//	//basic RL not root change
//	/*correct output
//	 * 1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	5 BF: 1 Height: 2
//	7 BF: 0 Height: 0*/
//	tree.insert(5,5);
//	tree.insert(7,7);
//	tree.insert(1,1);
//	tree.insert(3,3);
//	tree.insert(2,2);
//	tree.inOrder();
//	tree.treeClear();
//
//	//root deletion no roll successor is a neighbour
//	/*correct output
//	2 BF: 0 Height: 0
//	3 BF: 1 Height: 1
//	5 BF: 1 Height: 2
//	6 BF: 0 Height: 0*/
//	tree.insert(4,4);
//	tree.insert(5,5);
//	tree.insert(3,3);
//	tree.insert(2,2);
//	tree.insert(6,6);
//	tree.removeNode(4);
//	tree.inOrder();
//	tree.treeClear();
//
	//root deletion no roll successor is not a neighbour
	/*correct output
	2 BF: 0 Height: 0
	3 BF: 1 Height: 1
	5 BF: 0 Height: 2
	6 BF: 0 Height: 0
	7 BF: 0 Height: 1
	8 BF: 0 Height: 0 */
	tree.insert(node_temp4);
	tree.insert(node_temp3);
	tree.insert(node_temp7);
	tree.insert(node_temp2);
	tree.insert(node_temp5);
	tree.insert(node_temp8);
	tree.insert(node_temp6);
	tree.remove(node_temp4);
	tree.inOrder(tree.getRoot());
//	tree.treeClear();
//
//	//node deletion no roll successor is a neighbour case7
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	7 BF: 1 Height: 3
//	8 BF: -1 Height: 1
//	9 BF: 0 Height: 0*/
//	tree.insert(7,7);
//	tree.insert(3,3);
//	tree.insert(8,8);
//	tree.insert(2,2);
//	tree.insert(4,4);
//	tree.insert(9,9);
//	tree.insert(5,5);
//	tree.insert(1,1);
//	tree.removeNode(3);
//	tree.inOrder();
//	tree.treeClear();
//
//	//node deletion no roll successor is not a neighbour case8
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	5 BF: 0 Height: 2
//	6 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0
//	9 BF: 0 Height: 3
//	10 BF: 0 Height: 0
//	12 BF: -1 Height: 2
//	13 BF: -1 Height: 1
//	14 BF: 0 Height: 0*/
//	tree.insert(9,9);
//	tree.insert(3,3);
//	tree.insert(12,12);
//	tree.insert(2,2);
//	tree.insert(7,7);
//	tree.insert(10,10);
//	tree.insert(13,13);
//	tree.insert(1,1);
//	tree.insert(5,5);
//	tree.insert(8,8);
//	tree.insert(14,14);
//	tree.insert(6,6);
//	tree.removeNode(3);
//	tree.inOrder();
//	tree.treeClear();
//
//	//node deletion causing LR case9
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
//	tree.insert(7,7);
//	tree.insert(2,2);
//	tree.insert(8,8);
//	tree.insert(1,1);
//	tree.insert(4,4);
//	tree.insert(9,9);
//	tree.insert(3,3);
//	tree.removeNode(9);
//	tree.inOrder();
//	tree.treeClear();
//
//	//node deletion causing LL case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	3 BF: 0 Height: 2
//	4 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0*/
//	tree.insert(7,7);
//	tree.insert(3,3);
//	tree.insert(8,8);
//	tree.insert(2,2);
//	tree.insert(4,4);
//	tree.insert(9,9);
//	tree.insert(1,1);
//	tree.removeNode(9);
//	tree.inOrder();
//	tree.treeClear();
//
//	//node deletion causing RR case11
//	/*correct output
//	2 BF: 0 Height: 0
//	3 BF: 0 Height: 1
//	7 BF: 0 Height: 0
//	8 BF: 0 Height: 2
//	9 BF: -1 Height: 1
//	10 BF: 0 Height: 0*/
//	tree.insert(3,3);
//	tree.insert(2,2);
//	tree.insert(8,8);
//	tree.insert(7,7);
//	tree.insert(1,1);
//	tree.insert(9,9);
//	tree.insert(10,10);
//	tree.removeNode(1);
//	tree.inOrder();
//	tree.treeClear();
//
//	//node deletion causing RL case12
//	/*correct output
//	* 2 BF: 0 Height: 0
//	3 BF: 1 Height: 1
//	7 BF: 0 Height: 2
//	10 BF: 0 Height: 0
//	13 BF: 0 Height: 1
//	14 BF: 0 Height: 0*/
//	tree.insert(3,3);
//	tree.insert(2,2);
//	tree.insert(13,13);
//	tree.insert(7,7);
//	tree.insert(1,1);
//	tree.insert(14,14);
//	tree.insert(10,10);
//	tree.removeNode(1);
//	tree.inOrder();
//	tree.treeClear();
//
//	//double rotations RL and RR case 13
//	/*correct output
//	3 BF: 0 Height: 0
//	5 BF: 0 Height: 1
//	7 BF: 0 Height: 0
//	9 BF: 0 Height: 2
//	11 BF: 0 Height: 0
//	13 BF: 1 Height: 1
//	15 BF: 0 Height: 3
//	17 BF: 0 Height: 0
//	19 BF: -1 Height: 2
//	21 BF: -1 Height: 1
//	23 BF: 0 Height: 0*/
//	tree.insert(9,9);
//	tree.insert(3,3);
//	tree.insert(15,15);
//	tree.insert(1,1);
//	tree.insert(7,7);
//	tree.insert(13,13);
//	tree.insert(19,19);
//	tree.insert(5,5);
//	tree.insert(11,11);
//	tree.insert(17,17);
//	tree.insert(21,21);
//	tree.insert(23,23);
//	tree.removeNode(1);
//	tree.inOrder();
//	tree.treeClear();
//
//	//double rotations RR and RR case 14
//	/*correct output
//	3 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0
//	9 BF: 0 Height: 2
//	11 BF: 0 Height: 0
//	13 BF: 1 Height: 1
//	15 BF: 0 Height: 3
//	17 BF: 0 Height: 0
//	19 BF: -1 Height: 2
//	21 BF: -1 Height: 1
//	23 BF: 0 Height: 0*/
//	tree.insert(9,9);
//	tree.insert(3,3);
//	tree.insert(15,15);
//	tree.insert(1,1);
//	tree.insert(7,7);
//	tree.insert(13,13);
//	tree.insert(19,19);
//	tree.insert(8,8);
//	tree.insert(11,11);
//	tree.insert(17,17);
//	tree.insert(21,21);
//	tree.insert(23,23);
//	tree.removeNode(1);
//	tree.inOrder();
//	tree.treeClear();
//
//	//double rotations RL and LL case 15
//	/*correct output
//	6 BF: 0 Height: 0
//	7 BF: 1 Height: 1
//	8 BF: 1 Height: 2
//	9 BF: 0 Height: 0
//	10 BF: 0 Height: 3
//	11 BF: -1 Height: 1
//	12 BF: 0 Height: 0
//	15 BF: 0 Height: 2
//	17 BF: 0 Height: 0
//	18 BF: 0 Height: 1
//	20 BF: 0 Height: 0
//	 */
//	tree.insert(15,15);
//	tree.insert(10,10);
//	tree.insert(20,20);
//	tree.insert(8,8);
//	tree.insert(11,11);
//	tree.insert(17,17);
//	tree.insert(21,21);
//	tree.insert(7,7);
//	tree.insert(9,9);
//	tree.insert(12,12);
//	tree.insert(18,18);
//	tree.insert(6,6);
//	tree.removeNode(21);
//	tree.inOrder();
//	tree.treeClear();
//
//	//double rotations LR and LL case 16
//	/*correct output
//	6 BF: 0 Height: 0
//	7 BF: 1 Height: 1
//	8 BF: 1 Height: 2
//	9 BF: 0 Height: 0
//	10 BF: 0 Height: 3
//	11 BF: -1 Height: 1
//	12 BF: 0 Height: 0
//	15 BF: 0 Height: 2
//	20 BF: 0 Height: 0
//	21 BF: 0 Height: 1
//	22 BF: 0 Height: 0 */
//	tree.insert(15,15);
//	tree.insert(10,10);
//	tree.insert(20,20);
//	tree.insert(8,8);
//	tree.insert(11,11);
//	tree.insert(17,17);
//	tree.insert(22,22);
//	tree.insert(7,7);
//	tree.insert(9,9);
//	tree.insert(12,12);
//	tree.insert(21,21);
//	tree.insert(6,6);
//	tree.removeNode(17);
//	tree.inOrder();
//	tree.treeClear();
//
//	//delete node cause LR
//	/*correct output
//	 * 2 BF: 0 Height: 0
//	3 BF: -1 Height: 2
//	4 BF: 0 Height: 0
//	6 BF: 1 Height: 1*/
//
//	tree.insert(5,5);
//	tree.insert(3,3);
//	tree.insert(6,6);
//	tree.insert(2,2);
//	tree.insert(4,4);
//	tree.removeNode(5);
//	tree.inOrder();
//	tree.treeClear();
//
//	//delete node cause LR
//	/*correct output
//	 * 2 BF: 0 Height: 0
//	3 BF: 0 Height: 1
//	6 BF: 0 Height: 0*/
//	tree.insert(5,5);
//	tree.insert(3,3);
//	tree.insert(6,6);
//	tree.insert(2,2);
//	tree.removeNode(5);
//	tree.inOrder();
//	tree.treeClear();
//
//	std::vector<int> vector;
//	 for (int i=1; i<=100; i++) vector.push_back(i);
//
//	 //Randomly insert and removes nodes
//	 for (int k = 0; k < 20; ++k) {
//		 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//				tree.insert(*it,*it);
//
//		 }
//		 tree.inOrder();
//		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//				tree.removeNode(*it);
//				tree.inOrder();
//
//		 }
//		 tree.treeClear();
//		 tree.inOrder();
//		 std::cout << '\n';
//	}

    std::cout << "the root is: " << tree.getRoot()->getKey() << std::endl;
	return 0;
}

