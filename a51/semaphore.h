#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>
#include <cstddef>

class Semaphore
{
	std::condition_variable d_condition;
	
	protected:
		std::mutex d_mutex;
		std::size_t d_nAvailable = 0;
		
		std::size_t d_subscribers = 0;
		std::size_t d_waiters = 0;
	
	public:
		Semaphore() = default;
		Semaphore(std::size_t nAvailable);
		
		void subscribeThread();
		void desubscribeThread();
		
		std::size_t size() const;
		std::size_t subscribers() const;
		std::size_t waiters() const;
		
		void notify();
		void notify_all();
		void wait();
};

#endif
