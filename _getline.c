#include "shell.h"
/* _getline - read one line from the prompt
   @data: struct for the program's data
   Return: reading counting bytes */

int _getline(data_of_program *data)
{
	char buff[BUFFER_size] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;


	if (!array_commands[0] || (array_operators[0] == '&' && errno !=0) || (array_operators[0] == '|' && errno==0))
	{
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		bytes_read = read(data->filr_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);
		i = 0;
		do{
			array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;" ) );
			i = check_logic_ops(array_commands, i, array_operators);
		}while (array_commands[i++]);
	}

	data->input_line = array_commands[i + 1];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1]; 
	}
}
