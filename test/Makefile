CXXFLAGS = -Wall -g

my_program: main.o miniAES-Utils.o
    g++ main.o miniAES-Utils.o -o my_program

main.o: main.cpp
    g++ $(CXXFLAGS) -c -o main.o test_main.cpp

miniAES-Utils.o: ../miniAES/internal/miniAES-Utils.cpp
    g++ $(CXXFLAGS) -c -o miniAES-Utils.o ../miniAES/internal/miniAES-Utils.cpp
