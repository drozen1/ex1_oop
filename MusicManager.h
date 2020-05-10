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
~Artist_arrays() {
    delete[] (songNumberOfStreams);
    delete[] (arrayOfPointers);
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
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> listOfStreams;
    AVL_tree<Artist_arrays> mainTreeOfArtists;
    int totalNumberOfSongs;
public:
    int getTotalNumberOfSongs() const;

    void setTotalNumberOfSongs(int totalNumberOfSongs);

public:
    MusicManager(): totalNumberOfSongs(0){}

    StatusType RemoveArtistFromDataCenter(int artistID);
    StatusType AddDataCenter(int artistID, int  numOfSongs);
    StatusType MMGetNumberOfStreams(int artistID, int songID,int *streams);
    StatusType MMAddToSongCount( int artistID, int songID);
    StatusType GetRecommendedSongs(int numOfSongs, int *artists, int *songs);

    void handleCaseOfNewNodeInsertion(Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *pList,
                                      Link_Node<AVL_tree<AVL_tree<int>>> *pNode,
                                      Link_Node<AVL_tree<AVL_tree<int>>> *pNode1);
    ~MusicManager();

};
void* Init();
StatusType RemoveArtist(void *DS, int artistID);
StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);
StatusType AddArtist(void *DS, int artistID, int numOfSongs);
StatusType AddToSongCount(void *DS, int artistID, int songID);
StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);
void move_artists_from_min(AVL_tree_node<AVL_tree<int>> *cur,AVL_tree_node<AVL_tree<int>> *last, int* current_song_index,int numOfSongs,  int *artists, int *songs);

void print_songs_from_min(AVL_tree_node<int> *cur,AVL_tree_node<int> *last, int* current_song_index,int numOfSongs,  int *artists, int *songs, int artistID);


void Quit(void** DS);

void Quit(void** DS){
    if (DS == NULL){
        return;
    }
    else{
        delete ((MusicManager *)*DS);
        *DS = NULL;
    }

}

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
    AVL_tree_node<int>* song_to_push=new AVL_tree_node<int>(NULL,songID);
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
        currentArtist->getElement()->getArrayOfPointers()[songID]=new_list_node;
    }
    else{
        ///pushing the song to the next list node
        AVL_tree_node<AVL_tree<int>>* next_artist_tree_node= next_list_node->getElement()->find_node(artistID);
        if(next_artist_tree_node==NULL){
            ///no artist tree of the current artist in the next node
            AVL_tree<int>* new_song_tree= new AVL_tree<int>();
            new_song_tree->insert(*song_to_push);
            next_artist_tree_node= new AVL_tree_node<AVL_tree<int>>(new_song_tree,artistID);
            next_list_node->getElement()->insert(*next_artist_tree_node);
        }
        else {
            ///check if the next artist tree contain our artist ID
            next_artist_tree_node->getElement()->insert(*song_to_push);
        }
        currentArtist->getElement()->getArrayOfPointers()[songID]=next_list_node;
    }
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
    this->setTotalNumberOfSongs(totalNumberOfSongs + numOfSongs);
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

void insertNullPointers(Link_Node<AVL_tree<AVL_tree<int>>> ** arrayOfPointers , AVL_tree_node<int >* p){
    if (p == NULL){
        return;
    }
    insertNullPointers(arrayOfPointers,p->getLeftSon());
    insertNullPointers(arrayOfPointers,p->getRightSon());
    arrayOfPointers[p->getKey()]=NULL;
}


