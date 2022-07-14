#include "DSVector.h"
#include "PagesInputFile.h"
#include "KeywordsIndexFile.h"
#include "Crossrefrence.h"


using namespace std;

int main(int argc, char ** argv) {
        PagesInputFile page(argv[1]);
        KeywordsIndexFile key (argv[2]);
        Crossrefrence solution(page.getPage(),key.getWords(), argv[3]);
     return 0;
}

