#!/bin/bash

for REG in {africa,asia,europe,australia-oceania,central-america,north-america,south-america} ; do
    echo "Getting $REG..."
    curl -s 'http://download.geofabrik.de/'${REG}'.html' | grep ""${REG}"/.*\.pbf" | perl -pe 's/.*href="(.*?)-latest\.osm\.bz2.*/\1/'  > ${REG}.txt
done
