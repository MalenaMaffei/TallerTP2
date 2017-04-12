#!/bin/bash
python ./cpplint/cpplint.py --filter=`cat ./cpplint/filter_options` `find -regextype posix-egrep -regex '^\.\/[^\/]*\.(h|hpp|c|cpp)$'`
