/*
** EPITECH PROJECT, 2019
** ftp.h
** File description:
** ftp
*/

#ifndef FTP_H_
#define FTP_H_

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define msg_120 "120 Service ready in nnn minutes.\r\n"
#define msg_125 "125 Data connection already open.\r\n"
#define msg_150 "150 File status okay.\r\n"
#define msg_200 "200 Command okay.\r\n"
#define msg_221 "221 Service closing control connection.\r\n"
#define msg_214 "214 Help message.\r\n"
#define msg_220 "220 Service ready for new user.\r\n"
#define msg_226 "226 Closing data connection.\r\n"
#define msg_227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n"
#define msg_230 "230 User logged in, proceed.\r\n"
#define msg_250 "250 Requested file action okay, completed.\r\n"
#define msg_257 "257 \"PATHNAME\" created.\r\n"
#define msg_331 "331 User name okay, need password.\r\n"
#define msg_332 "332 Need account for login.\r\n"
#define msg_425 "425 Use PORT or PASV first.\r\n"
#define msg_430 "430 Invalid username or password.\r\n"
#define msg_530 "530 not logged in.\r\n"
#define msg_500 "500 Syntax error.\r\n"
#define msg_xxx "xxx Error (RFC compliant)\r\n"

typedef struct sockaddr_in sockaddr_in;

typedef struct socket {
    int PORT;
    char const *path;
} socket_t;

typedef struct user_connection {
    char *username;
    char *password;
} user_connection_t;

typedef struct data {
    sockaddr_in adress_socket_data;
    socket_t data_socket;
    int data_fd;
    int data_client_fd;
} data_t;

data_t data;
bool isPort;
char *rootPath;

/* Utils */
int print_usage(void);
char **str_to_array(char *str);
char **str_to_comma(char *str);
void my_perror(char *str);
bool isnumber(char const *s);
bool check_port(char const **argv);
bool check_path(char const **argv);
char *my_strncpy(char *dest, char *src, int n);
char *revstr(char *str);
void parent_cdup_adress(char **path);
pid_t check_pid(void);
char *concat_path(char *source, const char *element, const char *origin);
bool check_root_path(char *path, int client_fd);

/* Server connection */
void init_server(char const **argv);
void init_socket_struct(socket_t *socket_s, char const **argv);
void init_sockaddr_server(sockaddr_in *server, socket_t *socket_s);
void init_user_connection(user_connection_t *user_connection);
void init_port(data_t *data, char *address, char *port);
void connection_check(int client_fd);

/* User */
void set_username(user_connection_t *user_connection, const char *username);
void set_password(user_connection_t *user_connection, const char *password);

/* Directories */
bool dir_cwd(socket_t *socket_client, const char *new_path);
char *concat_pwd(const char *str);
void message(int client_fd, const char *str);
bool delete_dele(const char *path, const char *file_name);
void parent_cdup(char *path);
bool list_list(int client_fd, const char *path);

/* Data */
uint16_t init_pasv(data_t *data, sockaddr_in *their_addr, socklen_t *len);
void pasv(data_t *data, int client_fd);
void list(int client_socket);
void port(data_t *data, int client_fd, char *tab);

/* Check */
int main_command_check(int client_fd, const char *buffer, socket_t *socket_s);
bool check_connection(user_connection_t *user_connection);

/* Command */
int data_command(int client_fd, const char *buffer);

#endif /* !FTP_H_ */
