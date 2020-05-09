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
   void incrementSong(int index);
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

    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *getPointerToListOfStreams() const;

    int getArtistId() const;

    int *getSongNumberOfStreams1() const;

    Link_Node<AVL_tree<AVL_tree<int>>> **getArrayOfPointers() const;
};

void Artist_arrays::incrementSong(int index) {
    this->songNumberOfStreams[index]++;
    return;
}

Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *Artist_arrays::getPointerToListOfStreams() const {
    return pointerToListOfStreams;
}

int Artist_arrays::getArtistId() const {
    return artistID;
}

int *Artist_arrays::getSongNumberOfStreams1() const {
    return songNumberOfStreams;
}

Link_Node<AVL_tree<AVL_tree<int>>> **Artist_arrays::getArrayOfPointers() const {
    return arrayOfPointers;
}

class MusicManager {
    private:
    AVL_tree<Artist_arrays> mainTreeOfArtists;
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> listOfStreams;
    public:

    StatusType RemoveArtistFromDataCenter(int artistID);
    StatusType AddDataCenter(int artistID, int  numOfSongs);
    StatusType MMGetNumberOfStreams(int artistID, int songID,int *streams);
    StatusType MMAddToSongCount( int artistID, int songID);

    void handleCaseOfNewNodeInsertion(Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *pList,
                                      Link_Node<AVL_tree<AVL_tree<int>>> *pNode,
                                      Link_Node<AVL_tree<AVL_tree<int>>> *pNode1);
};
void* Init();
StatusType RemoveArtist(void *DS, int artistID);
StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);
StatusType AddArtist(void *DS, int artistID, int numOfSongs);
StatusType AddToSongCount(void *DS, int artistID, int songID);
//StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);
//void Quit(void** DS);

StatusType AddArtist(void *DS, int artistID, int numOfSongs) {
    if (DS == NULL || artistID <= 0 || numOfSongs<=0){
        return INVALID_INPUT;
    }
    return ((MusicManager *)DS)-> AddDataCenter(artistID, numOfSongs);
}

StatusType AddToSongCount(void *DS, int artistID, int songID){
    if (DS == NULL || artistID <= 0 || songID<0){
        return INVALID_INPUT;
    }
    return ((MusicManager *)DS)-> MMAddToSongCount(artistID, songID);
}

StatusType MusicManager::MMAddToSongCount(int artistID, int songID) {
    AVL_tree_node<Artist_arrays>*  currentArtist =  this->mainTreeOfArtists.find_node(artistID);
    if (!currentArtist){ //artist wasn't found
        return FAILURE;
    }
    if( songID >= currentArtist->getElement()->getNumberOfSongs()){
        return INVALID_INPUT;
    }
    Link_Node<AVL_tree<AVL_tree<int>>>* current_list_node = currentArtist->getElement()->getArrayOfPointers()[songID];
    ///num of streams ++
    currentArtist->getElement()->incrementSong(songID);
    int current_num_of_streams = current_list_node->getNum(); //can also take from the int* array in artist array
    ///remove song from current song tree
    AVL_tree<int>* current_song_tree= current_list_node->getElement()->find_node(artistID)->getElement();
    AVL_tree_node<int>* song_to_push=new AVL_tree_node<int>(songID);
    current_song_tree->remove(*song_to_push);
    Link_Node<AVL_tree<AVL_tree<int>>>* next_list_node= current_list_node->getNext();
    Link_Node<AVL_tree<AVL_tree<int>>>* prev_list_node= current_list_node->getPrev();
    bool curNodeWasRemoved= false;
    ///song tree after removal is now empty
    if(current_song_tree->getRoot()==NULL){
        AVL_tree_node<AVL_tree<int>> dummy_artist(NULL,artistID);
        current_list_node->getElement()->remove(dummy_artist);
    }
    /// artist tree is now empty, so, you delete the node from the list
    if(current_list_node->getElement()->getRoot()==NULL){
        currentArtist->getElement()->getPointerToListOfStreams()->removeNodeFromList(current_list_node);
        curNodeWasRemoved=true;
    }
    if(next_list_node==NULL || next_list_node->getNum()!=current_num_of_streams+1){
        ///create new list node
        AVL_tree<int>* new_song_tree= new AVL_tree<int>();
        new_song_tree->insert(*song_to_push);
        //handle memory errors
        AVL_tree_node<AVL_tree<int>>* new_artist_node= new AVL_tree_node<AVL_tree<int>>(new_song_tree, artistID);
        AVL_tree<AVL_tree<int>>* new_artist_tree = new AVL_tree<AVL_tree<int>>(new_artist_node);
        new_artist_tree->insert(*new_artist_node);
        Link_Node<AVL_tree<AVL_tree<int>>>* new_list_node = new Link_Node<AVL_tree<AVL_tree<int>>>(current_num_of_streams+1,new_artist_tree);
        if(curNodeWasRemoved){
            handleCaseOfNewNodeInsertion(currentArtist->getElement()->getPointerToListOfStreams(), prev_list_node,new_list_node);
        }
        else{
            handleCaseOfNewNodeInsertion(currentArtist->getElement()->getPointerToListOfStreams(), current_list_node,new_list_node);
        }
    }
    else{
        ///pushing the song to the next list node
        AVL_tree_node<AVL_tree<int>>* next_artist_tree_node= next_list_node->getElement()->find_node(artistID);
        if (next_artist_tree_node!=NULL){
            ///check if the next artist tree contain our artist ID
            next_artist_tree_node->getElement()->insert(*song_to_push);
        } else{
            AVL_tree_node<AVL_tree<int>>* new_artist_node= new AVL_tree_node<AVL_tree<int>>(artistID);
            new_artist_node->getElement()->insert(*song_to_push);
            current_list_node->getElement()->insert(*new_artist_node);
        }
    }
    //if(next_list_node==NULL){
    //    AVL_tree<int>* new_song_tree=A
    //    Link_Node<AVL_tree<AVL_tree<int>>>* new_node_list= Link_Node<AVL_tree<AVL_tree<int>>>(current_num_of_streams+1, )
    //}

    ///adding song to the next node

    return SUCCESS;
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

void MusicManager::handleCaseOfNewNodeInsertion(Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *pList,
                                                Link_Node<AVL_tree<AVL_tree<int>>> *pNode,
                                                Link_Node<AVL_tree<AVL_tree<int>>> *pNode1) {
    pList->setNewNodeAfterNode(pNode,pNode1);
}


void* Init() { ///Insert Memory checks!!!
    MusicManager* mm = new MusicManager();
    return mm;
}




#endif //EX1_DATASTRUCK_MUSICMANAGER_H