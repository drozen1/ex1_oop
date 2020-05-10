#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {

    //AVL_tree<int>* check= new AVL_tree<int>(20);
    //check->inOrder(check->getRoot());
    //check->print_from_min(check->getMinimum(),NULL);

//    int* test = NULL;
    void* m = Init();
//    MusicManager* mm = ((MusicManager*)m);
    AddArtist(m,123,5);
    int* artists = new int[3];
    int* songs = new int[3];
    GetRecommendedSongs(m,3,artists,songs);
//    AddArtist(m,456,3);
//    AddArtist(m,123,3);
//    AddArtist(m,-1,10);
//    AddToSongCount(m,123,4);
//    AddToSongCount(m,123,4);
//    RemoveArtist(m,456);
//    RemoveArtist(m,123);
//    Quit(&m);

    return 0;
}