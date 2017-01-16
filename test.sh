#!/bin/bash

xterm -e ./s &
sleep 1
xterm -e ./sender &
sleep 1
xterm -e ./led &