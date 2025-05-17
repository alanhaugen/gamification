#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <core/containers/array.h>
#include <core/containers/stack.h>
#include <core/x-platform/string.h>

class Lexeme
{
public:
    Lexeme();
    Lexeme(String word_, String translation_);

    String word;
    String translation;
    int timesAnsweredCorrectly;

    void IncreaseCompetence();
    //Audio sayIt;
};

class Dictionary
{
private:
public:
    Dictionary();
    Array<String> words;
    Array<Lexeme> lexemes;
    void SortLexemes();
    bool HasWord(String word);
    String Translate(String word);
};

#endif // DICTIONARY_H
