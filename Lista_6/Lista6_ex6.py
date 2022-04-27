def cria_vetor(n):
	vetor = []
	for j in range(n):
		numero = float(input("\nInsira o %d elemento: " % (j)))
		vetor.append(numero)
	return vetor

def media(vetor):
	soma = 0
	n = len(vetor)

	for j in range(n):
		soma += vetor[j]
	m = soma / n

	aux = sorted(vetor) #organiza vetor em ordem crescente, transfere ordem para aux

	for j in range(n):
		if aux[j] > m:
			ma = aux[j]
			mi = aux[j-1]
			posma = j
			break
	
	dma = ma - m
	dmi = m - mi

	if dma > dmi:
		p = posma - 1
	else:
		p = posma
	
	for j in range(n): #compara vetores e obtem a posicao no vetor
		if(vetor[j] == aux[p]):
			i = j

	return m, i

def main():
	vetor = []
	
	n = int(input("Quantos numeros serao inseridos no vetor: "))

	vetor = cria_vetor(n)
	
	m, i = media(vetor)
	print("\nMedia: %.1lf" % m)
	print("\nPosicao do valor mais proximo da media: %d\n" % i)
	
if __name__ == "__main__":
	main()
