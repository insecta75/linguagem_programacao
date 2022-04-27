def log_recursivo(n):
    if n == 1:
        return 0
    else:
        return 1 + log_recursivo(n/2)

def main():
    n = int(input("Digite o valor de n, para obter x, de 2^x = n: "))

    if n < 1:
        print("\nErro: Valores devem ser inteiros positivos!\n")
    else:
        print("Resultado: %d\n" % log_recursivo(n))

if __name__ == "__main__":
	main()
