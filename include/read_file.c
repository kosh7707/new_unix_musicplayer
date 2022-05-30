#include "textfilewriter.h"

void read_file(char* file_name){
	char buffer[MAX_TITLE_SIZE];
	FILE* stream = fopen(file_name, "r");
	while(fgets(buffer, MAX_TITLE_SIZE, stream) != NULL){
		printf("%s", buffer);
	}
	fclose(stream);
}
