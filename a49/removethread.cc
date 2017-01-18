#include "subscribable.ih"

void Subscribable::removeThread()
{
	--d_subscribers;
	--d_waiters;
}
