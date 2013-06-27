#include "Word.h"

Word::Word()
{
}
Word::~Word()
{
}
	
const QString& Word::GetValue() const
{
	return wordValue;
}
void Word::SetValue(const QString& value)
{
	wordValue = value;
}
	
int Word::GetOccurrence(const QString& url) const
{
	int result = 0;
	if(wordOccurrences.contains(url))
	{
		result = wordOccurrences[url];
	}
	return result;
}
void Word::SetOccurrence(const QString& url, int occurrence)
{
	if(wordOccurrences.contains(url))
	{
		wordOccurrences[url] = occurrence;
	}
	else
	{
		wordOccurrences.insert(url, occurrence);
	}
}

QList<QString> Word::GetContainingUrls() const
{
	return wordOccurrences.keys();
}
