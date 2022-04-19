def cria_matriz():
	matriz = []
	
	for i in range(9):
		linha = []
		for j in range(9):
			numero = int(input("Linha {} e Coluna {}: ".format(i+1, j+1)))			
			linha.append(numero)
		matriz.append(linha)
	return matriz

def mostra_matriz(matriz):
	for i in range(9):
		for j in range(9):
			print(matriz[i][j], end=" ")
		print()

def solucao(matriz):
	vetor = []
	
	#Verifica a linha da matriz por numeros repetidos
	for i in range(9):
		for j in range(9):
			k = j + 1
			while k < 9:
				if matriz[i][j] == matriz[i][k]:
					return 0
				k += 1
	
	#Verifica a coluna da matriz por numeros repetidos
	for i in range(9):
		for j in range(9):
			k = j + 1
			while k < 9:
				if matriz[j][i] == matriz[k][i]:
					return 0
				k += 1
	
	#Verifica em cada quadrado da matriz por numeros repetidos
	v = 0
	n = 3
	while n < 10: #Analisa os tres quadrados a esquerda
		i = v
		while i < n:
			for j in range(3):
				vetor.append(matriz[i][j])
			i += 1

		for i in range(9):
			j = i + 1
			while j < 9:
				if vetor[i] == vetor[j]:
					return 0
				j += 1

		v += 3
		n += 3
	vetor.clear()	
	
	v = 0
	n = 3
	while n < 10: #Analisa os tres quadrados do meio
		i = v
		while i < n:
			j = 3
			while j < 6:
				vetor.append(matriz[i][j])
				j += 1
			i += 1

		for i in range(9):
			j = i + 1
			while j < 9:
				if vetor[i] == vetor[j]:
					return 0
				j += 1

		v += 3
		n += 3
	vetor.clear()	
	
	v = 0
	n = 3
	while n < 10: #Analisa os tres quadrados a direita
		i = v
		while i < n:
			j = 6
			while j < 9:
				vetor.append(matriz[i][j])
				j += 1
			i += 1

		for i in range(9):
			j = i + 1
			while j < 9:
				if vetor[i] == vetor[j]:
					return 0
				j += 1

		v += 3
		n += 3	
	
	return 1

def main():
	matriz = []

	print("Jogo Sudoku (matriz: 9x9).\n")
	print("Preencha todas as posicoes com valores de 1 a 9.\n")
	matriz = cria_matriz()

	print("\nMatriz criada:")
	mostra_matriz(matriz)
	
	resp = solucao(matriz)
	if resp == 1:
		print("\nA matriz proposta representa uma solucao sudoku!\n")
	else: 
		print("\nA matriz proposta NAO representa uma solucao sudoku!\n")
	

if __name__ == "__main__":
	main()
