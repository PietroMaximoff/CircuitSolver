cd src

shopt -s expand_aliases
source ~/.bashrc

s++ -c RCV.cpp -o RCV.o
s++ -c Button.cpp -o Button.o


cd ..

s++ v1.0.cpp src/Button.o src/RCV.o -o CircuitSolver
s++ v0.9.cpp src/Button.o src/RCV.o -o CircuitSolverOld