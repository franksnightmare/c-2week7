#include "saferangequeue.ih"

SafeRangeQueue &SafeRangeQueue::addThread()
{
	Subscribable::addThread();
	return *this;
}
