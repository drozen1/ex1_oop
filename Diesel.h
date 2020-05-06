//
// Created by Owner on 06/05/2020.
//

#ifndef EX1_DATASTRUCK_DIESEL_H
#define EX1_DATASTRUCK_DIESEL_H
#include "AVL_tree.h"
#include "AVL_tree_node.h"
#include "Doubly_linked_list.h"
class Diesel {
private:
    class Main_Tree_Artist {
        AVL_Tree_Node<int>* arrayOfPointersToSongs;
        int* arrayOfSongStreams;
        //the class isn't finished
    };
    class Linked_list_Artist_Songs{
        AVL_Tree<int> treeOfArtistSongs;
        //the class isn't finished
    };
    class Tree_Of_Artists{
        AVL_Tree<Linked_list_Artist_Songs> rootOfArtistsTree;
    };

    AVL_Tree<Main_Tree_Artist> MainTreeOfArtists;
    Doubly_Linked_List<Tree_Of_Artists> ListOfStreams;

public:
    void * Init()
};


#endif //EX1_DATASTRUCK_DIESEL_H
