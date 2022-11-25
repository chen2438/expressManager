#! /bin/bash
g++ MyDB.cpp test.cpp -o test `mysql_config --cflags --libs` 