StatusType MusicManager::RemoveArtistFromDataCenter(int artistID) {
    AVL_tree_node<Artist_arrays> *currentArtist = this->mainTreeOfArtists.find_node(artistID);
    if (currentArtist == NULL) {
        return FAILURE;
    }
    int numberOfSongs = currentArtist->getElement()->getNumberOfSongs();
    Link_Node<AVL_tree<AVL_tree<int>>> **arrayOfPointers = currentArtist->getElement()->getArrayOfPointers();
    Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *pointerToListOfStreams = currentArtist->getElement()->getPointerToListOfStreams();
    AVL_tree_node<AVL_tree<int>> dummyNode = AVL_tree_node<AVL_tree<int>>(NULL, artistID);
    for (int i = 0; i < numberOfSongs; i++) {
        if (arrayOfPointers[i] != NULL) {
            Link_Node<AVL_tree<AVL_tree<int>>>* ptrToCurrentNodeInList = arrayOfPointers[i];
            AVL_tree<AVL_tree<int>>* ptrToCurrentTreeOfArtists = arrayOfPointers[i]->getElement();

            insertNullPointers(currentArtist->getElement()->getArrayOfPointers(),
                    arrayOfPointers[i]->getElement()->find_node(artistID)->getElement()->getRoot() );
            //arrayOfPointers[i]->getElement()->getRoot()->getElement()->getRoot()

            ptrToCurrentTreeOfArtists->remove(dummyNode);
            if (ptrToCurrentTreeOfArtists->getRoot() == NULL) {
//               arrayOfPointers[i]->setElement(NULL);
                pointerToListOfStreams->removeNodeFromList(ptrToCurrentNodeInList);
            }
        }
    }
    int numberOfGivenArtistSongs = currentArtist->getElement()->getNumberOfSongs();
    this->mainTreeOfArtists.remove(*currentArtist);
    this->setTotalNumberOfSongs(this->totalNumberOfSongs - numberOfGivenArtistSongs);
    return SUCCESS;
}



void MusicManager::handleCaseOfNewNodeInsertion(Doubly_Linked_List<AVL_tree<AVL_tree<int>>> *pList,
                                                Link_Node<AVL_tree<AVL_tree<int>>> *pNode,
                                                Link_Node<AVL_tree<AVL_tree<int>>> *pNode1) {
    pList->setNewNodeAfterNode(pNode,pNode1);
}

MusicManager::~MusicManager() {

}

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs){
    if(DS == NULL || numOfSongs<=0){
        return INVALID_INPUT;
    }
    return ((MusicManager *)DS) -> GetRecommendedSongs(numOfSongs,artists,songs);
}

StatusType MusicManager::GetRecommendedSongs(int numOfSongs, int *artists, int *songs) {
    if (numOfSongs > this->getTotalNumberOfSongs()){
        return FAILURE;
    }
    Link_Node<AVL_tree<AVL_tree<int>>>* current_list_node=this->listOfStreams.getLast();
    int current_song_number= 0;

    while (current_song_number<numOfSongs && current_list_node!=NULL){

         //  move_artists_from_min(current_list_node->getElement().g)
           move_artists_from_min(current_list_node->getElement()->getMinimum(),NULL,&current_song_number,numOfSongs,artists,songs);
           current_list_node=current_list_node->getPrev();
    }

    return SUCCESS;
}

int MusicManager::getTotalNumberOfSongs() const {
    return totalNumberOfSongs;
}

void MusicManager::setTotalNumberOfSongs(int totalNumberOfSongs) {
    MusicManager::totalNumberOfSongs = totalNumberOfSongs;
}


void* Init() { ///Insert Memory checks!!!
    MusicManager* mm = new MusicManager();
    return mm;
}



