#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;

void gcd(mpz_t a,mpz_t b,mpz_t x,mpz_t y){
    mpz_t zero,one;
    mpz_init_set_str(zero, "0", 10);
    mpz_init_set_str(one, "1", 10); 
    if (mpz_sgn(a) == 0){
    	mpz_set(x,zero);
    	mpz_set(y,one);
        gmp_printf("GCD is %Zd\n",b);   
       return;
    }
    
    mpz_t x1,y1,v1;
    mpz_init(x1);
    mpz_init(y1);
    mpz_init(r1);
    mpz_mod(r1,b,a);
    gmp_printf("Reminder : %Zd\n",v1); 
    gcd(r1,a,x1,y1);
    mpz_t val;
    mpz_init(val);
    mpz_div(val,b,a);
    mpz_mul(val,val,x1);
    mpz_sub(x,y1,val);
    mpz_set(y,x1);
    
    return ;
}

int main(void) {
 mpz_t x,y,result,x1,y1;

 char a[100],b[100];
 cin>>a>>b;
 
 mpz_init_set_str(x, a, 10);
 mpz_init_set_str(y, b, 10);
 mpz_init(result);
 mpz_init(x1);
 mpz_init(y1);
 
 mpz_gcd(result, x, y);

 cout<<"Inbuilt Result"<<endl;
 gmp_printf("GCD of %Zd and %Zd is %Zd\n",x,y,result);
 cout<<endl<<"With function"<<endl;
 
 const clock_t begin_time = clock();
 gcd(x,y,x1,y1);
 mpz_clear(x);
 mpz_clear(y);
 mpz_clear(result);
 
 gmp_printf("x,y : %Zd and %Zd\n",x1,y1);

 cout <<endl<< "Execution time : "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC;
 cout<<endl;
 return 0;
}


/*
Inputs:
7612058254738945 9263591128439081
12 10
9263591128439081 12345
123456789123456789182 35463435475663738485
7 3
*/
