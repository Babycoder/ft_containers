#!/bin/bash

ME=$(whoami)

echo "killing Chrome..."

pkill -f 'google|chrome|Google|Chrome'

GOIN="/goinfre/$ME/Google"
SRC="/Users/$ME/Library/Application Support/Google"

echo "deleting pre-existing $GOIN folder contents..." && rm -rf "$GOIN"/* && \
echo "creating $GOIN..." && mkdir -p "$GOIN" && \
echo "copying contents of $SRC to $GOIN..." && rsync -ah --progress "$SRC"/* "$GOIN" && \
echo "deleting $SRC..." && rm -rf "$SRC" && \
echo "creating symbolic link from $GOIN to $SRC..." && ln -s "$GOIN" "$SRC"

echo 'Done!'

echo "killing VScode..."

pkill -f 'visual|Visual|Studio|studio'

GOIN="/goinfre/$ME/Code"
SRC="/Users/$ME/Library/Application Support/Code"

echo "deleting pre-existing $GOIN folder contents..." && rm -rf "$GOIN"/* && \
echo "creating $GOIN..." && mkdir -p "$GOIN" && \
echo "copying contents of $SRC to $GOIN..." && rsync -ah --progress "$SRC"/* "$GOIN" && \
echo "deleting $SRC..." && rm -rf "$SRC" && \
echo "creating symbolic link from $GOIN to $SRC..." && ln -s "$GOIN" "$SRC"

echo 'Done!'

# SRC="/Users/$ME/Library/Caches"
# GOIN="/goinfre/$ME/Caches"

# echo "killing all apps that are using $SRC..."
# sleep 2
# while true; do
#     read -p "do you want to continue? " yn
#     case $yn in
#         [Yy]* ) echo "here we go then..."; break;;
#         [Nn]* ) exit;;
#         * ) echo "Please answer with yes or no.";;
#     esac
# done

# lsof +r0 | grep $SRC | awk 'NR>1' | awk '{print $2}' | xargs kill -9

# echo "deleting pre-existing $GOIN folder contents..." && rm -rf "$GOIN"/* && \
# echo "creating $GOIN..." && mkdir -p "$GOIN" && \
# echo "copying contents of $SRC to $GOIN..." && rsync -ah --progress "$SRC"/* "$GOIN" && \
# echo "deleting $SRC..." && rm -rf "$SRC" && \
# echo "creating symbolic link from $GOIN to $SRC..." && ln -s "$GOIN" "$SRC"