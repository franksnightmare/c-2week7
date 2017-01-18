#include "saferangequeue.ih"

void SafeRangeQueue::push(Range range)
{
	{
		lock_guard<mutex> lock(d_mutex);
		d_queue.push(range);
		++d_nAvailable;
	}
	notify_all();
}
