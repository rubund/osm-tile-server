

default: osm-tile-server-import-raw

install: default
	mkdir -p ${DESTDIR}/usr/lib/osm-tile-server-base/bin
	install osm-tile-server-import-raw ${DESTDIR}/usr/lib/osm-tile-server-base/bin/

osm-tile-server-import-raw: osm-tile-server-import.o parse-settings.o
	${CC} ${LDFLAGS} -o osm-tile-server-import osm-tile-server-import.o parse-settings.o


clean:
	${RM} *.o osm-tile-server-import
