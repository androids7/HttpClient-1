#!/bin/bash
# declare STRING variable
echo "Creating native make..."
cmake -G "Unix Makefiles" ..
echo "Running native make"
make
echo "Running CppLint"
echo "Inactivated cpp lint check"
#python cpplint/cpplint.py ../source/*.*
