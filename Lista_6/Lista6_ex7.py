def cria_vetor(n):
	vetor = []
	for j in range(n):
		numero = int(input("\nInsira o %d elemento: " % (j+1)))
		vetor.append(numero)
	return vetor

def frequencias(vetor):
	n = len(vetor)
	c = 0

	for i in range(n):
		for j in range(n):
			if vetor[i] == vetor[j]:
				c += 1 #Contagem do elemento atual
		if i == 0:
			cMe = c
			nMe = vetor[0]
			cMa = c
			nMa = vetor[0]
		else: #Verifica o Menor e Maior
			if c > cMa: #Elemento com maior frequencia
				nMa = vetor[i]
				cMa = c
			if c < cMe: #Elemento com menor frequencia
				nMe = vetor[i]
				cMe = c
		c = 0

	return nMe, nMa

def main():
	vetor = []

	n = int(input("Quantos numeros serao inseridos no vetor: "))
	vetor = cria_vetor(n)
	
	f1, f2 = frequencias(vetor)
	print("\nf1: %d; f2: %d\n" % (f1, f2))
	
if __name__ == "__main__":
	main()
