#include "semaphore.ih"

void Semaphore::wait()
{
	++d_waiters;
	unique_lock<mutex> lock(d_mutex);
	while (d_nAvailable == 0)
	{
		if (d_waiters == d_subscribers)
			return;
		d_condition.wait(lock);
	}
	
	--d_waiters;
	--d_nAvailable;
}
