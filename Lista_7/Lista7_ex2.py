class Data:

	def __init__(self, dia, mes, ano, indice):
		self.__dia = dia
		self.__mes = mes
		self.__ano = ano
		self.__indice = indice
	
	def get_dia(self):
		return self.__dia

	def get_mes(self):
		return self.__mes

	def get_ano(self):
		return self.__ano

	def get_indice(self):
		return self.__indice

	def mostra(self):
		print(str(self.get_dia()) + '/' + str(self.get_mes()) + '/' + str(self.get_ano()))

if __name__ == "__main__":

	lista = []
	
	print("### Cadastro de Datas ###\n")
	n = int(input("Quantidade de datas: "))
	print("\nExemplo de data (dia / mes / ano: 00 00 0000\n")
	for i in range(n):
		dia, mes, ano = [int(x) for x in input("Insira uma data: ").split()]
		if dia > 0 and dia < 32 and mes > 0 and mes < 13:
			indice = dia + ((mes - 1) * 30) + ((ano - 1) * 12 * 30)	
			d = Data(dia, mes, ano, indice)
			lista.append(d)
		else:
			print("Erro: Data incorreta!")
			break

	lista.sort(key=lambda obj: obj.get_indice())
	print("\n### Datas ordenadas ###\n")
	for v in lista:		
		v.mostra()
