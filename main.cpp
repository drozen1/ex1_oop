#include <iostream>
#include "AVL_tree.h"
#include "Doubly_linked_list.h"
#include "MusicManager.h"

int main() {
    void* m = Init();
    MusicManager* mm = ((MusicManager*)m);
    AddArtist(mm, 12,5);
  //  AddArtist(mm,2,5);
 //   RemoveArtist(mm, 2);
    AddToSongCount(mm,12,2);
    return 0;
}