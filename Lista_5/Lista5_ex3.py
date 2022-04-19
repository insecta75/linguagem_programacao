def mdc(m, n):
	if n == 0:
		return m
	else:
		return mdc(n, m%n)

def main():
	m = int(input("Digite o valor de m: "))
	n = int(input("Digite o valor de n: "))

	if m >= n:
		print("\nO valor do mdc entre %d e %d: %d\n" % (m, n, mdc(m, n)))
	else:
		print("\nO valor de m nao pode ser menor que n!\n")

if __name__ == "__main__":
	main()
