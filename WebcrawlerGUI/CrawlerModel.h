#ifndef CRAWLERMODEL_H
#define CRAWLERMODEL_H

#include <QObject>
#include <QString>
#include <QList>
#include <QHash>

#include "Page.h"
#include "PageWithCount.h"
#include "Word.h"

class CrawlerModel : public QObject
{
	Q_OBJECT
	
public:
	CrawlerModel();
	virtual ~CrawlerModel();
	
	/**
	 * Return a list of all pages stored in this model.
	 */
	QList<Page> GetPages() const;
	/**
	 * Return a list of all words stored in this model.
	 */
	QList<Word> GetWords() const;
	
	/**
	 * Return a list of words that were found on the given url.
	 */
	QList<Word> GetWordsOnUrl(const QString& url) const;
	
	/**
	 * Return a list of all of the pages currently in the model, but all of them are
	 * given a default value of 0 rating.  This is the method that should be called
	 * when the user searches when the search string is empty.
	 */
	QList<PageWithCount> GetAllPagesWithNullCount() const;
	/**
	 * Return a list of pages that contains all of the given word values.
	 * The pages will be sorted according to the sum of the occurrences of
	 * the words being searched for.
	 */
	QList<PageWithCount> GetPagesContainingWords(const QStringList& wordValues) const;
	
	/**
	 * Clear all current data in the model.
	 */
	void Reset();
	
	/**
	 * Load a new model from the given xml file name.
	 */
	void LoadFromFile(const QString& fileName);
	
signals:
	/**
	 * Signal that is emitted whenever the model is changed.
	 */
	void modelChanged();
	
private:
	/**
	 * The start url of this crawling session.
	 */
	QString startUrl;
	
	/**
	 * A QHash of the page url to an actual page object.
	 */
	QHash<QString,Page> pages;
	/**
	 * A QHash of the word's value to the actual word object.
	 */
	QHash<QString,Word> words;
};

#endif

