#include "semaphore.ih"

void Semaphore::notify_all()
{
	lock_guard<mutex> lock(d_mutex);
	if (d_counter++ == 0)
		d_condition.notify_all();
}
