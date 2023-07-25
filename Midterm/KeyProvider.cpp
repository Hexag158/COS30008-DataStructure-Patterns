#include "KeyProvider.h"

using namespace std;

KeyProvider::KeyProvider(const string& aKeyword) : fKeyword(new char[aKeyword.length()]), fSize(aKeyword.length()), fIndex(0)
{
	initialize(aKeyword);
}

KeyProvider :: ~KeyProvider() 
{
	delete[] fKeyword;
}

void KeyProvider::initialize(const string& aKeyword) 
{
	delete[] fKeyword;
	fKeyword = new char[aKeyword.length()];
	fSize = aKeyword.length();
	for (size_t index = 0; index < fSize; index++)
	{
		fKeyword[index] = static_cast<char>(toupper(aKeyword[index]));
	}
	fIndex = 0;

}

char KeyProvider :: operator*() const 
{
	return fKeyword[fIndex];
};


KeyProvider& KeyProvider::operator<<(char aKeyCharacter) 
{
	fKeyword[fIndex] = static_cast<char>(toupper(aKeyCharacter));
	fIndex+=1;
	if (fSize <= fIndex)
	{
		fIndex = 0;
	}
	return *this;
}

