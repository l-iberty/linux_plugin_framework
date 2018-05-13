#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "filelinenum.h"

void getPluginName(char* szPluginName)
{
	strcpy(szPluginName, "get file line num");
}

void run(FILE* fp)
{
	if (fp == NULL)
	{
		printf("<get file line num> error: null pointer\n");
		return;
	}

	printf("file line num: \n");
}