void move_artists_from_min(AVL_tree_node<AVL_tree<int>> *cur,AVL_tree_node<AVL_tree<int>> *last,
                                              int* current_song_index,int numOfSongs,  int *artists, int *songs) {
    if(numOfSongs==*current_song_index){
        return;
    }
    if(cur==NULL){
        if(last->getRightSon()==NULL &&last->getParent()!=NULL){
            move_artists_from_min(last->getParent(),last,current_song_index,numOfSongs,artists,songs);
        }
        return;
    }else{
        ///travel left
        if(cur->getLeftSon()!=NULL && last!=NULL && cur->getParent()!=NULL
           && cur->getParent()->getKey()==last->getKey()) {
            move_artists_from_min(cur->getLeftSon(), cur,current_song_index,numOfSongs,artists,songs);
            return;
        }
    }
    ///finish to travel left
    if(((cur->getLeftSon()==NULL && last==NULL) ||(last!=NULL&&
                                                   cur->getLeftSon()!=NULL&& cur->getLeftSon()->getKey()==last->getKey()))){
        print_songs_from_min(cur->getElement()->getMinimum(),NULL,current_song_index,numOfSongs,artists,songs,cur->getKey());
        last = cur;
        cur = cur->getRightSon();
        move_artists_from_min(cur, last,current_song_index,numOfSongs,artists,songs);
        return;
    }
    else {
        if (cur->isLeaf()){
            print_songs_from_min(cur->getElement()->getMinimum(),NULL,current_song_index,numOfSongs,artists,songs,cur->getKey());
            last=cur;
            cur = cur->getParent();
            move_artists_from_min(cur,last,current_song_index,numOfSongs,artists,songs);
            return;
        }
    }
    if(cur->getLeftSon()==NULL&&cur->getRightSon()!=NULL&&
       last!=NULL&&cur->getParent()!=NULL&&
       cur->getParent()->getKey()==last->getKey()){
        print_songs_from_min(cur->getElement()->getMinimum(),NULL,current_song_index,numOfSongs,artists,songs,cur->getKey());
    }
    ///travel right
    if(cur->getRightSon()!=NULL && last!=NULL && cur->getRightSon()->getKey()!=last->getKey()) {
        move_artists_from_min(cur->getRightSon(), cur,current_song_index,numOfSongs,artists,songs);
        return;
    }
    ///finish to travel right
    if( (cur->getRightSon()==NULL&&last==NULL)||
        (cur->getRightSon()!=NULL&& cur->getRightSon()->getKey()==last->getKey())){
        last=cur;
        cur=cur->getParent();
        move_artists_from_min(cur,last,current_song_index,numOfSongs,artists,songs);
    }

    return;
}



void print_songs_from_min(AVL_tree_node<int> *cur,AVL_tree_node<int> *last,
                                             int* current_song_index,int numOfSongs,  int *artists, int *songs, int artistID) {
    if(numOfSongs==*current_song_index){
        return;
    }
    if (cur == NULL) {
        if (last->getRightSon() == NULL && last->getParent() != NULL) {
            print_songs_from_min(last->getParent(), last ,current_song_index,numOfSongs,artists,songs,artistID);
        }
        return;
    } else {
        ///travel left
        if (cur->getLeftSon() != NULL && last != NULL && cur->getParent() != NULL
            && cur->getParent()->getKey() == last->getKey()) {
            print_songs_from_min(cur->getLeftSon(), cur,current_song_index,numOfSongs,artists,songs,artistID);
            return;
        }

    }
    ///finish to travel left
    if (((cur->getLeftSon() == NULL && last == NULL) || (last != NULL &&
                                                         cur->getLeftSon() != NULL &&
                                                         cur->getLeftSon()->getKey() == last->getKey()))) {

        artists[*current_song_index]=artistID;
        songs[*current_song_index]=cur->getKey();
        *current_song_index=*current_song_index+1;

        last = cur;
        cur = cur->getRightSon();
        print_songs_from_min(cur, last,current_song_index,numOfSongs,artists,songs,artistID);
        return;
    } else {
        if (cur->isLeaf()) {
            artists[*current_song_index]=artistID;
            songs[*current_song_index]=cur->getKey();
            *current_song_index=*current_song_index+1;
            last = cur;
            cur = cur->getParent();
            print_songs_from_min(cur, last,current_song_index,numOfSongs,artists,songs,artistID);
            return;
        }
    }
    if (cur->getLeftSon() == NULL && cur->getRightSon() != NULL &&
        last != NULL && cur->getParent() != NULL &&
        cur->getParent()->getKey() == last->getKey()) {
        artists[*current_song_index]=artistID;
        songs[*current_song_index]=cur->getKey();
        *current_song_index=*current_song_index+1;
    }
    ///travel right
    if (cur->getRightSon() != NULL && last != NULL && cur->getRightSon()->getKey() != last->getKey()) {
        print_songs_from_min(cur->getRightSon(), cur,current_song_index,numOfSongs,artists,songs,artistID);
        return;
    }
    ///finish to travel right
    if ((cur->getRightSon() == NULL && last == NULL) ||
        (cur->getRightSon() != NULL && cur->getRightSon()->getKey() == last->getKey())) {
        last = cur;
        cur = cur->getParent();
        print_songs_from_min(cur, last,current_song_index,numOfSongs,artists,songs,artistID);
    }
    return;

}



#endif //EX1_DATASTRUCK_MUSICMANAGER_H