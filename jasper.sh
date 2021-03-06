#!/bin/bash

echo "~~~~~Download Jasper~~~~~"
cd ~
git clone https://github.com/jasperproject/jasper-client.git jasper
echo "Done!"

echo "~~~~~Tools upgrade~~~~~"
sudo pip install --upgrade setuptools
echo "Done!"

echo "~~~~~Requirements~~~~~"
sudo pip install -r ~/jasper/client/requirements.txt
echo "Done!"

echo "~~~~~Change mode~~~~~"
chmod +x ~/jasper/jasper.py
echo "Done!"

echo "~~~~~Update~~~~~"
sudo apt-get update
echo "Done!"

echo "~~~~~Upgrade~~~~~"
sudo apt-get upgrade -y
echo "Done!"

echo "~~~~~Setting Wi-Fi~~~~~"
sudo sed -i '$a network={\nssid="HCL-404"\nproto=RSN\nkey_mgmt=WPA-PSK\npairwise=CCMP\n#auth_alg=OPEN\npsk="rup453184xu/6"\n}' /etc/wpa_supplicant/wpa_supplicant.conf
echo "Done!"

echo "~~~~~Move files~~~~~"
cd ~/test_jasper/
mv Navigation.py Position.py Shutdown.py ~/jasper/client/modules
echo "Done"

echo "~~~~~Change Mode~~~~~"
chmod +x ~/test_jasper/scan/scan_result.sh
chmod +x ~/test_jasper/scan/test_scan.sh
echo "Done!"

echo "~~~~~Profile setting~~~~~"
cd ~/jasper/client
python populate.py
echo "Done!"

echo "~~~~~Start Jasper~~~~~"
cd ~/jasper
./jasper.py

