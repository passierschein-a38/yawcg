#!/bin/bash

# Yet Another WebCam Grabber
BINARY=/usr/bin/yawcg.bin

# Lighthttpd directory
OUTDIR=/var/www/

#Power on Camera
echo 1 > /proc/acpi/asus/camera

sleep 2

#Start the grabber
$BINARY --number 5 --delay 2 --outdir $OUTDIR

#Power off Camera
echo 0 > /proc/acpi/asus/camera