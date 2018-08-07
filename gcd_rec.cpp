#include<gmp.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

long int gcd(mpz_t a,mpz_t b){
        if(mpz_cmp_d(a,1) == 0 || mpz_cmp_d(b,1) == 0){
                mpz_t ans;
                mpz_set_str(ans,"1",10);
                return mpz_get_si(ans);
        }

        if(mpz_cmp(a,b) < 0){
                return gcd(b,a);
        }

        mpz_t r;
        mpz_init(r);
        mpz_mod(r,a,b);

        if(mpz_sgn(r) == 0){
                return mpz_get_si(b);
        }

        mpz_set(a,b);
        mpz_set(b,r);

        return gcd(a,b);
}


int main(int argc,char* args[]){

        if(argc != 3){
                printf("Usage : gcd_rec a b");
        }

        mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
        long int ans;
        mpz_set_str(a,args[1],10);
        mpz_set_str(b,args[2],10);
	clock_t start = clock();
	ans = gcd(a,b);
	
	cout<<endl<<"Execution time : "<<(float)(clock() - start)/CLOCKS_PER_SEC;
        gmp_printf("GCD of input : %Zd and %Zd is %d\n",a,b,ans);
        return 0;
}
