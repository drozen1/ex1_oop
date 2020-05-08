#ifndef EX1_DATASTRUCK_MUSICMANAGER_H
#define EX1_DATASTRUCK_MUSICMANAGER_H

#include "AVL_tree.h"
#include "AVL_tree_node.h"
#include "Doubly_linked_list.h"
using namespace AVL;

class Artist_arrays {
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>>* pointerToListOfStreams;
    int artistID;
    int numberOfSongs;
    int* songNumberOfStreams;
    Link_Node<AVL_tree<AVL_tree<int>>>** arrayOfPointers;
public:
    int getNumberOfSongs(){
       return numberOfSongs;
   }
   int getSongNumberOfStreams(int index){
       return songNumberOfStreams[index];
   }
    Artist_arrays(Doubly_Linked_List<AVL_tree<AVL_tree<int>>>* pointerToList,int ID,int songNumber)   {
        pointerToListOfStreams = pointerToList;
        artistID = ID;
         numberOfSongs = songNumber;
        songNumberOfStreams = new int[songNumber];
        for(int i = 0; i< songNumber; i++)
            songNumberOfStreams[i] = 0;
       arrayOfPointers = new Link_Node<AVL_tree<AVL_tree<int>>>*[songNumber];
        for(int i = 0; i <songNumber; i++){
            arrayOfPointers[i]= pointerToList->getHead();
        }
    }
~Artist_arrays(){
    delete[] (songNumberOfStreams);
    AVL_tree_node<AVL_tree<int>> dummyNode =  AVL_tree_node<AVL_tree<int>>(NULL, artistID);
    // insert check that memory didn't fail
    for (int i = 0 ; i < numberOfSongs; i ++){
        if(arrayOfPointers[i] != NULL){
            arrayOfPointers[i]->getElement()->remove(dummyNode);
            if(arrayOfPointers[i]->getElement()->getRoot() == NULL){
                pointerToListOfStreams->removeNodeFromList(arrayOfPointers[i]);
                arrayOfPointers[i] = NULL;
            }
        }
    }
}
};

class MusicManager {
    private:
    AVL_tree<Artist_arrays> mainTreeOfArtists;
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> listOfStreams;
    public:

    StatusType RemoveArtistFromDataCenter(int artistID);
    StatusType AddDataCenter(int artistID, int  numOfSongs);
    StatusType MMGetNumberOfStreams(int artistID, int songID,int *streams);
};
void* Init();
StatusType RemoveArtist(void *DS, int artistID);
StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);
StatusType AddArtist(void *DS, int artistID, int numOfSongs);


StatusType AddArtist(void *DS, int artistID, int numOfSongs) {
    if (DS == NULL || artistID <= 0 || numOfSongs<=0){
        return INVALID_INPUT;
    }
    return ((MusicManager *)DS)-> AddDataCenter(artistID, numOfSongs);
}

StatusType MusicManager::AddDataCenter(int artistID, int numOfSongs) {
    if (mainTreeOfArtists.find_node(artistID) != NULL ){
        return FAILURE;
    }
    AVL_tree<int>* treeOfSongs = new AVL_tree<int>(numOfSongs);
    AVL_tree_node<AVL_tree<int>>* nodeToAddToTheList = new  AVL_tree_node<AVL_tree<int>>(treeOfSongs,artistID);

    if (this->listOfStreams.getHead()!=NULL  && this->listOfStreams.getHead()->getNum() == 0) {
        this->listOfStreams.getHead()->getElement()->insert(*nodeToAddToTheList);
    }
    else{
        AVL_tree<AVL_tree<int>>* tree_to_add_the_list = new AVL_tree<AVL_tree<int>> ();
        tree_to_add_the_list->insert(*nodeToAddToTheList);
        Link_Node<AVL_tree<AVL_tree<int>>>* linked_list_node = new Link_Node<AVL_tree<AVL_tree<int>>>(0,tree_to_add_the_list);
        this->listOfStreams.setNewNodeAfterNode(NULL,linked_list_node);
    }
    Artist_arrays* artists_arrays = new Artist_arrays(&this->listOfStreams,artistID,numOfSongs);
    AVL_tree_node<Artist_arrays>* node_to_add_to_main_tree = new AVL_tree_node<Artist_arrays>(artists_arrays ,artistID);
    this->mainTreeOfArtists.insert(*node_to_add_to_main_tree);
    return SUCCESS;
}

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams) {
       if(DS == NULL ){
           return INVALID_INPUT;
       }
        return ((MusicManager *)DS) -> MMGetNumberOfStreams(artistID,songID,streams);
}
StatusType MusicManager::MMGetNumberOfStreams(int artistID, int songID, int *streams) {
    if(streams == NULL || songID < 0 || artistID <= 0 ){ ///check that streams really should give this answer
        return INVALID_INPUT;
    }
    AVL_tree_node<Artist_arrays>*  currentArtist =  this->mainTreeOfArtists.find_node(artistID);
    if (!currentArtist){ //artist wasn't found
        return FAILURE;
    }
    if( songID >= currentArtist->getElement()->getNumberOfSongs()){
        return INVALID_INPUT;
    }
    *streams = currentArtist->getElement()->getSongNumberOfStreams(songID);
    return SUCCESS;
}



StatusType RemoveArtist(void *DS, int artistID) {
    if (DS == NULL || artistID <= 0 ){
        return INVALID_INPUT;
    }
    return  ((MusicManager *)DS) -> RemoveArtistFromDataCenter(artistID);

}

StatusType MusicManager::RemoveArtistFromDataCenter(int artistID) {
    AVL_tree_node<Artist_arrays>*  currentArtist =  this->mainTreeOfArtists.find_node(artistID);
    if(currentArtist == NULL){
        return FAILURE;
    }
    mainTreeOfArtists.remove(*currentArtist);

    return SUCCESS;
}

void* Init() { ///Insert Memory checks!!!
    MusicManager* mm = new MusicManager();
    return mm;
}




#endif //EX1_DATASTRUCK_MUSICMANAGER_H