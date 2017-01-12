#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <cstddef>

struct Range
{
	int *beg = 0;
	int *end = 0;
	Range() = default;
        Range(int *b, int *e)
        :
            beg(b),
            end(e)
        {}
};

class Semaphore
{
	std::mutex d_mutex;
	std::condition_variable d_condition;
	std::size_t d_nAvailable = 0;
	
	std::size_t d_subscribers = 0;
	std::size_t d_waiters = 0;
	
	std::queue<Range> d_queue;
	
	public:
		Semaphore() = default;
		Semaphore(std::size_t nAvailable);
		
		Semaphore &subscribeThread();
		void desubscribeThread();
		
		std::size_t size() const;
		std::size_t subscribers() const;
		std::size_t waiters() const;
		
		void push(Range range);
		Range next();
		
		void notify();
		void notify_all();
		void wait();
};

#endif
