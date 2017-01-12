#include "semaphore.ih"

size_t Semaphore::subscribers() const
{
	return d_subscribers;
}
