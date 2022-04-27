def busca_recursiva(vetor, ini, fim, chave):
	meio = int((ini + fim) / 2)	
		
	if fim < 0 or ini > fim:
		return -1
	else:
		if vetor[meio] == chave:
			return meio
		elif vetor[meio] > chave:
			fim = meio - 1
			return busca_recursiva(vetor, ini, fim, chave)
		else:
			ini = meio + 1
			return busca_recursiva(vetor, ini, fim, chave)

def main():
	vetor = [20, 5, 15, 24, 67, 45, 1, 76, 78, 100]
	chave = 15
	ini = 0
	fim = len(vetor) - 1
	
	ordena = sorted(vetor, key=lambda elem: elem)
	print("Vetor ordenado: ")
	print(ordena)
	pos = busca_recursiva(ordena, ini, fim, chave)

	if pos != -1:
		print("\nA posicao da chave {} no vetor é: {}\n".format(chave, pos))
	else:
		print("\nA chave {} não está no vetor! \n".format(chave)) 

if __name__ == "__main__":
	main()
