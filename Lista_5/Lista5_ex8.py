def cria_matriz(n): 
	matriz = []

	for i in range(n):
		linha = []
		for j in range(n):
			numero = float(input("Linha {} e Coluna {}: ".format(i+1, j+1)))
			linha.append(numero)
		matriz.append(linha)
	return matriz

def transposta(matriz, matrizRes, n): #void
	for i in range(n):
		linha = []
		for j in range(n):
			linha.append(matriz[j][i])
		matrizRes.append(linha)	

def mostra_matriz(matriz, n): #void
	for i in range(n):
		for j in range(n):
			print(matriz[i][j], end=" ")
		print()	

def main():
	matriz = []
	matrizRes = []
	n = int(input("Qual o valor do n, para a dimensao n x n da matriz: "))	

	print("\nInsira os valores na matriz:")
	matriz = cria_matriz(n)
	transposta(matriz, matrizRes, n)

	print("\nMatriz:")
	mostra_matriz(matriz, n)
	print("\nMatriz transposta:")
	mostra_matriz(matrizRes, n)

if __name__ == "__main__":
	main()
