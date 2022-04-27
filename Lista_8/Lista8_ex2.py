def multiplicacao_recursivo(a, b):
    if b == 0:
        return 0
    elif b == 1:
        return a
    else:
        return a + multiplicacao_recursivo(a, b-1)

def main():
	a, b = [int(x) for x in input("Insira a e b (inteiros nao negativos) para a multiplicacao: ").split()]
	
	if a < 0 or b < 0:
		print("\nO numero nao podem ser inteiros negativos!\n")
	else:
		r = multiplicacao_recursivo(a, b)
		print("\nResultado da multiplicacao: %d\n" % r)

if __name__ == "__main__":
	main()
