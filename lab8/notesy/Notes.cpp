//
// Created by CQ07 on 2021-12-05.
//

#include "Notes.h"
string Note::getTitle(){
    return title;
}
void Note::setTitle(string name){
    title = name;
}
string TextNote::getContent(){
    return content;
}
void TextNote::setContent(string txt){
    content = txt;
}