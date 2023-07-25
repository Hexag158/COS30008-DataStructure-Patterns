#include "Vigenere.h"

using namespace std;

Vigenere::Vigenere(const std::string& aKeyword) : fKeywordProvider(KeyProvider(aKeyword)), fKeyword(aKeyword)
{
	initializeTable();
}


void Vigenere::initializeTable()
{
	for (char row = 0; row < CHARACTERS; row++)
	{
		char lChar = 'B' + row;
		for (char column = 0; column < CHARACTERS; column++)
		{
			if (lChar > 'Z')
				lChar = 'A';
			fMappingTable[row][column] = lChar++;
		}
	}
}

string Vigenere :: getCurrentKeyword()
{
	string result;

	for (size_t i = 0;i < fKeyword.length();i++) 
	{
		result += *fKeywordProvider;
		fKeywordProvider << *fKeywordProvider;
	}

	return result;
}

void Vigenere :: reset()
{
	fKeywordProvider.initialize(fKeyword);
}

char Vigenere::encode(char aCharacter) 
{
	if (isalpha(aCharacter))
	{
		bool isLower = islower(aCharacter);
		char encode = fMappingTable[*fKeywordProvider - 'A'][std::toupper(aCharacter) - 'A'];

		fKeywordProvider << aCharacter;

		return isLower ? char(tolower(encode)) : (encode);

	}
	else
	{
		return aCharacter;
	}
}

char Vigenere:: decode(char aCharacter)
{
	if (isalpha(aCharacter))
	{
		char encoded = static_cast<char>(toupper(aCharacter));
		char decode = 0;
		bool isLower = islower(aCharacter);

		for (char col = 0; col < CHARACTERS; col++)
		{
			if (fMappingTable[*fKeywordProvider - 'A'][col] == encoded)
			{
				decode = char(col + 'A');
				break;
			}
		}
		fKeywordProvider << decode;

		return isLower ? char(tolower(decode)) : (decode);
	}
	else
	{
		return aCharacter;
	}
}