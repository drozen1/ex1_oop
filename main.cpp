#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {

    //2
    int* artists = new int[15];
    int* songs = new int[15];
    int* test = new int();
    void* m = Init();
    MusicManager* mm = ((MusicManager*)m);
    std::cout <<  AddArtist(m,1,1) << std::endl;
    std::cout <<  AddArtist(m,2,2) << std::endl;
    std::cout <<  AddArtist(m,3,3) << std::endl;
    std::cout <<  AddArtist(m,4,4) << std::endl;
    std::cout <<  AddArtist(m,5,5) << std::endl;
    std::cout <<  AddArtist(m,6,6) << std::endl;
    std::cout <<  AddArtist(m,7,7) << std::endl;
    std::cout <<  AddArtist(m,8,8) << std::endl;
    std::cout <<  AddArtist(m,9,9) << std::endl;
    std::cout <<  AddArtist(m,10,10) << std::endl;

    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,2,0) << std::endl;
    std::cout <<  AddToSongCount(m,3,0) << std::endl;
    std::cout <<  AddToSongCount(m,4,0) << std::endl;
    std::cout <<  AddToSongCount(m,5,0) << std::endl;
    std::cout <<  AddToSongCount(m,6,0) << std::endl;
    std::cout <<  AddToSongCount(m,7,0) << std::endl;
    std::cout <<  AddToSongCount(m,8,0) << std::endl;
    std::cout <<  AddToSongCount(m,9,0) << std::endl;
    std::cout <<  AddToSongCount(m,10,0) << std::endl;
    std::cout <<  AddToSongCount(m,10,0) << std::endl;
    std::cout <<  AddToSongCount(m,10,9) << std::endl;


    std::cout <<  AddToSongCount(m,10,9) << std::endl;
    std::cout <<  AddToSongCount(m,10,9) << std::endl;
    std::cout <<  AddToSongCount(m,10,9) << std::endl;
    std::cout <<  AddToSongCount(m,5,4) << std::endl;
    std::cout <<  AddToSongCount(m,5,4) << std::endl;
    std::cout <<  AddToSongCount(m,5,2) << std::endl;

    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;


    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;

    std::cout <<  NumberOfStreams(m,123,3,test) << std::endl;
    std::cout << GetRecommendedSongs(m,3,artists,songs);
    Quit(&m);

    return 0;
}