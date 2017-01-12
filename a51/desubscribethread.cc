#include "semaphore.ih"

void Semaphore::desubscribeThread()
{
	--d_subscribers;
	--d_waiters;
	notify_all();
}
