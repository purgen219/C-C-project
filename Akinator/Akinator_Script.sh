
#!/bin/bash

g++ -Wall -I -o main main.cpp

./main 

dot -Tpng -O tree

xdg-open tree.png

