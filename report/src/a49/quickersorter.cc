#include "main.ih"

void quickerSorter(Semaphore &nextRange)
{
	while (true)
	{
		nextRange.wait();
		
		if (nextRange.size() == 0 &&
			nextRange.waiters() == nextRange.subscribers())
		{
			nextRange.desubscribeThread();
			nextRange.notify_all();
			return;
		}
		
		quickerSort(nextRange);
	}
}
