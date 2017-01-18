#include "semaphore.ih"

bool Semaphore::empty()
{
	lock_guard<mutex> lock(d_mutex);
	return done();
}
