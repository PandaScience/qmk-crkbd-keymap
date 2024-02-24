#!/bin/bash
# https://github.com/caksoylar/keymap-drawer#command-line-tool-installation

cd ~/Private/qmk_firmware/
qmk c2json ~/Private/qmk-crkbd-keymap/keymap.c | keymap parse -c 12 -q - > ~/Private/qmk-crkbd-keymap/keymap.yaml

cd ~/Private/qmk-crkbd-keymap/
keymap draw keymap.yaml > keymap.svg

echo "DONE"
