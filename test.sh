#!/bin/bash

xterm -e ./server &
sleep 1
xterm -e ./sender &
sleep 1
xterm -e ./led &