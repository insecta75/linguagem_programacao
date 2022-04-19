def cria_matriz(n):
	matriz = []

	for i in range(n):
		linha = []
		for j in range(n):
			numero = float(input("Linha {} e Coluna {}: ".format(i+1, j+1)))
			linha.append(numero)
		matriz.append(linha)
	return matriz

def multiplica(matrizUm, matrizDois, matrizRes, n):
	soma = 0

	for i in range(n):
		linha = []
		for j in range(n):			
			for k in range(n):
				soma = soma + (matrizUm[i][k] * matrizDois[k][j])
			linha.append(soma)
			soma = 0
		matrizRes.append(linha)

def mostra_matriz(matriz, n):
	for i in range(n):
		for j in range(n):
			print(matriz[i][j], end=" ")
		print()	

def main():
	matrizUm = []
	matrizDois = []
	matrizRes = []
	n = int(input("Qual o valor do n, para a dimensao n x n da matriz: "))

	print("\nInsira os valores na matriz um:")
	matrizUm = cria_matriz(n)
	print("\nInsira os valores na matriz dois:")
	matrizDois = cria_matriz(n)

	multiplica(matrizUm, matrizDois, matrizRes, n)

	print("\nMatriz resposta:")
	mostra_matriz(matrizRes, n)

if __name__ == "__main__":
	main()
