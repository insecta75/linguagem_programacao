class Pessoa:

	def __init__(self):
		self.__rg = 0
		self.__cpf = 0
		self.__nome = ''
	
	def get_rg(self):
		return self.__rg

	def get_cpf(self):
		return self.__cpf

	def get_nome(self):
		return self.__nome

	def cadastra(self):
		self.__rg = int(input("RG: "))
		self.__cpf = int(input("CPF: "))
		self.__nome = input("Nome: ")

class Sistema (Pessoa):

	def __init__(self):
		self.__lista = []
		self.__numero = 0

	def get_numero_pessoas(self):
		self.__numero = int(input("Numero de pessoas: "))
		return self.__numero

	def get_lista(self, pessoa):		
		pessoa.cadastra()
		self.__lista.append(pessoa)
		return self.__lista

	def mostra(self):
		for p in self.__lista:
			print('RG: ' + str(p.get_rg()) +
			      '; CPF: ' + str(p.get_cpf()) +
			      '; Nome: ' + p.get_nome())	

	def busca_binaria(self, chave):
		ini = 0
		fim = self.__numero - 1
		ordena = sorted(self.__lista, key=lambda obj: obj.get_rg())
		
		while ini <= fim:
			meio = int((ini + fim) / 2)
			if ordena[meio].get_rg() == chave:
				return meio
			elif ordena[meio].get_rg() > chave:
				fim = meio - 1
			else:
				ini = meio + 1
		return -1
		
if __name__ == "__main__":

	s = Sistema()
	q = 's'

	print("### Cadastro de Pessoas ###\n")
	n = s.get_numero_pessoas()
	for i in range(n):
		print("----------")		
		p = Pessoa()
		s.get_lista(p)
	
	while(q == 's'):
		chave = int(input("\nDigite o numero de RG a ser buscado: "))
		r = s.busca_binaria(chave)
		if r == -1:
			print("\nRG nao foi encontrado!\n")
		else:
			print("\nRG foi encontrado!\n")

		q = input("\nFazer nova busca (s/n): ")
		if q == 'n':
			break

	print("\n### Pessoas cadastradas ###\n")
	s.mostra()
