def amigos(a, b):
	sa = 0
	sb = 0
	i = 1
	j = 1

	while i < a:
		if a%i == 0:
			sa += i
		i += 1

	while j < b:
		if b%j == 0:
			sb += j
		j += 1

	if sa == b and sb == a:
		return 1
	else:
		return 0

def main():
	a = int(input("Digite o valor de a: "))
	b = int(input("Digite o valor de b: "))

	r = amigos(a, b)

	if r == 1:
		print("\nOs numeros %d e %d sao amigos!\n" % (a, b))
	else:
		print("\nEsse numeros nao sao amigos!\n")

if __name__ == "__main__":
	main()
