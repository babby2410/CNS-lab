import math

def gcdExt( a, m ):
	a = int(a%m)
	b = int(m)

	xold = 1
	x = 0
	xnew = -1
	while( b>1 ):
		q = a//b
		r = a%b

		xnew = xold - q*x
		xold = x
		x = xnew

		a = b
		b = r

	x = x%m

	return x

def get_coprime( tot, start = 2 ):
	for e in range(start, tot-1):
		if math.gcd(e, tot)==1:
			return e
	return -1

def main():
	p, q = map(int, ( input( "Enter the 2 prime numbers : " ).split() ) );

	n = p*q
 	tot = (p-1)*(q-1)
	print("n = p*q =", n)
	print( tot(n) =", tot)

	start = int( input( "Enter the minimum value of e : " ) )

	e = get_coprime( tot, start )
	print("e =", e)

	d = gcdExt(e, tot)
	print("d =", d)

	msg = int( input("Enter the number to be encrypted between " + str(1) + " and " + str tot-1) + " : ") )

	cipherText = pow( msg, e, n )
	decipheredText = pow(cipherText, d, n)

	print("Ciphertext :", cipherText)
	print( "Deciphered Text :", decipheredText )


main()