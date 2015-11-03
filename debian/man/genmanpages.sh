#!/bin/bash


txt2man -d "${CHANGELOG_DATE}" -t OSM-TILE-SERVER.CONF              -s 5 osm-tile-server.conf.txt             > osm-tile-server.conf.5
txt2man -d "${CHANGELOG_DATE}" -t OSM-TILE-SERVER-PROCESS           -s 1 osm-tile-server-process.txt          > osm-tile-server-process.1
txt2man -d "${CHANGELOG_DATE}" -t OSM-TILE-SERVER-IMPORT            -s 1 osm-tile-server-import.txt           > osm-tile-server-import.1
txt2man -d "${CHANGELOG_DATE}" -t OSM-TILE-SERVER-TILELITE          -s 7 osm-tile-server-tilelite.txt         > osm-tile-server-tilelite.7
txt2man -d "${CHANGELOG_DATE}" -t OSM-TILE-SERVER                   -s 7 osm-tile-server.txt                  > osm-tile-server.7
