/* ascii.cc
 * Written by Cyprien Lacassagne, 02/18/2023
 */

#include <iostream>
#include <string>

int main() {
    
    std::string accent_line("\x1b[48;5;237m");
    std::string space("      ");
    std::string space2("     ");
    for (int columns(0); columns < 3; ++columns) {
        std::cout << "\x1b[4m" "Dec" << space2 << "Char   ";
        if (columns < 2)
            std::cout << "|";
    }
    std::cout << "\x1b[0m\n";
    for (int code(32); code <= 63; ++code) {
        if ((code-35) % 5 == 1)
            std::cout << accent_line;
            
        std::cout << code << space << char(code) << space << "|"
                   << code + 32 << space << char(code + 32) << space << "|"
                   << code + 64 << (code + 64 < 100 ? space : space2);
        if (code + 64 == 127)
            std::cout << "[DEL]";
        else
            std::cout << char(code+64);
        std::cout << space << "\x1b[0m\n";
    }
    
    return 0;
}
