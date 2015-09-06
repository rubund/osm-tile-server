#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cfg_dbname[64];
char cfg_slim[64];
char cfg_cache_strategy[64];
char cfg_memory[64];

int parse_one(const char *l, const char *cmp, char *var){
	int len;
	len = strlen(cmp);
	if(strncmp(cmp,l,strlen(cmp)) == 0) {
		if(l[7] == '\"'){
			char *substr = strstr(l+len+1,"\"");
			*substr = 0;
			strncpy(var,l+len+1,63);
		}
		else {
			char *substr = strstr(l+len+1,"\n");
			*substr = 0;
			strncpy(var,l+len,63);
		}
		return 0;
	}
	else return -1;
}

void parse_settings()
{
	char *linebuf = NULL;
	size_t len;
	ssize_t read;
	FILE *infile;

	infile = fopen("/etc/osm-tile-server.conf","r");
	if (infile == NULL) exit(-1);
	while((read = getline(&linebuf, &len, infile)) != -1 ) {
		const char *l = linebuf;
		if(parse_one(l,"DBNAME=",cfg_dbname) == 0){
		}
		else if(parse_one(l,"IMPORT_SLIM=",cfg_slim) == 0){
		}
		else if(parse_one(l,"IMPORT_CACHE_STRATEGY=",cfg_cache_strategy) == 0){
		}
		else if(parse_one(l,"IMPORT_MEMORY=",cfg_memory) == 0){
		}
	}
	fclose(infile);

	if(linebuf)
		free(linebuf);
}

