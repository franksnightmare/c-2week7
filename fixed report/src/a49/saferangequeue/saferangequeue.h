#ifndef SAFERANGEQUEUE_H
#define SAFERANGEQUEUE_H

#include "semaphore.h"
#include "subscribable.h"
#include <queue>

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

class SafeRangeQueue : public Semaphore,
	public Subscribable
{
	std::queue<Range> d_queue;
	
	private:
		bool done() override;
	
	public:
		SafeRangeQueue() = default;
		SafeRangeQueue &addThread();
		
		std::size_t size() const;
		
		void push(Range range);
		Range pop();
		
		void wait();
};

#endif
