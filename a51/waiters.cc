#include "semaphore.ih"

size_t Semaphore::waiters() const
{
	return d_waiters;
}
