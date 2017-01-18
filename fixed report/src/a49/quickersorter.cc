#include "main.ih"

void quickerSorter(SafeRangeQueue &nextRange)
{
	while (true)
	{
		nextRange.wait();
		
		if (nextRange.empty())
		{
			nextRange.removeThread();
			nextRange.notify_all();
			return;
		}
		
		quickerSort(nextRange);
	}
}
