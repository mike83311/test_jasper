#!/bin/bash

echo "~~~~~Download Jasper~~~~~"
git clone https://github.com/jasperproject/jasper-client.git jasper
echo "Done!"

echo "~~~~~Tools upgrade~~~~~"
sudo pip install --upgrade setuptools
echo "Done!"

echo "~~~~~Requirements~~~~~"
sudo pip install -r jasper/client/requirements.txt
echo "Done!"

echo "~~~~~Change mode~~~~~"
chmod +x jasper/jasper.py
echo "Done!"

echo "~~~~~Update~~~~~"
sudo apt-get update
echo "Done!"

echo "~~~~~Profile setting~~~~~"
cd jasper/client
python populate.py
echo "Done!"

cd
