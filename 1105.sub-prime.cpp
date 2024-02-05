#include <iostream>
#include <vector>

bool checkDebentures(const std::vector<int>& reserves, const std::vector<std::vector<int>>& debentures) {
    std::vector<int> balance(reserves); // saldo inicial de cada banco igual às reservas monetárias
    
    for (const auto& debenture : debentures) {
        int debtor = debenture[0];
        int creditor = debenture[1];
        int value = debenture[2];
        
        balance[debtor - 1] -= value; // subtrai o valor da debênture das reservas do banco devedor
        balance[creditor - 1] += value; // adiciona o valor da debênture nas reservas do banco credor
    }
    
    for (const auto& b : balance) {
        if (b < 0) {
            return false; // algum banco tem saldo negativo, não é possível liquidar todas as debêntures
        }
    }
    
    return true; // todos os bancos têm saldo não negativo, é possível liquidar todas as debêntures
}

int main() {
    int B, N;
    
    while (std::cin >> B >> N && B != 0 && N != 0) {
        std::vector<int> reserves(B);
        for (int i = 0; i < B; ++i) {
            std::cin >> reserves[i];
        }
        
        std::vector<std::vector<int>> debentures(N, std::vector<int>(3));
        for (int i = 0; i < N; ++i) {
            std::cin >> debentures[i][0] >> debentures[i][1] >> debentures[i][2];
        }
        
        if (checkDebentures(reserves, debentures)) {
            std::cout << "S" << std::endl;
        } else {
            std::cout << "N" << std::endl;
        }
    }
    
    return 0;
}
