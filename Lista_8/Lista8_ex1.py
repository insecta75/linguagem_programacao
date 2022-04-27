def multiplicacao_interativos(a, b):
    s = 0
    
    for i in range(b):
        s = s + a
    
    return s

def main():
	a, b = [int(x) for x in input("Insira a e b (inteiros nao negativos) para a multiplicacao: ").split()]
	
	if a < 0 or b < 0:
		print("\nO numero nao podem ser inteiros negativos!\n")
	else:
		s = multiplicacao_interativos(a, b)
		print("\nResultado da multiplicacao: %d\n" % s)

if __name__ == "__main__":
	main()
