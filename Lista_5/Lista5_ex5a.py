def teste(a, b, n):
	x = (a * a) + (b * b)
	if n == x:
		return 1
	else:
		return 0

def main():
	a = int(input("Digite o valor de a: "))
	b = int(input("Digite o valor de b: "))
	n = int(input("Digite o valor de n: "))

	if a < 1 or b < 1 or n < 1:
		print("\nErro: Todos os numeros devem ser inteiros e positivos!\n")
	else:
		r = teste(a, b, n)
		if r == 1:
			print("\nO numero %d e pitagoricos!\n" % n)
		else:
			print("\nO numero %d nao e pitagoricos!\n" % n)

if __name__ == "__main__":
	main()
