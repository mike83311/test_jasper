#!/bin/bash

sudo iwlist wlan0 scan > wifi_result.txt

dbICL3=$(grep -i B8:55:10:2E:65:70 -A 12 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbICL3" ]
then
	dbICL3=0
fi

dbE403=$(grep -i CC:B2:55:5D:3B:66 -A 18 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbE403" ]
then
	dbE403=0
fi

dbHCL404=$(grep -i 30:B5:C2:BD:DA:C1 -A 12 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbHCL404" ]
then
	dbHCL404=0
fi

dbE406=$(grep -i C0:A0:BB:14:56:8C -A 17 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbE406" ]
then
	dbE406=0
fi

dbE407=$(grep -i 9C:D6:43:D6:91:F8 -A 13 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbE407" ]
then
    dbE407=0
fi

#echo $dbICL3 $dbE403 $dbHCL404 $dbE406 $dbE407
#echo ""
#echo "Now Position is : "

#echo $position
position=$(/home/pi/test_jasper/scan/wifi $dbICL3 $dbE403 $dbHCL404 $dbE406 $dbE407)
#echo $position
#posx=$(echo $position | cut -c 1) 
#posy=$(echo $position | cut -c 3)
#echo $posx
#echo $posy

/home/pi/scan/Astar $position

