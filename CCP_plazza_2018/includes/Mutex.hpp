/*
** EPITECH PROJECT, 2019
** Mutex.hpp
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_

#include "plazza.hpp"

class Mutex {
	public:
		Mutex();
		~Mutex();
        void lock_mutex();
        void unlock_mutex();
		pthread_mutex_t &getMutex();

	protected:
	private:
        pthread_mutex_t _newMutex; /* Création du mutex */

};

#endif /* !MUTEX_HPP_ */
