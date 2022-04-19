def media(v, tam):
	sum = 0
	i = 0
	for i in range(tam):
		sum = sum + v[i]
	return sum / tam	

def main():
	i = 0
	v = []
	tam = int(input("O tamanho do vetor: "))

	print("\nInsira os valor no vetor:")
	for i in range(tam):
		r = float(input())
		v.insert(i, r)

	print("\nA media aritmetica e: %.2f\n" % media(v, tam))

if __name__ == "__main__":
	main()
