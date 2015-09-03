#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse-settings.h"

int main(int argc, char **argv)
{
	char command[256];
	char *cmd;

	if(argc != 2){
		fprintf(stderr,"Usage: %s <command>\n",argv[0]);
		return -1;
	}

	parse_settings();

	cmd = argv[1];

	FILE *wfile;

	if(strncmp(cmd,"done",4) == 0) {
		wfile = fopen("/var/cache/osm-tile-server-base/status.txt","w");
		fprintf(wfile,"DONE");
		fclose(wfile);
	}

	//snprintf(command,255,"osm2pgsql --slim -d %s --cache-strategy sparse -C 100 --hstore -S /usr/share/osm2pgsql/default.style %s",dbname,pbffile);
	//printf("Importing to database with this command:\n\n");
	//printf(" %s\n\n",command);
	//system(command);

	return 0;

}

