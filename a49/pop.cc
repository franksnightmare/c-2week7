#include "saferangequeue.ih"

Range SafeRangeQueue::pop()
{
	d_mutex.lock();
	Range range = d_queue.front();
	d_queue.pop();
	d_mutex.unlock();
	
	return range;
}
