#include "semaphore.ih"

Range Semaphore::next()
{
	Range range = d_queue.front();
	d_queue.pop();
	return range;
}
