#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

int sh_execute(char **argv)
{
	int status;
	pid_t pid;

	printf("%s\n",argv);
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

char **sh_get_argumentos()
{
	char *delimitador, *buffer = NULL, *token;
	int position = 0;
    size_t bufsize = 0;

    delimitador = " \t\r\n\a";
    if(getline(&buffer,&bufsize,stdin) == -1)
	{
        perror("Unable to allocate buffer");
        exit(1);
    }
	char **tokens = malloc(bufsize * sizeof(char*));
	if (!tokens) 
	    exit(-1);
	token = strtok(buffer, delimitador);
	while (token != NULL)
	{
		tokens[position] = token;
    	position++;
		printf("%s\n",token);
		token = strtok(NULL, delimitador);
	}
	tokens[position] = NULL;
  	return tokens;
}

int main(void)
{
	char **argumentos;
	int status = 0;

	do
	{
		printf("super_shell$ ");
		argumentos = sh_get_argumentos();

		status = sh_execute(argumentos);

		free(argumentos);

	} while (status != 0);
}