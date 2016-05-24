#!/bin/bash

#echo "script begins"

#asebaswitch "ser:name=Thymio" &
#echo
#echo "Connected to Thymio port"

#asebarec "tcp:localhost;port=33333" > eventlog.txt &
#echo "event recorded into eventlog.txt"

#asebastudio &
#echo "asebastudio launched"

./read eventlog.txt result.txt
echo "read executed"

echo "programm aborted"
