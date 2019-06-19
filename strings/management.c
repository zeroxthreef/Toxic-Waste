
/* the following 3 functions are pretty helpful for inserting strings inside strings */
char *string_replace(char *original, char *find, char *replace)
{
	char *final = NULL, *begining = NULL;

	if(original != NULL)
		if((begining = strstr(original, find)) != NULL)
		{
			final = calloc(1, (strlen(original) - strlen(find)) + strlen(replace) + 1);

			memmove(final, original, (begining - original));
			memmove(final + strlen(final), replace, strlen(replace));
			memmove(final + strlen(final), original + ((begining - original) + strlen(find)), strlen(original + ((begining - original) + strlen(find))));

    		return final;
		}

	return NULL;
}

char *string_replace_all(char *original, char *find, char *replace)
{
	char *final = NULL, *last = NULL;

	if(original != NULL)
  		while((final = string_replace(final ? final : original, find, replace)) != NULL)
  		{
		    if(last != NULL)
    		free(last);

			last = final;
		}

	return last;
}

int string_replace_buffer_all(char **original, char *find, char *replace)
{
	char *final = NULL;


	if(original != NULL && *original != NULL)
		if((final = string_replace_all(*original, find, replace)) != NULL)
		{
			free(*original);
			*original = final;

			return 1;
		}

	return 0;
}