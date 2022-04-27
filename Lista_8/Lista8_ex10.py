def busca_sequencial(vetor, tam, chave):
	if tam == 1:
		if vetor[0] == chave:
			return 0
		else:
			return -1
	else:
		if vetor[tam-1] == chave:
			return tam - 1
		return busca_sequencial(vetor, tam-1, chave)

def main():
	vetor = [20, 5, 15, 24, 67, 45, 1, 76, -10, -1]
	chave = 45

	pos = busca_sequencial(vetor, len(vetor), chave)

	if pos != -1:
		print("\nA posicao da chave {} no vetor é: {}\n".format(chave, pos))
	else:
		print("\nA chave {} não está no vetor! \n".format(chave)) 

if __name__ == "__main__":
	main()
