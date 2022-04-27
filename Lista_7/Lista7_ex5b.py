def busca_binaria(vetor, chave):
	posicoes = []
	n = 0
	ini = 0
	fim = len(vetor) - 1
	ordena = sorted(vetor, key=lambda elem: elem)
		
	while ini <= fim:
		meio = int((ini + fim) / 2)

		if ordena[meio] == chave:
			posicoes.insert(n, meio)
			n += 1

			k = meio - 1
			while k >= ini: #Verifica valores inferiores ao meio
				if ordena[k] == chave:
					posicoes.insert(n, k)
					n += 1
				else:
					break
				k -= 1
			
			k = meio + 1
			while k <= fim: #Verifica valores superiores ao meio
				if ordena[k] == chave:
					posicoes.insert(n, k)
					n += 1
				else:
					break
				k += 1
			
			break
		elif ordena[meio] > chave:
			fim = meio - 1
		else:
			ini = meio + 1

	return posicoes, n, ordena
		
def main():
	vetor = [20, 5, 1, 1, 5, 1, 1, 76, 78, 100]
	chave = 5
	
	resp = busca_binaria(vetor, chave)
	posicoes = resp[0]
	n = resp[1]
	ordena = resp[2]

	print("Vetor nao Ordenado: ");
	for i in range(len(vetor)):
		print(vetor[i], end =" ")
	print("\n")

	print("Vetor Ordenado: ");
	for i in range(len(vetor)):
		print(ordena[i], end =" ")
	print("\n")
	
	if n != 0:
		print("No vetor a chave %d aparece %d vez(es). As posicoes seriam:" % (chave, n), end =" ")
		for i in range(n):
			print(posicoes[i], end =" ")
		print("\n")
	else:		
		print("A chave %d não está no vetor!\n" % chave)

if __name__ == "__main__":
	main()
