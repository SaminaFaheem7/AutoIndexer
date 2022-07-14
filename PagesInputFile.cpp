// Created by fahee on 6/8/2022.
/* Getting the contents of the textbook(test_book) parsing it.
 * See it its the end of the book or not, by checking the page number, and getting the text from the page.
 * Storing it in a buffer.
*/

#include "PagesInputFile.h"
#include <fstream>
#include <iostream>
using namespace std;

PagesInputFile ::PagesInputFile(DSString filename) {
    readfile(filename);
}

DSVector<Page> PagesInputFile::getPage(){
     return pages;
}

void PagesInputFile::readfile(DSString arg) {
    ifstream file;
    file.open(arg.c_str());

    char* buffer = new char[1000];

    if(!file.is_open())
    {
        cout<< "Failed test_book.txt";
        exit (1);
    }

    Page currentpage;

    while(!file.eof()){
        file.getline(buffer, 1000);
        DSString line = buffer;

        line.lower_alphabets();

        if(line.getLength() ==0)
        {
            continue;
        }

        //Check the page number/ if its the page or not
        if(line[0] == '<') {
            DSString pagenumber;
            pages.pushBack(currentpage);

            //Get the page number
            pagenumber = line.substring(1, line.getLength() - 2);
            if (pagenumber == "-1") {
                break;
            }
            currentpage.pagenumber = pagenumber;
            currentpage.pagetext =  " ";  //resetting
        }
        else{
            DSString temp = currentpage.pagetext + " ";
            temp += line;
            currentpage.pagetext = temp;
                    }
    }
file.close();
}