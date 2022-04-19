def desvio_padrao(v, tam):
	sumq = 0
	sum = 0
	i = 0
	j = 0
	for i in range(tam):
		sum = sum + v[i]
	for j in range(tam):
		sumq = sumq + (v[j] * v[j])
	
	return (sumq-((sum*sum)/tam))/(tam-1)

def main():
	i = 0
	v = []
	tam = int(input("O tamanho do vetor: "))

	print("\nInsira os valor no vetor:")
	for i in range(tam):
		r = float(input())
		v.insert(i, r)

	print("\nO desvio padrao e: %.2f\n" % desvio_padrao(v, tam))

if __name__ == "__main__":
	main()
