def cria_vetor(n):
	vetor = []
	for j in range(n):
		numero = float(input("\nInsira o %d elemento: " % (j+1)))
		vetor.append(numero)
	return vetor

def media(vetor):
	soma = 0
	n = len(vetor)

	for j in range(n):
		soma += vetor[j]
	m = soma / n

	for j in range(n):
		if vetor[j] > m:
			ma = vetor[j]
			mi = vetor[j-1]
			posma = j
			break
	
	dma = ma - m
	dmi = m - mi

	if dma > dmi:
		i = posma -1
	else:
		i = posma

	return m, i

def main():
	vetor = []
	
	n = int(input("Quantos numeros serao inseridos no vetor: "))

	print("\nInsira os numeros em ordem crescente:")
	vetor = cria_vetor(n)
	
	m, i = media(vetor)
	print("\nMedia: %.1lf" % m)
	print("\nPosicao do valor mais proximo da media: %d\n" % i)
	
if __name__ == "__main__":
	main()
