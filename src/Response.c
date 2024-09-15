#include "Response.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * render_static_file(char *fileName){
	FILE* file = fopen(file,"r");

	if(file == NULL){
		return NULL;
	}else{
		printf("%s does exit \n",fileName);
	}

	fseek(file,0,SEEK_END);
	long fsize = ftell(file);
	fseek(file,0,SEEK_SET);

	char* temp = malloc(sizeof(char)*(fsize+1));
	char ch;

	int i =0;

	while((ch=fgetc(file))!=EOF){
		temp[i]=ch;
		i++;
	}

	fclose(file);
	return temp;
}
