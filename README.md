
Compilar por consola:
g++ lista.h tests.cpp -lgtest_main  -lgtest -lpthread -std=c++11 &&  valgrind --leak-check=yes ./a.out
