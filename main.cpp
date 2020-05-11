#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {





    //2
    int* artists = new int[18];
    int* songs = new int[18];
    int* test = new int();
    void* m = Init();
    MusicManager* mm = ((MusicManager*)m);

    std::cout <<  AddArtist(m,1,1) << std::endl;
    std::cout <<  AddArtist(m,2,2) << std::endl;
    std::cout <<  AddArtist(m,3,3) << std::endl;
    std::cout <<  AddArtist(m,4,4) << std::endl;
    std::cout <<  AddArtist(m,5,5) << std::endl;
//    std::cout <<  AddArtist(m,6,6) << std::endl;
//    std::cout <<  AddArtist(m,7,7) << std::endl;
//    std::cout <<  AddArtist(m,8,8) << std::endl;
//    std::cout <<  AddArtist(m,9,9) << std::endl;
//    std::cout <<  AddArtist(m,10,10) << std::endl;
    std::cout <<"Get0:"<< GetRecommendedSongs(m,0,artists,songs)<< std::endl;

    std::cout <<"Get1:"<< GetRecommendedSongs(m,1,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,1);
    std::cout <<"Get2:"<< GetRecommendedSongs(m,2,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,2);
    std::cout <<"Get14:"<< GetRecommendedSongs(m,14,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,4);
    std::cout <<"Get15:"<< GetRecommendedSongs(m,15,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,15);

    std::cout <<"Get16:"<< GetRecommendedSongs(m,16,artists,songs)<< std::endl;
    std::cout <<"Get17:"<< GetRecommendedSongs(m,17,artists,songs)<< std::endl;
    std::cout <<"Get18:"<< GetRecommendedSongs(m,18,artists,songs)<< std::endl;
    std::cout <<  AddToSongCount(m,5,2) << std::endl;
    std::cout <<  AddToSongCount(m,4,2) << std::endl;
    std::cout <<  AddToSongCount(m,3,1) << std::endl;
    std::cout <<  AddToSongCount(m,5,2) << std::endl;
    std::cout <<  AddToSongCount(m,4,2) << std::endl;
    std::cout <<"Get0:"<< GetRecommendedSongs(m,0,artists,songs)<< std::endl;
    std::cout <<"Get1:"<< GetRecommendedSongs(m,1,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,1);
    std::cout <<"Get2:"<< GetRecommendedSongs(m,2,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,2);
    std::cout <<"Get14:"<< GetRecommendedSongs(m,14,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,14);
    std::cout <<"Get15:"<< GetRecommendedSongs(m,15,artists,songs)<< std::endl;
    mm->print_arr(artists,songs,15);
    std::cout <<"Get16:"<< GetRecommendedSongs(m,16,artists,songs)<< std::endl;
    std::cout <<"Get17:"<< GetRecommendedSongs(m,17,artists,songs)<< std::endl;
    std::cout <<"Get18:"<< GetRecommendedSongs(m,18,artists,songs)<< std::endl;
    std::cout <<  AddToSongCount(m,1,0) << std::endl;
    std::cout <<  AddToSongCount(m,2,0) << std::endl;
    std::cout <<  AddToSongCount(m,2,1) << std::endl;
    std::cout <<  AddToSongCount(m,3,0) << std::endl;
    std::cout <<  AddToSongCount(m,3,2) << std::endl;
    std::cout <<  AddToSongCount(m,4,0) << std::endl;
    std::cout <<  AddToSongCount(m,4,1) << std::endl;
    std::cout <<  AddToSongCount(m,4,3) << std::endl;
    std::cout <<  AddToSongCount(m,5,0) << std::endl;
    std::cout <<  AddToSongCount(m,5,1) << std::endl;
    std::cout <<  AddToSongCount(m,5,3) << std::endl;
    std::cout <<  AddToSongCount(m,5,4) << std::endl;

    std::cout <<"Get0:"<< GetRecommendedSongs(m,0,artists,songs)<< std::endl;
    std::cout <<"Get1:"<< GetRecommendedSongs(m,1,artists,songs)<< std::endl;

    std::cout <<"Get2:"<< GetRecommendedSongs(m,2,artists,songs)<< std::endl;
    std::cout <<"Get14:"<< GetRecommendedSongs(m,14,artists,songs)<< std::endl;
    std::cout <<"Get15:"<< GetRecommendedSongs(m,15,artists,songs)<< std::endl;

    std::cout <<"Get16:"<< GetRecommendedSongs(m,16,artists,songs)<< std::endl;
    std::cout <<"Get17:"<< GetRecommendedSongs(m,17,artists,songs)<< std::endl;
    std::cout <<"Get18:"<< GetRecommendedSongs(m,18,artists,songs)<< std::endl;

    ///remove 4

    std::cout <<  RemoveArtist(m,4) << std::endl;


//
//    AddToSongCount 1 0
//    AddToSongCount 2 0
//    AddToSongCount 2 1
//    AddToSongCount 3 0
//    AddToSongCount 3 2
//    AddToSongCount 4 0
//    AddToSongCount 4 1
//    AddToSongCount 4 3
//    AddToSongCount 5 0
//    AddToSongCount 5 1
//    AddToSongCount 5 3
//    AddToSongCount 5 4


//    std::cout <<  AddToSongCount(m,6,0) << std::endl;
//    std::cout <<  AddToSongCount(m,7,0) << std::endl;
//    std::cout <<  AddToSongCount(m,8,0) << std::endl;
//    std::cout <<  AddToSongCount(m,9,0) << std::endl;
//    std::cout <<  AddToSongCount(m,10,0) << std::endl;
//    std::cout <<  AddToSongCount(m,10,0) << std::endl;
//    std::cout <<  AddToSongCount(m,10,9) << std::endl;
//    std::cout <<  AddToSongCount(m,10,9) << std::endl;
//    std::cout <<  AddToSongCount(m,10,9) << std::endl;
//    std::cout <<  AddToSongCount(m,10,9) << std::endl;
//    std::cout <<  AddToSongCount(m,5,4) << std::endl;
//    std::cout <<  AddToSongCount(m,5,4) << std::endl;
//    std::cout <<  AddToSongCount(m,5,2) << std::endl;
//
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//    std::cout <<  AddToSongCount(m,4,3) << std::endl;
//
//
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;
//    std::cout <<  AddToSongCount(m,1,0) << std::endl;

//    std::cout <<  NumberOfStreams(m,123,3,test) << std::endl;
//    std::cout << GetRecommendedSongs(m,3,artists,songs);
    Quit(&m);

    return 0;
}