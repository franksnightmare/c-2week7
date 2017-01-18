#include "subscribable.ih"

void Subscribable::addThread()
{
	++d_subscribers;
}
