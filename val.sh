#!/bin/bash

valgrind --tool=memcheck --trace-children=yes --track-fds=yes --time-stamp=yes --num-callers=20 --error-exitcode=42 --leak-check=full --leak-resolution=med --show-reachable=yes ./tp tests/t9/spoon.cfg tests/t9/cap0.cap tests/t9/cap1.cap tests/t9/cap2.cap tests/t9/cap3.cap tests/t9/cap4.cap

