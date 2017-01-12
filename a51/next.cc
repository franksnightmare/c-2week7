#include "safequeue.ih"

DotPair SafeQueue::next()
{
	wait();
	
	lock_guard<mutex> lock(d_mutex);
	if (d_queue.size() == 0 && d_waiters == d_subscribers)
	{
		--d_waiters;
		return DotPair(0, 0, 0);
	}
	
	DotPair pair = d_queue.front();
	d_queue.pop();
	return pair;
}
