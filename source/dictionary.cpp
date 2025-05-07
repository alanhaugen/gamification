#include "dictionary.h"
#include "japanesekana.h"

void Dictionary::SortLexemes()
{
    // Bubble sort
    for (unsigned int i = 0; i < lexemes.Size(); i++)
    {
        for (unsigned int j = 0; j < lexemes.Size(); j++)
        {
            if (lexemes[i].timesAnsweredCorrectly < lexemes[j].timesAnsweredCorrectly)
            {
                Lexeme temp = lexemes[i];

                lexemes[i] = lexemes[j];
                lexemes[j] = temp;
            }
        }
    }
}

Dictionary::Dictionary()
{
    lexemes.Add(Lexeme(Kana::mo+Kana::no, "'mono': a thing"));
    lexemes.Add(Lexeme(Kana::ko+Kana::ko, "'koko': a person"));
    //lexemes.Add(Lexeme(Kana::ka+Kana::ko, "'koko': the past"));
    lexemes.Add(Lexeme(Kana::ka+Kana::sa, "'kako': an umbrella"));
    lexemes.Add(Lexeme(Kana::mo+Kana::mo, "'momo': a peach"));
}

Stack<Lexeme> Dictionary::GetLexemeStack()
{
    Stack<Lexeme> stack;

    SortLexemes();

    for (int i = 0; i < 4; i++)
    {
        stack.Push(lexemes[i]);
    }

    return stack;
}

Lexeme::Lexeme()
{
    timesAnsweredCorrectly = 0;
}

Lexeme::Lexeme(String word_, String translation_)
{
    word = word_;
    translation = translation_;
    timesAnsweredCorrectly = 0;
}
