#ifndef EX1_DATASTRUCK_MUSICMANAGER_H
#define EX1_DATASTRUCK_MUSICMANAGER_H

#include "AVL_tree.h"
#include "AVL_tree_node.h"
#include "Doubly_linked_list.h"
using namespace AVL;

class Artist_arrays {
    int* songNumberOfStreams;
    AVL_tree_node<AVL_tree<int>>** arrayOfPointers;
public:
    Artist_arrays(int songNumber, AVL_tree_node<AVL_tree<int>>* pointerToNewNode)   {
        songNumberOfStreams = new int[songNumber];
        for(int i = 0; i< songNumber; i++)
            songNumberOfStreams[i] = 0;
        arrayOfPointers = new AVL_tree_node<AVL_tree<int>>*[songNumber];

        for(int i = 0; i <songNumber; i++){
            arrayOfPointers[i]= pointerToNewNode;
        }
    }
};

class MusicManager {
    private:
    AVL_tree<Artist_arrays> mainTreeOfArtists;
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> listOfStreams;


    void* Init();

    StatusType AddArtist(void *DS, int artistID, int numOfSongs);
    StatusType AddDataCenter(int artistID, int  numOfSongs);

};

StatusType MusicManager::AddArtist(void *DS, int artistID, int numOfSongs) {
    // don't forget to check that the input is valid
    return ((MusicManager *)DS)-> AddDataCenter(artistID, numOfSongs);
}
StatusType MusicManager::AddDataCenter(int artistID, int numOfSongs) {
    AVL_tree<int>* treeOfSongs = new AVL_tree<int>(numOfSongs);
    AVL_tree_node<AVL_tree<int>>* nodeToAddToTheList = new  AVL_tree_node<AVL_tree<int>>(treeOfSongs,artistID);

    if(this->listOfStreams.getHead()->getNum() == 0){
        this->listOfStreams.getHead()->getElement()->insert(*nodeToAddToTheList);
    }
    else{
        AVL_tree<AVL_tree<int>>* tree_to_add_the_list = new AVL_tree<AVL_tree<int>> ();
        tree_to_add_the_list->insert(*nodeToAddToTheList);
        Link_Node<AVL_tree<AVL_tree<int>>>* linked_list_node = new Link_Node<AVL_tree<AVL_tree<int>>>(0,tree_to_add_the_list);
        this->listOfStreams.setNewNodeAfterNode(NULL,linked_list_node);
    }

    Artist_arrays* artists_arrays = new Artist_arrays(numOfSongs,nodeToAddToTheList);
    AVL_tree_node<Artist_arrays>* node_to_add_to_main_tree = new AVL_tree_node<Artist_arrays>(artists_arrays ,artistID);
    this->mainTreeOfArtists.insert(*node_to_add_to_main_tree);

    return SUCCESS;

}



//void *MusicManager::Init() {
//    try{
//        MusicManager* mm = new MusicManager();
//    }
//    catch () //handle exception
//    return mm;
//}
//}


#endif //EX1_DATASTRUCK_MUSICMANAGER_H