#include<bits/stdc++.h>
#define twoDImat vector<vector<int> >
#define twoDFmat vector<vector<double> >
#define oneDarr vector<int>
#define pb push_back
#define pf push_front
using namespace std;

void getCofactor(twoDImat &A, twoDImat &temp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
int determinant(twoDImat &A,int n)
{
    int D = 0; 
    if (n == 1)
        return A[0][0];
 
    twoDImat temp(n,oneDarr(n,0)); 
 
    int sign = 1; 
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
 
    return D;
}

void adjoint(twoDImat &A,twoDImat &adj)
{   
    int N = A.size();
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    twoDImat temp(N,oneDarr(N,0));
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            getCofactor(A, temp, i, j, N);
            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}


int mulInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}


void vdisplay(twoDImat &arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        for (int j=0; j<arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void fill_keymat(twoDImat &key_mat,string & key,int m){

    int ind = 0,start = 'a',len = key.length();

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(ind < len)
                key_mat[i][j] = key[ind++] - 'a';
            else{
                key_mat[i][j] = (start - 'a')%26;
                start++;
            }
        }
    }
}
int combine(twoDImat &key_mat,twoDImat &col_mat,int i,int j,int m){
    
    int ans = 0;
    for(int k=0;k<m;k++){
        ans += key_mat[i][k]*col_mat[k][j];
    }

    return ans%26;
}

string Encrypt(string &text,twoDImat &key_mat){

    string ans;
    int m = key_mat.size(),ind = 0,len = text.length();
    twoDImat col_mat(m);

    while(ind < len){
        col_mat[ind%m].pb(text[ind] - 'a');
        ind++;
    }

    while(ind%m != 0){
        col_mat[ind%m].pb('x' - 'a');
        ind++;
    }

    twoDImat res_mat(col_mat.size(),oneDarr(col_mat[0].size(),0));

    for(int i=0;i<col_mat.size();i++){
        for(int j=0;j<col_mat[i].size();j++){
            res_mat[i][j] = combine(key_mat,col_mat,i,j,m);
        }
    }

    for(int j=0;j<res_mat[0].size();j++){
        for(int i=0;i<res_mat.size();i++){
            ans.pb('a' + res_mat[i][j]);
        }
    }

    return ans;
}

void mod_with(twoDImat &adj,int k){
    
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j] >= 0)
                adj[i][j]%=k;
            else{
                while(adj[i][j]<0)
                    adj[i][j]+=k;
            }
        }
    }
}

void get_keyinv(twoDImat &adj,int inv){

    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            adj[i][j]*=inv;
            adj[i][j]%=26;
        }
    }
}

string Decrypt(string &text,twoDImat &key_mat){

    string ans;
    int m = key_mat.size(),ind = 0,len = text.length();
    int det = determinant(key_mat,m);
    det%=26;
    det = mulInverse(det,26);
    
    twoDImat adj(m,oneDarr(m,0));
    adjoint(key_mat,adj);
    mod_with(adj,26);
    get_keyinv(adj,det);

    twoDImat col_mat(m);

    while(ind < len){
        col_mat[ind%m].pb(text[ind] - 'a');
        ind++;
    }

    while(ind%m != 0){
        col_mat[ind%m].pb('x' - 'a');
        ind++;
    }

    twoDImat res_mat(col_mat.size(),oneDarr(col_mat[0].size(),0));

    for(int i=0;i<col_mat.size();i++){
        for(int j=0;j<col_mat[i].size();j++){
            res_mat[i][j] = combine(adj,col_mat,i,j,m);
        }
    }

    for(int j=0;j<res_mat[0].size();j++){
        for(int i=0;i<res_mat.size();i++){
            ans.pb('a' + res_mat[i][j]);
        }
    }

    return ans;
}

string EorD(string &text,int operation,twoDImat &key_mat){

    if (operation)
        return Decrypt(text,key_mat);
    return Encrypt(text,key_mat);
}

int main(){

    int m;
    cout<<endl<<"Enter key matrix size : ";
    cin>>m;
    cin.ignore();

    string key;
    cout<<endl<<"Enter the key : ";
    getline(cin,key);

    twoDImat key_mat(m,oneDarr(m,0));
    fill_keymat(key_mat,key,m);
    vdisplay(key_mat);

    int operation;
    cout<<endl<<"Enter the operation(0 --> Encrypt, 1 --> Decrypt): ";
    do{
        cin>>operation;
        cin.ignore();
        if(!(operation == 1 || operation == 0))
            cout<<endl<<"Input error, please enter again !";
    }while(!(operation == 1 || operation == 0));

    string text;
    if(operation)
        cout<<endl<<"Enter the text to decrypt : ";
    else
        cout<<endl<<"Enter the text to encrypt : ";
    getline(cin,text);

    string ans = EorD(text,operation,key_mat);

    cout<<endl<<"Resultant text: "<<ans;
    cout<<endl<<"Original text after reverse operation: "<< EorD(ans,operation^1,key_mat)<<endl<<endl;
    
    return 0;
}

    

