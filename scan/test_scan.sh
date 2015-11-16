#!/bin/bash

sudo iwlist wlan0 scan > wifi_result.txt


dbHCL404=$(grep -i HCL-404 -A 16 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbHCL404" ]
then
	dbHCL404=0
fi

dbE403=$(grep -i E403 -A 20 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbE403" ]
then
	dbE403=0
fi

dbE406=$(grep -i E406 -A 16 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbE406" ]
then
	dbE406=0
fi

#dbRandy=$(grep -i Randy-WiFi -A 16 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
#if [ -z "$dbRandy" ]
#then
#	dbRandy=0
#fi

dbICL3=$(grep -i ICL3 -A 16 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbICL3" ]
then
	dbICL3=0
fi

dbLab411=$(grep -i Lab411 -A 20 wifi_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
if [ -z "$dbLab411" ]
then
        dbLab411=0
fi

#echo $dbHCL404 $dbE403 $dbE406 $dbICL3 $dbLab411
#echo ""
#echo "Now Position is : "

#echo $position
position=$(/home/pi/scan/wifi $dbHCL404 $dbE403 $dbE406 $dbICL3 $dbLab411)
posx=$(echo $position | cut -c 1) 
posy=$(echo $position | cut -c 3)
#echo $posx
#echo $posy

/home/pi/scan/Astar 20 3



