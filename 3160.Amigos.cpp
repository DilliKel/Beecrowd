#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string linha1, linha2, nome_indicado;
    
    // Leitura da primeira lista de amigos
    std::getline(std::cin, linha1);
    // Leitura da segunda lista de amigos
    std::getline(std::cin, linha2);
    // Leitura do nome do amigo indicado ou "nao"
    std::getline(std::cin, nome_indicado);
    
    // Transformar as linhas em vetores de strings
    std::vector<std::string> amigos, novos_amigos;
    std::string nome;
    
    // Preenchendo a lista de amigos de Luiggy
    std::stringstream ss1(linha1);
    while (ss1 >> nome) {
        amigos.push_back(nome);
    }
    
    // Preenchendo a nova lista de amigos
    std::stringstream ss2(linha2);
    while (ss2 >> nome) {
        novos_amigos.push_back(nome);
    }
    
    // Verificar se há indicação de amigo
    if (nome_indicado != "nao") {
        // Inserir os novos amigos antes do amigo indicado
        auto it = std::find(amigos.begin(), amigos.end(), nome_indicado);
        if (it != amigos.end()) {
            amigos.insert(it, novos_amigos.begin(), novos_amigos.end());
        }
    } else {
        // Caso contrário, adicionar no final
        amigos.insert(amigos.end(), novos_amigos.begin(), novos_amigos.end());
    }
    
    // Exibir a lista atualizada de amigos
    for (size_t i = 0; i < amigos.size(); ++i) {
        std::cout << amigos[i];
        if (i != amigos.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
