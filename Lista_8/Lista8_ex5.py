def media_recursivo(vetor, n, tam):
    if n == 1:
        return vetor[0]
    else:
        aux = media_recursivo(vetor, n-1, tam)
        if n == tam:
            return (vetor[n-1] + aux) / tam
        else:
            return vetor[n-1] + aux

def main():
	vetor = [2, 3.5, 10, 5.2, 4.7]
	
	print("Media dos elementos: %.2f\n" % media_recursivo(vetor, len(vetor), len(vetor)))

if __name__ == "__main__":
	main()
