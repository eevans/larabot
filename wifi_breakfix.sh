#!/bin/bash

APP=`basename "$0"`
DEV=${1:-wlan0}

log()
{
    logger -i -t "$APP" "$1"
}

if ! ip addr show "$DEV" &>/dev/null; then
    log "$DEV not found, exiting."
    exit 0
fi

ifdown wlan0 &>/dev/null
pkill wpa_supplicant

ifup wlan0 && log "Success." || log "Failed."
