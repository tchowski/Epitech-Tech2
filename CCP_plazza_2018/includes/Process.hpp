/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Desc
*/

#ifndef CCP_PROCESS_HPP_
#define CCP_PROCESS_HPP_

#include <unistd.h>

class Process {
public:
    Process();
    ~Process();
    pid_t getPid() const;
private:
    pid_t _pid;
};


#endif //CCP_PROCESS_HPP_
