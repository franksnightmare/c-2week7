#include "subscribable.ih"

size_t Subscribable::waiters() const
{
	return d_waiters;
}
