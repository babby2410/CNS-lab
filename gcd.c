#include <gmp.h>
#include <stdio.h>
void gcd(mpz_t ans,mpz_t a,mpz_t b){
        mpz_t r;
        mpz_init(r);
        while(mpz_sgn(b)!=0){
                mpz_mod(r,a,b);
                mpz_set(a,b);
                mpz_set(b,r);
        }
        mpz_set(ans,a);
}
void fibo(mpz_t ans,int n){
        mpz_t f1,f2,f3;
        int i;
        mpz_init_set_ui(f1,1);
        mpz_init_set_ui(f2,1);
        for(i=0;i<n;i++){
                mpz_add(f3,f1,f2);
                mpz_set(f1,f2);
                mpz_set(f2,f3);
        }
        mpz_set(ans,f2);
}
int main(){
        //Intialisation
        mpz_t a,b,r,ans;
        mpz_init(a);
        mpz_init(b);
        mpz_init(r);
        mpz_init(ans);

        //Fixed Input
        mpz_set_str(a,"4864",10);
        mpz_set_str(b,"3458",10);
        gmp_printf ("Test Case 1 Trivial Input\n%Zd %Zd\n", a,b);
        mpz_gcd(r,a,b);
        gcd(ans,a,b);
        gmp_printf ("Predefined %Zd\n", r);
        gmp_printf ("Function %Zd\n", ans);


        //Random Number 
        unsigned long int i, seed;
    gmp_randstate_t r_state;
    seed = 123456;

    gmp_randinit_default (r_state);
    gmp_randseed_ui(r_state, seed);
    mpz_urandomb(a,r_state,51);
    mpz_urandomb(b,r_state,42);
    gmp_printf ("Test Case 2 Random Numbers\n%Zd %Zd\n", a,b);

        mpz_gcd(r,a,b);
        gmp_printf ("Predefined %Zd\n", r);
        gcd(ans,a,b);
        gmp_printf ("Function %Zd\n", ans);


        //GCD of consecutive fibonacci numbers is 1.
        //fibo Calculates nth fibonacci number 
        fibo(a,201);
        fibo(b,200);
        gmp_printf ("Test Case 3 Fibonacci Numbers\n%Zd %Zd\n", a,b);
        mpz_gcd(r,a,b);
        gmp_printf ("Predefined %Zd\n", r);
        gcd(ans,a,b);
        gmp_printf ("Function %Zd\n", ans);

        //Clear
        mpz_clear(a);
        mpz_clear(b);
        mpz_clear(r);
}

