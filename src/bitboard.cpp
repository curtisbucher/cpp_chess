#include <iostream>
#include "bitboard.h"

void print_bb(bitboard bb){
    for(int i=63; i >= 0; i--){
        if(1ULL << i & bb){
            std::cout << " * ";
        }
        else {
            std::cout << " . ";
        }
        if(i % 8 == 0){
            std::cout << "\n";
        }
    }
}