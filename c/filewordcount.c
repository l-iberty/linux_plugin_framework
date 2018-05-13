#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "filewordcount.h"

void getPluginName(char* szPluginName)
{
	strcpy(szPluginName, "count words");
}

void run(FILE* fp)
{
	if (fp == NULL)
	{
		printf("<count words> error: null pointer\n");
		return;
	}

	printf("count words: \n");
}
