#include "semaphore.ih"

void Semaphore::subscribeThread()
{
	++d_subscribers;
}
