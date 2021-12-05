//
// Created by CQ07 on 2021-12-05.
//

#ifndef NOTESY_NOTES_H
#define NOTESY_NOTES_H

#include <iostream>
using namespace std;

class Note {

    string title;
public:
    Note(string name): title(name){};
    string getTitle();
    void setTitle(string name);
    virtual string getContent() = 0;
    virtual void setContent(string txt) = 0;
};

class TextNote : public Note {
protected:
    string content;
public:
    TextNote(string name, string txt): Note(name), content(txt){};
    string getContent();
    void setContent(string txt);
};

#endif //NOTESY_NOTES_H
