#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ Extension!"};
    for (const std::string &wrod : msg) {
        std::cout << wrod << " ";
    }
    std::cout << std::endl;    
}