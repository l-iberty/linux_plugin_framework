#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "filesize.h"


void getPluginName(char* szPluginName)
{
	strcpy(szPluginName, "get file size");
}

void run(FILE* fp)
{
	long size;
	
	if (fp == NULL)
	{
		printf("<get file size> error: null pointer\n");
		return;
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("file size: %ld bytes.\n", size);
}
