cmake_minimum_required(VERSION 3.16)
project(AutoIndexer)

set(CMAKE_CXX_STANDARD 14)

# The configure_file statements below ensure that files are copied into the data
# folder that will be created in the build folder.
configure_file(data/test_book.txt data/test_book.txt NEWLINE_STYLE UNIX)
configure_file(data/terms.txt data/terms.txt NEWLINE_STYLE UNIX)

add_executable(AutoIndexer main.cpp DSVector.h DSString.cpp DSString.h PagesInputFile.cpp PagesInputFile.h KeywordsIndexFile.cpp KeywordsIndexFile.h Page.h Crossrefrence.cpp Crossrefrence.h Keyword.h)
add_executable(AutoIndexer_test DSVector.h catch.hpp catch_setup.cpp sample_tests.cpp catch_setup.h DSString.cpp DSString.h PagesInputFile.cpp PagesInputFile.h KeywordsIndexFile.cpp KeywordsIndexFile.h Page.h Crossrefrence.cpp Crossrefrence.h Keyword.h)


