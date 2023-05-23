#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void execute_command(char *command);
char *get_location(const char *command);
void execute_commands_from_file(const char *filename);
void display_prompt(void);
void remove_newline(char *str);
void execute_command(char *command);
void exitShell(int exitStatus);
void handle_comments(char *command);
int setenvShell(char *variable, char *value);
void processCommand(char *command);
void processSubCommand(char *subCommand);
void unset_env_variable(char *command);


#endif /* SHELL_H */
