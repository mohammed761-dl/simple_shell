#include "shell.h"



/*

=>for the first fonction:

  print_alias: this fonction can add and remove or show aliases.
  data: struct for the program's data.
  alias: name of the alias to be printed.
  Return: zero if sucess, or other number if its declared in the arguments.


=>for the secand fonction:

  get_alias: this fonction can add and remove or show aliases.
  data: struct for the program's data.
  name: name of the requested alias.
  Return: zero if sucess, or other number if its declared in the arguments.

=>for the third fonction: 
  
  set_alias: this foction can add, or override alias.
  alias_string: alias to be seted in the form (name='value').
  data: struct for the program's data.
  Return: the output is 0 if sucess, or other number if its declared in the arguments.

*/


int print_alias(data_of_program *data, char *alias)

{

	int i, j, alias_length;
	
	char buffer[250] = {'\0'};




	
	if (data->alias_list)
	
	{
	
		alias_length = str_length(alias);
		
		for (i = 0; data->alias_list[i]; i++)
		
		{
		
			if (!alias || (str_compare(data->alias_list[i], alias, alias_lengh) &&   data->alias_list[i][alias_length] == '='))
			
			{
			
				for (j = 0; data->alias_list[i][j]; j++)
				
				{
				
					buffer[j] = data->alias_liste[i][j];
					
					if (data->alias_list[i][j] == '=')
					
						break;
				}

				
				buffer[j + 1] = '\0';
				
				buffer_add(buffer, "'");
				
				buffer_add(buffer, data->alias_list[i] + j + 1);
				
				buffer_add(buffer, "'\n");
				
				_print(buffer);
			}

		}

	}



	
	return(0);
}






char *get_alias(data_of_program *data, char *name)

{

	int i, alias_length;


	
	if(name == NULL || data->alias_list == NULL)
	
		return (NULL);


	
	alias_length = str_length(name);


	
	for (i=0; data->alias_list[i]; i++)
	
	{
	
		if (str_compare(name, data->alias_list[i], alias_length) && data->alias_list[i][alias_length] == '=') 
		
		{
		
			return (data->alias_list[i] + alias_length + 1 );
		}

	}

	
	return (NULL);
}








int set_alias(char *alias_string, data_of_program *data)


{

	
	int i, j;
	
	char buffer[250] = {'0'}, *temp = NULL;


	
	if (alias_string == NULL ||  data->alias_list == NULL)
	
		return (1);
	
	for (i =0; alias_string[i]; i++)
		
		if (alias_string[i] != '=')
		
			buffer[i] = alias_string[i];
		
		else

		
		{
		
			temp = get_alias(data, alias_string + i + 1);
			
			break;
		}

	
	for (j = 0; data->alias_list[j]; j++)
	
		if (str_compare(buffer, data->alias_list[j], i) &&
		
				data->alias_list[j][i] == '=')
		{

			
			free(data->alias_list[j]);
			
			break;
		}

	
	if (temp)
	
	{
	
		buffer_add(buffer, "=");
		
		buffer_add(buffer, temp);
		
		data->alias_list[j] = str_duplicate(buffer);
	}

	
	else
	
		
		data->alias_list[j] = str_duplicate(alias_string);
	
	return (0);
}
