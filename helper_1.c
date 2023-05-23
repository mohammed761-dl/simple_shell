i#include "shell.h"


/*
 * 
 *
 * FREE_RECURRENT_DATA - FREE THE FILEDS NEEDED EACH LOOP
 *
 *
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


void free_all_data(data_of_program *data)

{
	if (data->file_descriptor != 0)
	{
		perror(data->program_name);

	}

	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}



void free_array_of_pointers(char **array)


{
	int i;

		if (array != NULL)
		{
			for(i = 0; array; i++)
				free(array[i]);

			free(array);
			array = NULL;
	}
}
