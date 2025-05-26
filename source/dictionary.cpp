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

bool Dictionary::HasWord(String word)
{
    return true;
}

String Dictionary::Translate(String word)
{
    for (unsigned int i = 0; i < lexemes.Size(); i++)
    {
        if (lexemes[i].word == word)
        {
            return lexemes[i].translation;
        }
    }
}

Dictionary::Dictionary()
{
    lexemes.Add(Lexeme((std::string(1, Kana::mo)+std::string(1, Kana::no)).c_str(), "'mono': a thing"));
    lexemes.Add(Lexeme((std::string(1, Kana::ko)+std::string(1, Kana::ko)).c_str(), "'koko': here"));
    lexemes.Add(Lexeme((std::string(1, Kana::ka)+std::string(1, Kana::sa)).c_str(), "'kasa': an umbrella"));
    lexemes.Add(Lexeme((std::string(1, Kana::mo)+std::string(1, Kana::mo)).c_str(), "'momo': a peach"));
    lexemes.Add(Lexeme((std::string(1, Kana::a)+std::string(1, Kana::i)).c_str(), "'ai': love"));
    lexemes.Add(Lexeme((std::string(1, Kana::e)+std::string(1, Kana::ki)).c_str(), "'eki': station"));
    lexemes.Add(Lexeme((std::string(1, Kana::i)+std::string(1, Kana::e)).c_str(), "'ie': house"));
    lexemes.Add(Lexeme((std::string(1, Kana::u)+std::string(1, Kana::e)).c_str(), "'ue': up"));
    lexemes.Add(Lexeme((std::string(1, Kana::ka)+std::string(1, Kana::o)).c_str(), "'kao': face"));
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
