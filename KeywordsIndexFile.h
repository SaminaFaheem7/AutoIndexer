// Created by fahee on 6/9/2022.

#ifndef INC_22SU_PA02_KEYWORDSINDEXFILE_H
#define INC_22SU_PA02_KEYWORDSINDEXFILE_H

#include "DSString.h"
#include "DSVector.h"
#include "Keyword.h"

class KeywordsIndexFile {
public:
    KeywordsIndexFile(DSString filename2);
    DSVector<Keyword> getWords();

private:
    void readfile(DSString);
    DSVector<Keyword> keywords;

};
#endif //INC_22SU_PA02_KEYWORDSINDEXFILE_H
