def calcular_imposto(salario):
    if salario <= 2000.00:
        return "Isento"
    
    imposto = 0.0
    if salario > 4500.00:
        imposto += (salario - 4500.00) * 0.28
        salario = 4500.00
    if salario > 3000.00:
        imposto += (salario - 3000.00) * 0.18
        salario = 3000.00
    if salario > 2000.00:
        imposto += (salario - 2000.00) * 0.08
    
    return f"R$ {imposto:.2f}"

# Entrada do usuário
salario = float(input().strip())
print(calcular_imposto(salario))
