#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cfg_dbname[64];
char cfg_slim[64];
char cfg_cache_strategy[64];
char cfg_memory[64];
char cfg_processes[64];

int parse_one(const char *l, const char *cmp, char *var){
	int len;
	int i;
	int linelen;
	len = strlen(cmp);
	linelen=strlen(l);
	for(i=0;i<linelen;i++){
		if(l[i] == '#' || l[i] == '\n'){
			return -1;
		}
		else if (l[i] != ' ' && l[i] != '\t'){
			break;
		}
	}
	const char *reml = l+i;
	if(strncmp(cmp,reml,strlen(cmp)) == 0) {
		if(reml[strlen(cmp)] == '\"' || reml[strlen(cmp)] == '\''){
			char *substr = strstr(reml+len+1,"\"");
			*substr = 0;
			strncpy(var,reml+len+1,63);
		}
		else {
			char *substr = strstr(reml+len+1,"\n");
			*substr = 0;
			strncpy(var,reml+len,63);
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
		else if(parse_one(l,"IMPORT_PROCESSES=",cfg_processes) == 0){
		}
	}
	fclose(infile);

	if(linebuf)
		free(linebuf);
}

