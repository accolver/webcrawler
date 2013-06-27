#include "CrawlerModel.h"

#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QDomNodeList>
#include <QDomNode>
#include <QDomElement>

#include <QMessageBox>

CrawlerModel::CrawlerModel()
{
	Reset();
}
CrawlerModel::~CrawlerModel()
{
}

QList<Page> CrawlerModel::GetPages() const
{
	return pages.values();
}
QList<Word> CrawlerModel::GetWords() const
{
	return words.values();
}

QList<Word> CrawlerModel::GetWordsOnUrl(const QString& url) const
{
	QList<Word> result;
	QList<Word> tempWords = words.values();
	
	for(int i = 0; i < tempWords.length(); i++)
	{
		if(tempWords[i].GetOccurrence(url) > 0)
		{
			result.append(tempWords[i]);
		}
	}
	
	return result;
}

QList<PageWithCount> CrawlerModel::GetAllPagesWithNullCount() const
{
	QList<PageWithCount> result;
		
	QList<Page> pageObjects = pages.values();
	qSort(pageObjects.begin(), pageObjects.end());

	for(int i = 0; i < pageObjects.length(); i++)
	{
		const Page& p = pageObjects[i];
	
		PageWithCount tempPage;
		tempPage.SetOccurrenceCount(0);
		tempPage.SetURL(p.GetURL());
		tempPage.SetDescription(p.GetDescription());
		result.append(tempPage);
	}

	return result;
}

QList<PageWithCount> CrawlerModel::GetPagesContainingWords(const QStringList& wordValues) const
{
	// Url -> PageWithCount
	QHash<QString,PageWithCount> result;
	
	// Get the list of all urls that contain at least one search word.
	for(int searchIndex = 0; searchIndex < wordValues.length(); searchIndex++)
	{
		QString search = wordValues[searchIndex];
		if(words.contains(search))
		{
			QList<QString> urls = words[search].GetContainingUrls();
			
			for(int urlIndex = 0; urlIndex < urls.length(); urlIndex++)
			{
				QString curUrl = urls[urlIndex];
				if(result.contains(curUrl))
				{
					result[curUrl].AddOccurrenceCount(words[search].GetOccurrence(curUrl));
				}
				else
				{
					PageWithCount toAdd;
				
					toAdd.SetURL(curUrl);
					toAdd.SetDescription(pages[curUrl].GetDescription());
					toAdd.SetOccurrenceCount(words[search].GetOccurrence(curUrl));
					
					result.insert(curUrl, toAdd);
				}
			}
		}
	}
	
	QList<PageWithCount> retResult = result.values();
	qSort(retResult.begin(), retResult.end(), qGreater<PageWithCount>());
	
	// Trim the current result so that it now only contains those urls that contain all search words.
	for(int resultIndex = 0; resultIndex < retResult.length(); resultIndex++)
	{
		const PageWithCount& curPage = retResult[resultIndex];
		
		for(int searchIndex = 0; searchIndex < wordValues.length(); searchIndex++)
		{
			const QString& curWord = wordValues[searchIndex];
			
			if(words[curWord].GetOccurrence(curPage.GetURL()) == 0)
			{
				retResult.removeAt(resultIndex);
				resultIndex--;
				break;
			}
		}
	}
	
	return retResult;
}

void CrawlerModel::Reset()
{
	startUrl = "";
	pages.clear();
	words.clear();
}

