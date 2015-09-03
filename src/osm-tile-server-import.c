#include <stdio.h>


int main(int argc, char **argv)
{
	char command[256];

	snprintf(command,255,"osm2pgsql --slim -d $DBNAME --cache-strategy sparse -C 100 --hstore -S /usr/share/osm2pgsql/default.style /usr/share/osm-tile-server-base/samples/liechtenstein-latest.osm.pbf");
	printf("Importing to database with this command:\n");
	printf(" %s\n",command);
	//system(command);

	return 0;

}

