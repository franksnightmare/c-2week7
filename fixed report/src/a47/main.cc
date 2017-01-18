#include "semaphore.h" 
#include <thread>

using namespace std;

void waiter(Semaphore &semaphore)
{
	semaphore.wait();
}

int main(int argc, char **argv)
{
	Semaphore semaphore;
	
	thread wait1(waiter, std::ref(semaphore));
	
	semaphore.notify_all();
	
	wait1.join();
}
