"""
No exemplo:
Entrada: j, Saida: i
Cidades: 0, 1, 2
Cidades com apenas entrada: 1
Cidades com apenas saida: nulo
Cidades com entrada e saida: 0 e 2
Cidades sem entrada e sem saida: nulo
valor 1 para ok e valor 0 para nulo
"""
def cria_matriz(n):
	matriz = []

	for s in range(n):
		linha = []
		for e in range(n):
			#Na estrada, (e) representa entrada e (s) saida de cada cidade
			if s == e:
				linha.append(0)
			else:
				numero = int(input("\nSaida da cidade {} indo para Entrada da cidade {}: ".format(s, e)))
				linha.append(numero)
		matriz.append(linha)
	return matriz

def mostra_matriz(matriz, n):
	for s in range(n):
		for e in range(n):
			print(matriz[s][e], end=" ")
		print()

def verifica(matriz, n): #erro
	comEntrada = []
	comSaida = []
	resposta = []

	for i in range(n):
		comEntrada.insert(i, 0)
		comSaida.insert(i, 0)
		resposta.insert(i, 0)
	
	#Cidades com entrada
	for c in range(n):
		for s in range(n):
			for e in range(n):
				if c == e and matriz[s][e] == 1:
					comEntrada[c] = 1
	#Cidades com saida
	for c in range(n):
		for s in range(n):
			for e in range(n):
				if c == s and matriz[s][e] == 1:
					comSaida[c] = 1

	#Verifica quais cidades tem entrada e saida
	for i in range(n):
		if comEntrada[i] == 1 and comSaida[i] == 1:
			resposta[i] = 1

	print("\nCidades com entrada e saida: ")
	for i in range(n):
		if resposta[i] == 1:
			print(i)

	for i in range(n):
		resposta[i] = 0

	#Verifica quais cidades tem entrada, mas nao tem saida
	for i in range(n):
		if comEntrada[i] == 1 and comSaida[i] == 0:
			resposta[i] = 1

	print("\nCidades com entrada, mas sem saida: ")
	for i in range(n):
		if resposta[i] == 1:
			print(i)

	for i in range(n):
		resposta[i] = 0

	#Verifica quais cidades nao tem entrada, mas tem saida
	for i in range(n):
		if comEntrada[i] == 0 and comSaida[i] == 1:
			resposta[i] = 1	

	print("\nCidades com saida, mas sem entrada: ")
	for i in range(n):
		if resposta[i] == 1:
			print(i)

	for i in range(n):
		resposta[i] = 0	

	#/Verifica quais cidades estao isoladas
	for i in range(n):
		if comEntrada[i] == 0 and comSaida[i] == 0:
			resposta[i] = 1	

	print("\nCidades que estao isoladas: ")
	for i in range(n):
		if resposta[i] == 1:
			print(i)

	print()

def main():
	matriz = []
	resposta = []
	n = int(input("Digite o valor de n (numero de cidades) para a matriz n x n: "))
	
	print("\nDigite se ha estradas indo para a cidade (0 ausente, 1 existente):")
	matriz = cria_matriz(n)

	print("\nMatriz:")
	mostra_matriz(matriz, n)

	print("\nRespostas:")
	verifica(matriz, n)

if __name__ == "__main__":
	main()
