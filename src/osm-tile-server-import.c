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

int main(int argc, char **argv)
{
	char command[256];

	parse_settings();

	snprintf(command,255,"osm2pgsql --slim -d %s --cache-strategy sparse -C 100 --hstore -S /usr/share/osm2pgsql/default.style /usr/share/osm-tile-server-base/samples/liechtenstein-latest.osm.pbf",dbname);
	printf("Importing to database with this command:\n\n");
	printf(" %s\n\n",command);
	//system(command);

	return 0;

}

