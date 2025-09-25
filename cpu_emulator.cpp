#include <iostream>
#include <cstdint>
#include <array>

//64KB of Memory
constexpr size_t MEMORY_SIZE = 65536;
std::array<uint8_t, MEMORY_SIZE> memory = {0};

struct CPU{
    std::array<uint16_t, 8> reg;
    uint16_t PC;
    uint16_t SP;
    struct {
        bool ZF : 1;
        bool CF : 1;
        bool NF : 1;
        bool OF : 1;
    } FLAGS;
    CPU(){
        
    }
};

int main() {
    memory[0] = 0x10;
    memory[1] = 0x21;
    memory[2] = 0x34;
    for(int i = 0; i < 3; i++){
        std::cout << "memory[" << i << "] = 0x" << std::hex << (int)memory[i]<< std::endl;
    }
}