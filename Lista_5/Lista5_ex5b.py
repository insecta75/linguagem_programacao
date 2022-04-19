def pitagorico(n):
	a = 1
	b = 1

	for a in range(n):
		for b in range(n):
			x = (a * a) + (b * b)
			if n == x:
				return 1
	
	return 0

def main():
	n = int(input("Digite o valor inteiro n: "))

	if n < 1:
		print("\nErro: n deve ser inteiro e positivo!\n")
	else:
		r = pitagorico(n)
		if r == 1:
			print("\nO numero %d e pitagoricos!\n" % n)
		else:
			print("\nO numero %d nao e pitagoricos!\n" % n)

if __name__ == "__main__":
	main()
