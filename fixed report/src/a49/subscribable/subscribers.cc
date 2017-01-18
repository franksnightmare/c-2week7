#include "subscribable.ih"

size_t Subscribable::subscribers() const
{
	return d_subscribers;
}
