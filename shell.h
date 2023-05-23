

                                                        /*this file is the main file for the project.*/


#ifndef SHELL_H
#define SHELL_H



/* include library.h.*/
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>



/*inculde macros.*/
#include "macros.h"




/*   Struct Info: struct for the program's data. */

typedef struct info {
	
	char *program_name; // program_name: the name of the executable.
	char *input_line; // input_line: pointer to the input read for _getline.
	char *command_name;  // command_name: pointer to the first command typed by the user.
	int exec_counter; // exec_counter: number of excecuted comands.
	int file_descriptor; // exec_counter: number of excecuted comands.
	char **tokens; // tokens: pointer to array of tokenized input.
	char **env; // env: copy of the environ.
	char **alias_list;} //  alias_list: array of pointers with aliases.

data_of_program;

// Struct Builtins: Struct For The Builtins .

typedef struct builtins{
	char *builtin; // builtin: the name of the builtin
	int (*function)(data_of_program *data); // function: the associated function to be called for each builtin
	} 
builtins;


/***************** Include fonction . *****************/



//shell.c .

void inicialize_data(data_of_program *data, int arc, char *argv[], char **env); 
void sisifo(char *prompt, data_of_program *data); 
void handle_ctrl_c(int opr UNUSED);



//_getline.c .

int _getline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);



//expansions.c .

void expand_variables(data_of_program *data);
void expand_alias(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);



//str_tok.c .

void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);



//execute.c .

int execute(data_of_program *data);



//builtins_list.c .

int builtins_list(data_of_program *data);



//find_in_path.c .

char **tokenize_path(data_of_program *data);
int find_program(data_of_program *data);



// helpers_free.c

void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