void CrawlerModel::LoadFromFile(const QString& fileName)
{
	Reset();
	
	QString warnTitle = "Loading XML File";
	
	if(QFile::exists(fileName) == false)
	{
		QMessageBox::warning(NULL, warnTitle, "Could not find the specified xml file.  No values will be loaded into the program data.");
		return;
	}
	
	QDomDocument doc;
	QFile file(fileName);
	if(file.open(QIODevice::ReadOnly) == false)
	{
		QMessageBox::warning(NULL, warnTitle, "The specified xml file could not be loaded with read only privaledges."); 
		return;
	}
	if(doc.setContent(&file) == false)
	{
		//QMessageBox::warning(NULL, warnTitle, "The specified xml file was not in proper xml format.");
		file.close();
		return;
	}
	
	// website
	QDomElement websiteElem = doc.documentElement();
	if(websiteElem.isNull() || websiteElem.tagName() != "website")
	{
		QMessageBox::warning(NULL, warnTitle, "The first element of the document must be the website element.");
		return;
	}
	
	// start-url
	QDomElement startUrlElem = websiteElem.firstChildElement();
	if(startUrlElem.isNull() || startUrlElem.tagName() != "start-url")
	{
		QMessageBox::warning(NULL, warnTitle, "The first element in the websiteElem element must be the start-url element.");
		return;
	}
	startUrl = startUrlElem.text();
	
	
	// pages
	QDomElement pagesElem = startUrlElem.nextSiblingElement();
	if(pagesElem.isNull() || pagesElem.tagName() != "pages")
	{
		QMessageBox::warning(NULL, warnTitle, "Directly after start-url, the student must have a pages element.");
		return;
	}
	
	// page
	QDomElement pageElem = pagesElem.firstChildElement();
	while(!pageElem.isNull() && pageElem.tagName() == "page")
	{
		// url
		QDomElement urlElem = pageElem.firstChildElement();
		if(urlElem.isNull() || urlElem.tagName() != "url")
		{
			QMessageBox::warning(NULL, warnTitle, "First child of page element should be the url element.");
			return;
		}
		
		// description
		QDomElement descriptionElem = urlElem.nextSiblingElement();
		//if(descriptionElem.isNull() || descriptionElem.tagName() != "description")
		//{
		//	According to the current webcrawler specification, a description element is not necessary.
		//	QMessageBox::warning(NULL, warnTitle, "The next child directly after the url element should be the description element.");
		//	return;
		//}
		
		Page tempPage;
		tempPage.SetURL(urlElem.text());
		tempPage.SetDescription(descriptionElem.text());
		pages.insert(urlElem.text(), tempPage);
		
		pageElem = pageElem.nextSiblingElement();
	}
	
	// index
	QDomElement indexElem = pagesElem.nextSiblingElement();
	if(indexElem.isNull() || indexElem.tagName() != "index")
	{
		// According to the current webcrawler specification, an index element is not necessary.
		//QMessageBox::warning(NULL, warnTitle, "Directly after the pages element should be an index element that contains all of the word elements.");
		return;
	}
	
	// word
	QDomElement wordElem = indexElem.firstChildElement();
	while(!wordElem.isNull() && wordElem.tagName() == "word")
	{
		Word tempWord;
		
		// value
		QDomElement valueElem = wordElem.firstChildElement();
		if(valueElem.isNull() || valueElem.tagName() != "value")
		{
			QMessageBox::warning(NULL, warnTitle, "The first child element of the word element should be value.");
			return;
		}
		
		tempWord.SetValue(valueElem.text());
		
		// occurrence
		QDomElement occurrenceElem = valueElem.nextSiblingElement();
		if(occurrenceElem.isNull() || occurrenceElem.tagName() != "occurrence")
		{
			QMessageBox::warning(NULL, warnTitle, "Directly after the value element of the word element should be at least one occurrence element.");
			return;
		}
		while(!occurrenceElem.isNull() && occurrenceElem.tagName() == "occurrence")
		{
			// url
			QDomElement urlElem = occurrenceElem.firstChildElement();
			if(urlElem.isNull() || urlElem.tagName() != "url")
			{
				QMessageBox::warning(NULL, warnTitle, "The first child element of the occurrence element should be url.");
				return;
			}
		
			// count
			QDomElement countElem = urlElem.nextSiblingElement();
			if(countElem.isNull() || countElem.tagName() != "count")
			{
				QMessageBox::warning(NULL, warnTitle, "The next element after the url in an occurrence element should be the count element.");
				return;
			}
			
			tempWord.SetOccurrence(urlElem.text(), countElem.text().toInt());
			
			occurrenceElem = occurrenceElem.nextSiblingElement();
		}
		
		words.insert(tempWord.GetValue(), tempWord);
		
		wordElem = wordElem.nextSiblingElement();
	}
	
	emit modelChanged();
}







