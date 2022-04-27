def minimo_recursivo(vetor, n):
    if n == 1:
        return vetor[0]
    else:
        aux = minimo_recursivo(vetor, n-1)
        if aux < vetor[n-1]:
            return aux
        return vetor[n-1]

def main():
	vetor = [2, 3, 1, 5, 4]
	
	print("Elemento minimo: %d\n" % minimo_recursivo(vetor, len(vetor)))

if __name__ == "__main__":
	main()
