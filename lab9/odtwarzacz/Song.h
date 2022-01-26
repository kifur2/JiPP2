//
// Created by CQ07 on 2021-12-11.
//

#ifndef ODTWARZACZ_SONG_H
#define ODTWARZACZ_SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song {

    int id;
    string name, artist;

public:
    //Song():id(NULL), name(NULL), artist(NULL){};
    Song(int id, string name, string artist): id(id), name(name), artist(artist){};
    void print();
};

#endif //ODTWARZACZ_SONG_H
