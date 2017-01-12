#include "semaphore.ih"

Semaphore &Semaphore::subscribeThread()
{
	++d_subscribers;
	return *this;
}
