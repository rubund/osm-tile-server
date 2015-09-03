#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse-settings.h"


int main(int argc, char **argv)
{
	char command[256];
	char *area;

	if(argc != 2){
		fprintf(stderr,"Usage: %s <area/country>\n",argv[0]);
		return -1;
	}
	area = argv[1];

	parse_settings();

	char *filename = "downloaded.osm.pbf";
	char *url = "http://download.geofabrik.de/europe/norway-latest.osm.pbf";
	snprintf(command,255,"wget -O /var/cache/osm-tile-server-base/%s %s ",filename,url);
	printf("The following command will be run to download:\n\n");
	printf(" %s\n\n",command);
	system(command);

	return 0;

}

