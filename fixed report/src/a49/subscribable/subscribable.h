#ifndef SUBSCRIBABLE_H
#define SUBSCRIBABLE_H

#include <cstddef>

class Subscribable
{
	protected:
		std::size_t d_subscribers = 0;
		std::size_t d_waiters = 0;
	
	public:
		Subscribable() = default;
		
		void addThread();
		void removeThread();
		
		std::size_t subscribers() const;
		std::size_t waiters() const;
};

#endif
