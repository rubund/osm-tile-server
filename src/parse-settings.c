#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dbname[64];

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
		if(strncmp("DBNAME=\"",l,8) == 0) {
			char *substr = strstr(l+8,"\"");
			*substr = 0;
			//printf("Read line: %s\n",linebuf+8);
			strncpy(dbname,linebuf+8,63);
			//printf("%s\n",dbname);
		}
	}
	fclose(infile);

	if(linebuf)
		free(linebuf);
}

