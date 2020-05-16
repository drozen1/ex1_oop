//
// Created by Dor on 28/04/2020.
//

#include "library1.h"
#include "MusicManager.h"


void *Init() { ///Insert Memory checks!!!
    try {
        MusicManager *mm = new MusicManager();
        return mm;
    }
    catch (std::bad_alloc& ba){
        return NULL;
    }
}


StatusType AddArtist(void *DS, int artistID, int numOfSongs) {
    if (DS == NULL || artistID <= 0 || numOfSongs<=0){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->AddDataCenter(artistID, numOfSongs);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveArtist(void *DS, int artistID) {
    if (DS == NULL || artistID <= 0 ){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->RemoveArtistFromDataCenter(artistID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }

}

StatusType AddToSongCount(void *DS, int artistID, int songID){
    if (DS == NULL || artistID <= 0 || songID<0){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->MMAddToSongCount(artistID, songID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType NumberOfStreams(void *DS, int artistID, int songID, int *streams) {
    if(DS == NULL ){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->MMGetNumberOfStreams(artistID, songID, streams);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType GetRecommendedSongs(void *DS, int numOfSongs, int *artists, int *songs){
    if(DS == NULL ){
        return INVALID_INPUT;
    }
    if (numOfSongs<=0){
        return  ALLOCATION_ERROR;
    }
    try {
        return ((MusicManager *) DS)->GetRecommendedSongs(numOfSongs, artists, songs);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}


