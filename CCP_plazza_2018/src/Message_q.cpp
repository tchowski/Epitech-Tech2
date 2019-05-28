/*
** EPITECH PROJECT, 2019
** Message_queu.cpp
** File description:
** Message_queue
*/

#include "Message_q.hpp"
#include <iostream>

Message_Q::Message_Q(std::string &id_message_q, const char *message)
{
    this->_attr.mq_maxmsg = 10;
    this->_attr.mq_msgsize = 20;
    this->_mqfd = mq_open(id_message_q.c_str(), O_WRONLY | O_CREAT, 0666, &_attr);
    this->_id_message_q = strdup(id_message_q.c_str());
    this->_message = strdup(message);
    if (_mqfd == -1) {
        perror("Child mq_open failure");
        exit(84);
    }
}

Message_Q::Message_Q(std::string &id_message_q)
{
    this->_attr.mq_maxmsg = 10;
    this->_attr.mq_msgsize = 20;
    this->_mqfd = mq_open(id_message_q.c_str(), O_RDONLY | O_CREAT, 0666, &_attr);
    this->_id_message_q = strdup(id_message_q.c_str());
    if (_mqfd == -1) {
        perror("Child mq_open failure");
        exit(84);
    }
}

Message_Q::~Message_Q()
{
}

void Message_Q::send_message_queue()
{
    this->_status = mq_send(this->_mqfd, this->_message, strlen(this->_message) + 1, 0);
    if (_status == -1) {
        perror("mq_send failure");
        exit(84);
    }
}

void Message_Q::close_message_queue()
{
    mq_close(this->_mqfd);
}

void Message_Q::receive_message_queue()
{
    this->_status = mq_receive(this->_mqfd, this->_buf, 100, 0);
    if (_status == -1) {
        perror("mq_receive failure");
        exit(84);
    }
}

void Message_Q::unlink(std::string &id_message_q)
{
    mq_unlink(id_message_q.c_str());
}