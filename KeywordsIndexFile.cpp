// Created by fahee on 6/9/2022.
// Opening and accesing the Terms file, which has the keywords stored in them. Creating a buffer to store them.

#include "KeywordsIndexFile.h"
#include <fstream>
#include <iostream>

using namespace std;


KeywordsIndexFile :: KeywordsIndexFile(DSString filename2){
    readfile(filename2);
}

DSVector<Keyword> KeywordsIndexFile :: getWords(){
    return keywords;
}

void KeywordsIndexFile::readfile(DSString arg) {
    ifstream file;
    file.open(arg.c_str());

    char* buffer = new char[1000];

    if(!file.is_open())
    {
        cout<< "Failed Terms.txt";
        exit (1);
    }


    while(!file.eof()){

        file.getline(buffer, 1000);
        DSString line = buffer;

        if(line.getLength() == 0)
        {
            break;
        }

        line.lower_alphabets();
        // setting vector of keywords
        Keyword currentkeyword;
        currentkeyword.keyword= line;
        keywords.pushBack(currentkeyword);
    }

    file.close();
}