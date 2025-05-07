#include "dictionary.h"
#include <string>
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
    lexemes.Add(Lexeme((std::string(1, Kana::mo)+std::string(1, Kana::no)).c_str(), "'mono': a thing"));
    lexemes.Add(Lexeme((std::string(1, Kana::ko)+std::string(1, Kana::ko)).c_str(), "'koko': a person"));
    lexemes.Add(Lexeme((std::string(1, Kana::ka)+std::string(1, Kana::ko)).c_str(), "'kako': an umbrella"));
    lexemes.Add(Lexeme((std::string(1, Kana::mo)+std::string(1, Kana::mo)).c_str(), "'momo': a peach"));
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

void Lexeme::IncreaseCompetence()
{
    timesAnsweredCorrectly++;
}
