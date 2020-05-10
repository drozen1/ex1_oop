#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {
    int* test = NULL;
    void* m = Init();
    MusicManager* mm = ((MusicManager*)m);
    AddArtist(m,123,5);
    AddArtist(m,456,3);
    AddArtist(m,123,3);
    AddArtist(m,-1,10);
    RemoveArtist(m,456);
    RemoveArtist(m,789);

    Quit(&m);

    return 0;
}