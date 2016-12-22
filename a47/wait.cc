#include "semaphore.ih"

void Semaphore::wait()
{
	unique_lock<mutex> lock(d_mutex);
	while (d_counter == 0)
		d_condition.wait(lock);
	
	--d_counter;
}
