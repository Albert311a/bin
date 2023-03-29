#!/bin/bash

# Test to see if we are connected to the internet

while true
do
	ping -c 1 www.yahoo.com > /dev/null 2>&1 && break
done;

set t_Co=256
C='10'
printf "\e[38;5;${C}m Connected to the internet.\n\033[0m"
