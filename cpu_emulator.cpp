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
        reg.fill(0);
        PC = 0;
        SP = 0xFFFE;
        FLAGS = {false, false, false, false};
    }
};

CPU cpu;

uint8_t fetch_byte(){
    return memory[cpu.PC++];
}

uint16_t fetch_word() {
    uint16_t low  = fetch_byte();
    uint16_t high = fetch_byte();
    return (high << 8) | low;  // little-endian
}

void run(){
    bool running = true;
    while (running) {
        uint8_t opcode = fetch_byte();
        switch(opcode){
            case 0x00: //Null operation
                break;

            case 0x01:
                uint8_t r1 = fetch_byte();
                uint8_t r2 = fetch_byte();
                cpu.reg[r1] = cpu.reg[r2];
                break;

            case 0x02:
                uint8_t r1 = fetch_byte();
                uint8_t imm = fetch_byte();
                cpu.reg[r1] = imm;
            
            case 0x03:
                uint8_t r1 = fetch_byte();
                uint16_t addr = fetch_word();
                cpu.reg[r1] = memory[addr];
                cpu.FLAGS.ZF = (cpu.reg[r1] == 0);
                cpu.FLAGS.NF = (cpu.reg[r1] & 0x8000);
                break;
            
            case 0x04:
                uint8_t r1 = fetch_byte();
                uint16_t addr = fetch_word();
                memory[addr] = cpu.reg[r1];
                break;

            default:
                std::cerr << "Unknown opcode: " << std::hex << (int)opcode << "\n";
                running = false;
                break;
        }
    }
}

int main() {
    memory[0] = 0x10;
    memory[1] = 0x21;
    memory[2] = 0x34;
    for(int i = 0; i < 3; i++){
        std::cout << "memory[" << i << "] = 0x" << std::hex << (int)memory[i]<< std::endl;
    }
}