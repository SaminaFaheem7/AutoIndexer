// Created by fahee on 6/9/2022.

#ifndef INC_22SU_PA02_CROSSREFRENCE_H
#define INC_22SU_PA02_CROSSREFRENCE_H

#include "DSString.h"
#include "DSVector.h"
#include "Page.h"
#include "Keyword.h"

class Crossrefrence {
public:
    Crossrefrence(DSVector<Page>,DSVector<Keyword>, DSString output);

private:
    void Crossrefrencing();
    DSVector<Keyword> keywords;
    DSVector<Page> pages;
    void Outputfile(DSString output);
};
#endif //INC_22SU_PA02_CROSSREFRENCE_H
