#!/bin/bash

#psnum=`ps -a | grep flappy_bird | awk  -F' ' '{print $1}'`
psnum=`pgrep flappy_bird`
#echo $psnum
kill -9 ${psnum}
