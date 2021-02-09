#/bin/bash
service mysql start

#PERM
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

#Website folder
mkdir /var/www/miweb && touch /var/www/miweb/info.php
echo "<?php phpinfo(); ?>" >> /var/www/miweb/info.php

#SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 \
			-x509 \
			-sha256 \
			-days 3500 \
			-nodes \
			-out /etc/nginx/ssl/micrt.crt \
			-keyout /etc/nginx/ssl/mikey.key \
			-subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=jtello-m/CN=miweb"

#config Nginx
mv ./tmp/nginx-conf /etc/nginx/sites-available/miweb
ln -s /etc/nginx/sites-available/miweb /etc/nginx/sites-enabled/miweb
rm -rf /etc/nginx/sites-enabled/default

#config Mysql
echo "CREATE DATABASE mywordpress;" | mysql -u root --skip-password
echo "GRANT ALL ON mywordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

#config PHPmyadmin
mkdir /var/www/miweb/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/miweb/phpmyadmin
mv ./tmp/phpmyadmin.inc.php /var/www/miweb/phpmyadmin/config.inc.php

#WORDPRESS
cd /tmp/
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/miweb
mv /tmp/wp-config.php /var/www/miweb/wordpress

service php7.3-fpm start
service nginx start

sleep infinity