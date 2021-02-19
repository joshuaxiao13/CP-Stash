co() { g++ -std=c++0x -O2 -o "${1%.*}" $1 -Wall; }
run() { co $1 && ./${1%.*} & fg; }
