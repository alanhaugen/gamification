#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <core/containers/array.h>
#include <core/x-platform/string.h>

class Dictionary
{
public:
    Dictionary();
    Array<String> words;
};

#endif // DICTIONARY_H
