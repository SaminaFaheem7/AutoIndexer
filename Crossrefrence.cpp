// Created by fahee on 6/9/2022.
/* after parsing both the files and having access to all the items in the files,
we need to cross reference the keywords in the terms.txt to the text book,  to find if there word is there or not.
 then Outputting the term, with which page number they belong to in the output file.
*/
#include "Crossrefrence.h"
#include <fstream>

using namespace std;

// each keyword keep track of the pagenumber
Crossrefrence::Crossrefrence(DSVector<Page> pagenum,DSVector<Keyword>word, DSString output) {
    pages=pagenum;
    keywords=word;
    Crossrefrencing();
    Outputfile(output);
}

void Crossrefrence ::Crossrefrencing() {
    //iterate through pages
    for(int i=0; i< pages.getSize(); i++)
    {
        // iterating through the keywords
        for(int j =0; j< keywords.getSize(); j++)
        {
            // if its on the page or not, if not then adding it.
            DSString p = pages[i].pagetext;
            if(pages[i].pagetext.contains(keywords[j].keyword))
            {
                keywords[j].pageson.pushBack(pages[i].pagenumber);
            }
        }
    }
}

// Output file.
void Crossrefrence::Outputfile(DSString output) {
    std::ofstream file;
    file.open(output.c_str());

    keywords.selectionsort();
    char firstchar;   //character in the brackets;
    for (int i = 0; i < keywords.getSize(); i++) {
        if (keywords[i].pageson.getSize() == 0) {
            continue;
        }
        if (keywords[i].keyword[0] != firstchar) {
            firstchar = keywords[i].keyword[0];
            file << "[" << firstchar << "]" << endl;
        }
        file << keywords[i].keyword << ": " << keywords[i].pageson[0];
        for (int j = 1; j < keywords[i].pageson.getSize(); j++) {
            file << ", " << keywords[i].pageson[j];
        }
        file << endl;
    }
    file.close();
}

