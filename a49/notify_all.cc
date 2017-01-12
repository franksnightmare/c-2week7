#include "semaphore.ih"

void Semaphore::notify_all()
{
	lock_guard<mutex> lock(d_mutex);
	d_condition.notify_all();
}
