#include "textfilewriter.h"

void write_file(char* file_name){
	
	FILE* stream = fopen(file_name, "a");
	char musicTitle[51];
	rewind(stream);
	fgets(musicTitle, sizeof(musicTitle), stdin);
	fputs(musicTitle, stream);
	fclose(stream);
}
