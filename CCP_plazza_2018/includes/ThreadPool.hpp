/*
** EPITECH PROJECT, 2019
** ThreadPool.hpp
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

#include "Thread.hpp"
#include <list>
#include <string>

class ThreadPool {
	public:
		ThreadPool(int number, void *(*start_routine)(void *), void *arg);
		~ThreadPool();
		std::list<Thread*>	_threadsPool;

	protected:
	private:

};

#endif /* !THREADPOOL_HPP_ */
