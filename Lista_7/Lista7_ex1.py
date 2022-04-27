class Produto:

	def __init__(self):
		self.__nome = '' #privado
		self.__preco = 0
		self.__quantidade = 0
	
	def get_nome(self):
		return self.__nome

	def get_preco(self):
		return self.__preco

	def get_quantidade(self):
		return self.__quantidade

	def cadastra(self):
		self.__nome = input("Nome: ")
		self.__preco = float(input("Preco: "))
		self.__quantidade = int(input("Quantidade: "))
	
	def mostra(self):
		print('Nome: ' + self.get_nome() +
		      '; Preco: ' + str(self.get_preco()) +
		      '; Quantidade: ' + str(self.get_quantidade()))

class Supermercado (Produto):

	def __init__(self):
		self.__lista = []
		self.__numero = 0

	def get_numero_produtos(self):
		self.__numero = int(input("Numero de produtos: "))
		return self.__numero
	
	def get_lista(self, produto):		
		produto.cadastra()
		self.__lista.append(produto)
		return self.__lista

	def ordena_produtos_preco(self):
		ordenaPreco = sorted(self.__lista, key=lambda obj: obj.get_preco())
		print("\n### Produtos ordenados pelo preco ###\n")
		for p in ordenaPreco:		
			p.mostra()
			print("----------")

	def ordena_produtos_quantidade(self):
		self.__lista.sort(key=lambda obj: obj.get_quantidade())	
		print("\n### Produtos ordenados pela quantidade ###\n")
		for q in self.__lista:		
			q.mostra()
			print("----------")

if __name__ == "__main__":
	
	s = Supermercado()

	print("### Cadastro de Produtos ###\n")
	n = s.get_numero_produtos()
	for i in range(n):
		print("----------")
		p = Produto()
		s.get_lista(p)	
	
	s.ordena_produtos_preco()
	s.ordena_produtos_quantidade()
