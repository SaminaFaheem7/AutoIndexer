//
// Created by fahee on 6/8/2022.
//

#ifndef INC_22SU_PA02_PAGESINPUTFILE_H
#define INC_22SU_PA02_PAGESINPUTFILE_H

#include "DSString.h"
#include "Page.h"
#include "DSVector.h"

class PagesInputFile {
public:
    PagesInputFile(DSString);
     DSVector<Page> getPage();          // get the page

private:
    void readfile(DSString);
    DSVector<Page> pages;
};


#endif //INC_22SU_PA02_PAGESINPUTFILE_H
