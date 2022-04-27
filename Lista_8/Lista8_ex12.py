def mdc_interativo(x, y):
	i = y
	while y >= 1:
		if x%i == 0 and y%i == 0:
			return i
		i -= 1

def mdc_recursivo(x, y):
	if x%y == 0:
		return y
	return mdc_recursivo(y, x%y)

def main():
	x, y = [int(a) for a in input("Insira os numeros inteiros e positivos x e y, onde x maior ou igual a y: ").split()]

	if x <= 0 or y < 0:
		print("\nErro: Os números não podem ser negativos ou x não pode ser nulo!\n")
	elif x < y:
		print("\nErro: O número y não pode ser o maior!\n")
	elif y == 0:
		print("\nO M.D.C dos dois número é: %d" % x)
	else:
		print("\nO M.D.C Interativo dos números %d e %d é: %d\n" % (x, y, mdc_interativo(x, y)))

	if x < 0 or y < 0:
		print("\nErro: Os números não podem ser negativos ou m não pode ser nulo!\n")
	else:
		print("\nO M.D.C Recursivo dos números {} e {} é: {}\n".format(x, y, mdc_recursivo(x, y))) 

if __name__ == "__main__":
	main()
