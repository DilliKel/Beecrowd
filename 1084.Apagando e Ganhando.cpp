#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N, D;
    
    while (std::cin >> N >> D && N != 0 && D != 0) {
        std::string number;
        std::cin >> number;
        
        int remainingDigits = N - D; // quantidade de dígitos restantes
        
        std::string result;
        for (char digit : number) {
            while (!result.empty() && result.back() < digit && D > 0) {
                result.pop_back(); // remove o último dígito se for menor que o dígito atual
                D--;
            }
            result.push_back(digit);
        }
        
        // Se ainda sobrarem dígitos a serem removidos, remova-os do final do número
        result.resize(remainingDigits);
        
        std::cout << result << std::endl;
    }
    
    return 0;
}
