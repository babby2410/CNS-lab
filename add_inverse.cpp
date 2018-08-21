#include <bits/stdc++.h>
#include <gmpxx.h>
#include <gmp.h>

using namespace std;

int main(){
	
	int N;
	cout<<"Enter the number : "<<endl;
	cin>>N;

	mpz_class mod = N;
	vector<vector<mpz_class> > arr_m(N,vector<mpz_class>(N));

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mpz_class a,b,c;
			a = i;
			b = j;
			c = a+b;
			c = c%mod;

			if(c == 0){
				arr_m[i][j] = 1;
			}
			else{
				arr_m[i][j] = c;
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<arr_m[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}