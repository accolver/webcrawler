#ifndef PAGE_WITH_COUNT_H
#define PAGE_WITH_COUNT_H

#include "Page.h"

class PageWithCount : public Page
{
public:
	PageWithCount();
	PageWithCount(const PageWithCount& toCopy);
	virtual ~PageWithCount();
	
	virtual bool operator<(const PageWithCount& rhs) const;
	virtual bool operator>(const PageWithCount& rhs) const;
	
	int GetOccurrenceCount() const;
	void SetOccurrenceCount(int count);
	/**
	 * Add the given addCount to the current occurrence count of this page.
	 */
	void AddOccurrenceCount(int addCount);

private:
	int occurrenceCount;
};

#endif

