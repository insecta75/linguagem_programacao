def busca(vetor, chave):
	n = 0
	posicoes = []

	for i in range(len(vetor)):
		if vetor[i] == chave:
			posicoes.append(i)
			n += 1
	return posicoes, n			
		
def main():
	vetor = [20, 5, 15, 24, 67, 45, -1, 76, -1, -1]
	chave = -1	

	resp = busca(vetor, chave)
	posicoes = resp[0]
	n = resp[1]
	
	if n != 0:
		print("No vetor a chave %d aparece %d vez(es). As posicoes seriam:" % (chave, n), end =" ")
		for i in range(n):
			print(posicoes[i], end =" ")
		print("\n")
	else:		
		print("A chave %d não está no vetor!\n" % chave)

if __name__ == "__main__":
	main()
