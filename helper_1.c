#include "shell.h"


/**
 * free_recurrent_data - free the fields needed each loop
	*/

void free_reccurent_data(data_of_program *data)
	 {
		 if(data->input_line)
			 free(data->input_line);
		 if(data->command_name)
			 free(data-command_name);

		 data->input_line = NULL;
		 data->data_name = NULL;
		 data->tokens = NULL;

}

/*
 * free_all_data - free all field of the data
 */

void free_all_data(data_of_program *data)

	if (data->file_descriptor != 0)
{
		perror(data->program_name);

}

free_recurrent_data(data);
free_array_of_pointers(data->env);
free_array_of_pointers(data->alias_list);
}

/*
 * free_array_of_pointers - frees each pointer of an array of pointers and the arraytoo
 */

void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for(i = 0; array; i++)
			free(array[i]);

		free(array);
		array = NULL;
