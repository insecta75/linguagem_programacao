def cria_matriz(n):
	matriz = []
	
	for i in range(n):
		linha = []
		for j in range(n):
			numero = int(input("Linha {} e Coluna {}: ".format(i+1, j+1)))
			linha.append(numero)
		matriz.append(linha)
	return matriz

def mostra_matriz(matriz, n):
	for i in range(n):
		for j in range(n):
			print(matriz[i][j], end=" ")
		print()

def magico(matriz, n):
	vetor = []
	soma = 0
	#Soma linhas
	for i in range(n):
		for j in range(n):
			soma = soma + matriz[i][j] 
		vetor.append(soma)
		soma = 0
	#Soma colunas
	for i in range(n):
		for j in range(n):
			soma = soma + matriz[j][i] 
		vetor.append(soma)
		soma = 0
	#Soma diagonal principal
	for i in range(n):
		soma = soma + matriz[i][i] 
	vetor.append(soma)
	soma = 0
	#Soma diagonal secundaria
	i = 0
	j = n - 1
	while i < n and j >= 0:
		soma = soma + matriz[i][j]
		i += 1
		j -= 1
	vetor.append(soma)
	#Comparacao final
	for i in range(len(vetor)):
		if vetor[0] != vetor[i]:
			return False
	return True

def main():
	matriz = []
	n = int(input("Qual o valor do n, para a dimensao n x n da matriz: "))

	print("\nInsira os valores na matriz:")
	matriz = cria_matriz(n)

	print("\nMatriz:")
	mostra_matriz(matriz, n)

	verifica = magico(matriz, n)

	if verifica:
		print("\nA matriz e um quadrado magico!\n")
	else:
		print("\nA matriz nao e um quadrado magico!\n") 

if __name__ == "__main__":
	main()
