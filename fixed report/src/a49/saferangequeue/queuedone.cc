#include "saferangequeue.ih"

bool SafeRangeQueue::done()
{
	return Semaphore::done()
		&& d_waiters == d_subscribers;
}
