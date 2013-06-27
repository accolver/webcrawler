#ifndef PAGE_H
#define PAGE_H

#include <QString>

class Page
{
public:
	Page();
	Page(const Page& toCopy);
	virtual ~Page();
	
	virtual bool operator<(const Page& rhs) const;
	virtual bool operator>(const Page& rhs) const;
	
	const QString& GetURL() const;
	void SetURL(const QString& url);
	
	const QString& GetDescription() const;
	void SetDescription(const QString& description);
	
private:
	QString pageUrl;
	QString pageDescription;
};

#endif

