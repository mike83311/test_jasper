#!/bin/bash

for((i=0;i<10;i=i+1))do
#CIRCLE
  let count=count+1
  sudo iwlist wlan0 scan > scan_result.txt
#HCL-404
  dbHCL404=$(grep -i HCL-404 -A 16 scan_result.txt | awk '/level/' | cut -d '=' -f 3 | cut -d '/' -f 1)
    echo "HCL-404 "$dbHCL404""
    let sum_HCL404=sum_HCL404+dbHCL404
#E403
  dbE403=$(grep -i E403 -A 20 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "E403 "$dbE403""
    let sum_E403=sum_E403+dbE403
#E406
  dbE406=$(grep -i E406 -A 16 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "E406 "$dbE406""
    let sum_E406=sum_E406+dbE406
#Randy
  dbRandy=$(grep -i Randy-WiFi -A 16 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)    
    echo "Randy "$dbRandy""
    let sum_Randy=sum_Randy+dbRandy
#ICL3
  dbICL3=$(grep -i ICL3 -A 16 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "ICL3 "$dbICL3""
    let sum_dbICL3=sum_dbICL3+dbICL3
#Lab411
  dbLab411=$(grep -i Lab411 -A 20 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "Lab411 "$dbLab411""
    let sum_dbLab411=sum_dbLab411+dbLab411

  echo "####################"$count"####################"
done

#HCL404
  echo "HCL-404 Sum "$sum_HCL404""
  let average_HCL404=sum_HCL404/10
  echo Average_HCL404=$average_HCL404
#E403
  echo "E403 Sum "$sum_E403""
  let average_E403=sum_E403/10
  echo Average_E403=$average_E403
#E406
  echo "E406 Sum "$sum_E406""
  let average_E406=sum_E406/10
  echo Average_E406=$average_E406
#Randy-WiFi
  echo "Randy Sum "$sum_Randy""
  let average_Randy=sum_Randy/10
  echo Average_Randy=$average_Randy
#ICL3
  echo "ICL3 Sum "$sum_dbICL3""
  let average_dbICL3=sum_dbICL3/10
  echo Average_dbICL3=$average_dbICL3
#Lab411
  echo "Lab411 Sum "$sum_dbLab411""
  let average_dbLab411=sum_dbLab411/10
  echo Average_dbLab4=$average_dbLab411

echo "####################"END"####################"

