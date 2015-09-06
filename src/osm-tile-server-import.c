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

	if(strcmp(cfg_slim,"true") == 0) {
		snprintf(cfg_slim,10,"--slim");
	}
	else {
		snprintf(cfg_slim,10,"");
	}
	snprintf(command,255,"osm2pgsql %s -d %s --cache-strategy %s -C %s --hstore -S /usr/share/osm2pgsql/default.style %s",cfg_slim,cfg_dbname,cfg_cache_strategy,cfg_memory,pbffile);
	printf("Importing to database with this command:\n\n");
	printf(" %s\n\n",command);
	system(command);

	return 0;

}

