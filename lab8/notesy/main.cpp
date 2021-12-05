#include <iostream>
#include "Notes.h"
int main()
{
    TextNote notatka1("notatka1", "");
    cout<<"Podaj jak ma sie nazywac nowa notatka: "<<endl;
    string name, line;
    cin>> name;
    notatka1.setTitle(name);
    getline(cin, line);
    cout<<"Podaj co ma zawierac notatka o nazwie \""<<notatka1.getTitle()<<"\": "<<endl;
    getline(cin, line);
    notatka1.setContent(line);
    cout<<notatka1.getTitle()<<": "<<endl;
    cout<<notatka1.getContent()<<endl;
    return 0;
}
