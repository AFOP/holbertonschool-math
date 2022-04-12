#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

int execute(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else 
	{
		wait(&status);
	}
	return (status);
}

char *get_argumentos(char buffer, int cont)
{
	int position = 0;
	char **tokens = malloc(cont+1 * sizeof(char *));

	char *token = strtok(buffer, " \n");

	while (token != NULL)
	{
		tokens[position] = token;
		printf ("%s\n", tokens[position]);
		position++;
		token = strtok(NULL, " \n");
	}
	tokens[position] = NULL;
	printf("%i\n", position);
	return (tokens);
}

int main(void)
{
	char *buffer, **arg, *copy, *token;
	size_t bufsize = 0;
	int status = 0, cont =0;

	do
	{
		printf("super_shell$ ");
		getline(&buffer, &bufsize, stdin);

		copy = strdup(buffer);
		token = strtok(copy, " ");
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			cont++;
		}
		arg = get_argumentos(buffer, cont);

		status = execute(arg);

	} while (status);
}