#include "shell.h"

/**
 * _changeToHomeDirectory - change to home directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToHomeDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	struct stat st;
	char *newDirectory;

	newDirectory = _getenvvalue("HOME");

	if (stat(newDirectory, &st) == 0)
	{
		chdir(newDirectory);
		/* set old path environment variable */
		_setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
		free(newDirectory);
	}
	else
	{
		free(newDirectory);
		perror(newDirectory);
	}
}
