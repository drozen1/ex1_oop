//
// Created by Dor on 28/04/2020.
//

#include "library1.h"

void *Init(){}

StatusType AddArtist(void *DS, int artistID, int numOfSongs);

StatusType RemoveArtist(void *DS, int artistID);

StatusType AddToSongCount(void *DS, int artistID, int songID);

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams);

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs);