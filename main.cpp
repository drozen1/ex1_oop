#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {

    int* artists = new int[3];
    int* songs = new int[3];
    int* test = new int();
    void* m = Init();
    MusicManager* mm = ((MusicManager*)m);
    std::cout <<  AddArtist(m,123,5) << std::endl;
    std::cout <<  AddArtist(m,456,3) << std::endl;
    std::cout <<  AddArtist(m,123,3) << std::endl;
    std::cout <<  AddArtist(m,-1,10) << std::endl;
    std::cout <<  RemoveArtist(m,456) << std::endl;
    std::cout <<  RemoveArtist(m,789) << std::endl;
    std::cout <<  AddToSongCount(m,123,3) << std::endl;
    std::cout <<  NumberOfStreams(m,123,3,test) << std::endl;
    std::cout << GetRecommendedSongs(m,3,artists,songs);
    Quit(&m);

    return 0;
}