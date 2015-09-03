

default: osm-tile-server-import osm-tile-server-download

install: default
	mkdir -p ${DESTDIR}/usr/bin
	install osm-tile-server-import ${DESTDIR}/usr/bin/
	install osm-tile-server-download ${DESTDIR}/usr/bin/

osm-tile-server-import: osm-tile-server-import.o parse-settings.o
	${CC} ${LDFLAGS} -o osm-tile-server-import osm-tile-server-import.o parse-settings.o

osm-tile-server-download: osm-tile-server-download.o parse-settings.o
	${CC} ${LDFLAGS} -o osm-tile-server-download osm-tile-server-download.o parse-settings.o

clean:
	${RM} *.o osm-tile-server-import osm-tile-server-download
