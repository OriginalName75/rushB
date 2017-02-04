#!/bin/bash

xterm -e ./server.out &
sleep 1
xterm -e ./led.out &
sleep 1
xterm -e ./client.out &