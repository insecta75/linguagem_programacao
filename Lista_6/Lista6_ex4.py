def menor_base_log(n):
	B = 2	
	k = 0
	x = n	
	while B <= x:
		if n % B == 0:
		    n = n/B;
		    k += 1; #retorna k
		    if n == 1:
		        b = B #retorna o menor b
		        return b, k		    
		else:
		    n = x #n volta ao valor inicial
		    k=0 #k volta ao valor inicial
		    B += 1 #soma 1 ao b
		
def main():
	n = int(input("Digite o valor de n, da formula b^k = n: "))
	
	if n < 1:
		print("\nO numero n deve ser inteiro e positivo!\n")
	elif n == 1:
		print("\nOs valores de b e k seriam: 1\n")
	else:
		b, k = menor_base_log(n)
		print("\nOs valores seriam. b: %d, k: %d\n" % (b, k))

if __name__ == "__main__":
	main()
