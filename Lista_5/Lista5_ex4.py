def menor_base_log(n):
	b = 2
	x = n
	
	while b <= x:
		if n % b == 0:
			n = n / b
			if n == 1:
				return b #retorna o menor b
		else:
			n = x #n volta ao valor inicial
			b += 1 #soma 1 ao b

def main():
	n = int(input("Digite o valor de n, da formula b^k = n: "))

	if n < 1:
		print("\nO numero n deve ser inteiro e positivo!\n")
	elif n == 1:
		print("\nO valor de b seria: 1\n")
	else:
		print("\nO valor de b seria: %d\n" % menor_base_log(n))

if __name__ == "__main__":
	main()
