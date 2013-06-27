#include "PageWithCount.h"

PageWithCount::PageWithCount()
{
}
PageWithCount::PageWithCount(const PageWithCount& toCopy) : Page(toCopy)
{
	occurrenceCount = toCopy.GetOccurrenceCount();
}
PageWithCount::~PageWithCount()
{
}

bool PageWithCount::operator<(const PageWithCount& rhs) const
{
	return (occurrenceCount - rhs.GetOccurrenceCount()) < 0;
}
bool PageWithCount::operator>(const PageWithCount& rhs) const
{
	return (occurrenceCount - rhs.GetOccurrenceCount()) > 0;
}
	
int PageWithCount::GetOccurrenceCount() const
{
	return occurrenceCount;
}
void PageWithCount::SetOccurrenceCount(int count)
{
	occurrenceCount = count;
}
void PageWithCount::AddOccurrenceCount(int addCount)
{
	occurrenceCount += addCount;
}

