#include "semaphore.ih"

bool Semaphore::done()
{
	return d_nAvailable == 0;
}
