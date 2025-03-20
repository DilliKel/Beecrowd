def identificar_animal(palavra1, palavra2, palavra3):
    animais = {
        ("vertebrado", "ave", "carnivoro"): "aguia",
        ("vertebrado", "ave", "onivoro"): "pomba",
        ("vertebrado", "mamifero", "onivoro"): "homem",
        ("vertebrado", "mamifero", "herbivoro"): "vaca",
        ("invertebrado", "inseto", "hematofago"): "pulga",
        ("invertebrado", "inseto", "herbivoro"): "lagarta",
        ("invertebrado", "anelideo", "hematofago"): "sanguessuga",
        ("invertebrado", "anelideo", "onivoro"): "minhoca"
    }
    
    return animais.get((palavra1, palavra2, palavra3), "Animal nao encontrado")

# Entrada do usuário
palavra1 = input().strip()
palavra2 = input().strip()
palavra3 = input().strip()

print(identificar_animal(palavra1, palavra2, palavra3))
