cd /var/www/html && rm -rf expressManager/ && git clone https://github.com/chen2438/expressManager.git && g++ expressManager/cpp/main.cpp  -std=c++20 -o expressManager/cpp/main `mysql_config --cflags --libs` && chmod 777 -R expressManager/ 

&& ./expressManager/cpp/main signUp 2 3 4