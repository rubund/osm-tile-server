

default: osm-tile-server-import

install: osm-tile-server-import
	mkdir -p ${DESTDIR}/usr/bin
	install osm-tile-server-import ${DESTDIR}/usr/bin/

osm-tile-server-import: osm-tile-server-import.o
	${CC} -o osm-tile-server-import osm-tile-server-import.o

clean:
	${RM} *.o osm-tile-server-import
