// Created by fahee on 6/9/2022.

#ifndef INC_22SU_PA02_KEYWORD_H
#define INC_22SU_PA02_KEYWORD_H

#include "DSVector.h"
#include "DSString.h"

class Keyword{
public:
    DSString keyword;
    DSVector<DSString> pageson;

    bool operator<  (const Keyword& arg)const{
        return keyword < arg.keyword;
    }

    Keyword& operator= (const Keyword& arg){
        keyword = arg.keyword;
        pageson =arg.pageson;
        return *this;
    }
};


#endif //INC_22SU_PA02_KEYWORD_H
