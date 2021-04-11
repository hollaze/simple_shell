#include "shell.h"

/**
 * _getenv - get envioronment variable
 *
 * @prmEnvironmentName: environment variable name
 *
 * Return: environment variable value
 */
char *_getenv(char *prmEnvironmentName)
{
	int cLoop = 0;

	while (environ[cLoop] != NULL)
	{
		if (_strstr(environ[cLoop], prmEnvironmentName, 1) != NULL)
		{
			return (environ[cLoop]);
		}
		cLoop++;
	}

	return (NULL);
}

/**
 * _env - print environement variable
 *
 * @prmData: data structure
 */
void _env(data_t *prmData __attribute__((unused)))
{
	int cLoop = 0;

	while (environ[cLoop])
	{
		_puts(environ[cLoop]);
		_putchar('\n');
		cLoop++;
	}
}

/**
 * _getenvvalue -
 *
 * @prmEnvironmentName:
 *
 * Return:
 */
char *_getenvvalue(char *prmEnvironmentName)
{
	char *environmentVariable, *tmpEnv, *locate, *result;

	environmentVariable = _getenv(prmEnvironmentName);

	if (environmentVariable == NULL)
		return (NULL);

	tmpEnv = _strdup(environmentVariable);

	if (tmpEnv == NULL)
		return (NULL);

	locate = _strchr(tmpEnv, '=');

	if (locate == NULL)
		return (NULL);

	result = _strdup(locate + 1);
	free(tmpEnv);

	return (result);
}

/**
 * _setenv -
 *
 * @prmName:
 * @prmValue:
 * @prmOverwrite:
 *
 * Return:
 */
int _setenv(char *prmName, char *prmValue, int prmOverwrite)
{
	char *env, *newValue = "";
	size_t cLoop = 0;

	newValue = _calloc(sizeof(char), (_strlen(prmName) + _strlen(prmValue) + 2));
	env = _getenv(prmName);

	newValue = strcat(newValue, prmName);
	newValue = strcat(newValue, "=");
	newValue = strcat(newValue, prmValue);

	if (env == NULL)
	{
		while (environ[cLoop])
			cLoop++;
		environ[cLoop] = newValue;
		environ[cLoop + 1] = NULL;
		/* free(newValue); */
	}
	else if (prmOverwrite == 1)
	{
		while (environ[cLoop] != env)
			cLoop++;
		strcpy(environ[cLoop], newValue);
		free(newValue);
	}
	else
	{
		free(newValue);
		free(env);
	}

	return (EXIT_SUCCESS);
}

/**
 * _unsetenv -
 *
 * @prmName:
 *
 * Return:
 */
int _unsetenv(char *prmName)
{
	char *env;
	int size = 0, cLoop = 0;

	env = _getenv(prmName);

	while (environ[size])
		size++;

	if (env == NULL)
		return (EXIT_FAILURE);
	else
		while (_strstr(environ[cLoop], prmName, 1) == NULL)
			cLoop++;

	for (; cLoop < size; cLoop++)
		environ[cLoop] = environ[cLoop + 1];

	return (EXIT_SUCCESS);
}