def obter_cidade_ddd(ddd):
    ddd_cidades = {
        61: "Brasilia",
        71: "Salvador",
        11: "Sao Paulo",
        21: "Rio de Janeiro",
        32: "Juiz de Fora",
        19: "Campinas",
        27: "Vitoria",
        31: "Belo Horizonte"
    }
    
    return ddd_cidades.get(ddd, "DDD nao cadastrado")

# Entrada do usuário
ddd = int(input().strip())

print(obter_cidade_ddd(ddd))
