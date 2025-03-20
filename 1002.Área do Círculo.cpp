#include <iostream>
#include <iomanip>  // Para definir a precisão

int main() {
    double raio, area;
    
    // Leitura do valor do raio
    std::cin >> raio;
    
    // Cálculo da área
    area = 3.14159 * raio * raio;
    
    // Imprimir o resultado com 4 casas decimais
    std::cout << std::fixed << std::setprecision(4) << "A=" << area << std::endl;
    
    return 0;
}
