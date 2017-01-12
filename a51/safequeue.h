#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H

#include "semaphore.h"
#include <queue>

struct DotPair
{
	double *vec1;
	double *vec2;
	std::size_t size;
	DotPair() = default;
        DotPair(double *lhs, double *rhs, std::size_t dim)
        :
            vec1(lhs),
            vec2(rhs),
            size(dim)
        {}
};

class SafeQueue : public Semaphore
{	
	std::queue<DotPair> d_queue;
	
	public:
		void push(DotPair pair);
		DotPair next();
};

#endif
