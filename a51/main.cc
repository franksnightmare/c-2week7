#include "safequeue.h"
#include <thread>
#include <iostream>

// Example of a worker that will automatically stop
// When there are no more jobs and all workers are waiting

void worker(SafeQueue &list)
{
    while (true)
    {
        DotPair pair = list.next();
        if (pair.size == 0)
        {
            list.desubscribeThread();
            std::cout << "Stopping\n";
            return;
        }
        
        std::cout << "Doing a job\n";
        // DO STUFF
        
    }
}

int main()
{
	SafeQueue workList;
	
	double *point1 = new double[5];
	double *point2 = new double[5];
	
	// Example of a job.
	workList.push(DotPair(point1, point2, 5));
	
	// Example of a worker thread
	workList.subscribeThread();
	std::thread thread1(worker, std::ref(workList));
	
	// Just to show the thread ends
	thread1.join();
	
	delete point1;
	delete point2;
}
