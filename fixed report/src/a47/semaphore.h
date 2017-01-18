#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>
#include <cstddef>

class Semaphore
{
	std::mutex d_mutex;
	std::condition_variable d_condition;
	std::size_t d_nAvailable = 0;
	
	public:
		Semaphore() = default;
		Semaphore(std::size_t nAvailable);
		
		std::size_t size() const;
		
		void notify();
		void notify_all();
		void wait();
};

#endif
