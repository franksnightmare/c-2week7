#include "saferangequeue.ih"

void SafeRangeQueue::wait()
{
	++d_waiters;
	Semaphore::wait();
	if (!done())
		--d_waiters;
}
