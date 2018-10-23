#include<bits/stdc++.h>
using namespace std;

void invert(char &ch)
{
	if(ch=='0')
		ch='1';
	else
		ch='0';
}

string stringXOR( string str1, string str2 )
{
	for( int i=0;i<str1.length() && i<str2.length();i++ )
		if( str2[i]=='1' )
			invert(str1[i]);
	
	return str1;
}

string fast_bit_mul( string poly1, string poly2, string irred )
{
	irred = irred.substr(1);
	int degree = irred.length();
	
	if(poly1.length()!=degree || poly2.length()!=degree)
		return "Inconsistent degrees of polynomials";
	
	string ans(degree, '0');
	string temp = poly1;
	
	for( int i=0;i<degree;i++ )
	{
		cout<<poly1<<" * x^"<<i<<" = "<<temp<<endl;
		if( poly2[degree-i-1]=='1' )
			ans = stringXOR( ans, temp );
		
		bool firstBitSet = (temp[0]=='1');
		
		temp = temp.substr(1) + "0";
		
		if(firstBitSet)
			temp = stringXOR(temp, irred);
	}
	
	return ans;
}

int main()
{
	string poly1, poly2, irred;
	
	cout<<"Enter the coefficients of irreducible polynomial (e.g. x^3+x+1 as 1011) : ";
	cin>>irred;
	
	cout<<"Enter the coefficients of poly1 (e.g. x+1 as 011) : ";
	cin>>poly1;
	
	cout<<"Enter the coefficients of poly2 (e.g. x^2+1 as 101) : ";
	cin>>poly2;
	
	string ans = fast_bit_mul( poly1, poly2, irred );
	
	cout<<"\nResult of multiplication : \n "<<ans<<endl;
	
	return 0;
}
