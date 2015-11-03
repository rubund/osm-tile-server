default:

install:
	mkdir -p ${DESTDIR}/usr/bin
	install osm-tile-server-process ${DESTDIR}/usr/bin/
	install osm-tile-server-import ${DESTDIR}/usr/bin/
	mkdir -p ${DESTDIR}/usr/lib/osm-tile-server-base/bin
	install osm-tile-server-status  ${DESTDIR}/usr/lib/osm-tile-server-base/bin/
	install osm-tile-server-download ${DESTDIR}/usr/lib/osm-tile-server-base/bin/
	install install-postgis-osm-user.sh ${DESTDIR}/usr/lib/osm-tile-server-base/bin/
