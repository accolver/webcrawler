#ifndef WORD_H
#define WORD_H

#include <QString>
#include <QList>
#include <QHash>

class Word
{
public:
	Word();
	virtual ~Word();
	
	const QString& GetValue() const;
	void SetValue(const QString& value);
	
	int GetOccurrence(const QString& url) const;
	void SetOccurrence(const QString& url, int occurrence);
	
	QList<QString> GetContainingUrls() const;

private:
	QString wordValue;
	QHash<QString,int> wordOccurrences;
};

#endif

