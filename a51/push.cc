#include "safequeue.ih"

void SafeQueue::push(DotPair pair)
{
	{
		lock_guard<mutex> lock(d_mutex);
		d_queue.push(pair);
		++d_nAvailable;
	}
	notify_all();
}
