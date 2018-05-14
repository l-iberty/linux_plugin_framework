#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "filewordcount.h"

#define bool    int
#define false   0
#define true    1

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
	
	int count = 0;
	bool word = false;
	
	while (!feof(fp))
	{
	        int ch = fgetc(fp);
	        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                {
                        word = true;
                        continue;
                }
                else if (word)
                {
                        word = false;
                        count++;
                }
	}

	printf("count words: %d\n", count);
}
