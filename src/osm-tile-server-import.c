#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse-settings.h"

int main(int argc, char **argv)
{
	char command[256];
	char *pbffile;

	if(argc != 2){
		fprintf(stderr,"Usage: %s <pbf-file>\n",argv[0]);
		return -1;
	}
	pbffile = argv[1];

	parse_settings();

	snprintf(command,255,"osm2pgsql --slim -d %s --cache-strategy sparse -C 100 --hstore -S /usr/share/osm2pgsql/default.style %s",dbname,pbffile);
	printf("Importing to database with this command:\n\n");
	printf(" %s\n\n",command);
	system(command);

	return 0;

}

