#/bin/bash

apt-get update && apt-get upgrade
apt-get install nginx -y
service nginx start