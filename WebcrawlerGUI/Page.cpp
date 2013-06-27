#include "Page.h"


Page::Page()
{
}
Page::Page(const Page& toCopy)
{
	pageUrl = toCopy.GetURL();
	pageDescription = toCopy.GetDescription();
}
Page::~Page()
{
}

bool Page::operator<(const Page& rhs) const
{
	return pageDescription < rhs.GetDescription();
}
bool Page::operator>(const Page& rhs) const
{
	return pageDescription > rhs.GetDescription();
}
	
	
const QString& Page::GetURL() const
{
	return pageUrl;
}
void Page::SetURL(const QString& url)
{
	pageUrl = url;
}
	
const QString& Page::GetDescription() const
{
	return pageDescription;
}
void Page::SetDescription(const QString& description)
{
	pageDescription = description;
}

