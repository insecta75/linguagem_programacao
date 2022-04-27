def funcao(n):
    if n == 0:
        return 0
    else:
        return n + funcao(n-1)

def main():
	#Soma os valores (ex: 0+1+2+3+4+5=15)
	print("Resultado: %d\n" % funcao(5))

if __name__ == "__main__":
	main()
