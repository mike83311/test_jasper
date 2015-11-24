#!/bin/bash

for((i=0;i<10;i=i+1))do
#CIRCLE
  let count=count+1
  sudo iwlist wlan0 scan > scan_result.txt

#ICL3
  dbICL3=$(grep -i B8:55:10:2E:65:70 -A 12 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "ICL3 "$dbICL3""
    let sum_dbICL3=sum_dbICL3+dbICL3
#E403
  dbE403=$(grep -i CC:B2:55:5D:3B:66 -A 18 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "E403 "$dbE403""
    let sum_E403=sum_E403+dbE403
#HCL-404
  dbHCL404=$(grep -i 30:B5:C2:BD:DA:C1 -A 12 scan_result.txt | awk '/level/' | cut -d '=' -f 3 | cut -d '/' -f 1)
    echo "HCL-404 "$dbHCL404""
    let sum_HCL404=sum_HCL404+dbHCL404
#E406
  dbE406=$(grep -i C0:A0:BB:14:56:8C -A 17 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "E406 "$dbE406""
    let sum_E406=sum_E406+dbE406
#dbE407
  dbE407=$(grep -i 9C:D6:43:D6:91:F8 -A 13 scan_result.txt | awk '/level/' |cut -d '=' -f 3 |cut -d '/' -f 1)
    echo "dbE407 "$dbE407""
    let sum_dbdbE407=sum_dbE407+dbE407

  echo "####################"$count"####################"
done

#ICL3
  echo "ICL3 Sum "$sum_dbICL3""
  let average_dbICL3=sum_dbICL3/10
  echo Average_dbICL3=$average_dbICL3
#E403
  echo "E403 Sum "$sum_E403""
  let average_E403=sum_E403/10
  echo Average_E403=$average_E403
#HCL404
  echo "HCL-404 Sum "$sum_HCL404""
  let average_HCL404=sum_HCL404/10
  echo Average_HCL404=$average_HCL404
#E406
  echo "E406 Sum "$sum_E406""
  let average_E406=sum_E406/10
  echo Average_E406=$average_E406
#dbE407
  echo "dbE407 Sum "$sum_dbE407""
  let average_dbE407=sum_dbE407/10
  echo Average_dbE407=$average_dbE407

echo "####################"END"####################"

