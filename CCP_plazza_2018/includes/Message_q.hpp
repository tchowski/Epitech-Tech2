/*
** EPITECH PROJECT, 2019
** message_queu.hpp
** File description:
** message_queue
*/

#ifndef MESSAGE_QUEUE_HPP_
    #define MESSAGE_QUEUE_HPP_

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

class Message_Q {

	public:
        char _buf[100];
        char *_message;
        char *_id_message_q;
		Message_Q(std::string &id_message_q, const char *message);
        Message_Q(std::string &id_message_q);
		~Message_Q();
        void send_message_queue();
        void receive_message_queue();
        void unlink(std::string &id_message_q);
        void close_message_queue();

	protected:
	private:
        mqd_t _mqfd;
        int _status;
        struct mq_attr _attr;
};

#endif /* !MUTEX_HPP_ */
