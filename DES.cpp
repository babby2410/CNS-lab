#include <bits/stdc++.h>
using namespace std;

string _bitbin(int val,int len = 8){
	string ans = "";
	for(int i=0;i<len;i++){
		if(val%2)
			ans += "1";
		else
			ans += "0";
		val /= 2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

string strtobin(string &str){
	string binstr = "";
	for(int i=0;i<str.length();i++){
		binstr += _bitbin((unsigned char)str[i]);
	}
	return binstr;
}

int binstrtoint(string str){
	int p = 1;
	int ans = 0;
	for(int i=str.length() - 1;i>=0;i--)
	{
		if(str[i] == '1')
			ans += p;
		p = p*2;
	}
	return ans;
}

void cir_shift(string &text,int num,bool rshift = false){
	int upto = num;
	if(rshift)
		 upto = text.length() - num;
	
	reverse(text.begin(),text.begin() + upto);
	reverse(text.begin() + upto,text.end());
	reverse(text.begin(),text.end());
}

string strXOR(string str1,string str2){
	for(int i=0;i<str1.length();i++)
		str1[i] = (str1[i] + str2[i] - '0' - '0')%2 + '0';
	return str1;
}

string toText(string str){
	string ans = "";
	for(int i=0;i<str.length();i+=8)
		ans += (unsigned char)binstrtoint(str.substr(i, 8));
	return ans;
}

string _IP(string text){
	int iptab[] = {
		58, 50, 42, 34, 26, 18, 10, 2, 
		60, 52, 44, 36, 28, 20, 12, 4, 
		62, 54, 46, 38, 30, 22, 14, 6, 
		64, 56, 48, 40, 32, 24, 16, 8, 
		57, 49, 41, 33, 25, 17, 9, 1, 
		59, 51, 43, 35, 27, 19, 11, 3, 
		61, 53, 45, 37, 29, 21, 13, 5, 
		63, 55, 47, 39, 31, 23, 15, 7
	};
	
	string ans = "";
	for(int i=0;i<64;i++)
		ans += text[iptab[i] - 1];
	return ans;
}

string _PC1(string text){
	int pc1tab[] = {
		57, 49, 41, 33, 25, 17, 9, 
		1, 58, 50, 42, 34, 26, 18, 
		10, 2, 59, 51, 43, 35, 27, 
		19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15, 
		7, 62, 54, 46, 38, 30, 22, 
		14, 6, 61, 53, 45, 37, 29, 
		21, 13, 5, 28, 20, 12, 4
	};

	string ans = "";
	for(int i=0;i<56;i++)
		ans += text[pc1tab[i] - 1];
	return ans;
}

string _PC2(string text){
	int pc2tab[] = {
		14, 17, 11, 24, 1, 5, 3, 28, 
		15, 6, 21, 10, 23, 19, 12, 4, 
		26, 8, 16, 7, 27, 20, 13, 2, 
		41, 52, 31, 37, 47, 55, 30, 40, 
		51, 45, 33, 48, 44, 49, 39, 56, 
		34, 53, 46, 42, 50, 36, 29, 32
	};

	string ans = "";
	for(int i=0;i<48;i++)
		ans += text[pc2tab[i] - 1];
	return ans;
}

string _expPerm(string text){
	int expPermtab[] = {
		32, 1, 2, 3, 4, 5, 
		4, 5, 6, 7, 8, 9, 
		8, 9, 10, 11, 12, 13, 
		12, 13, 14, 15, 16, 17, 
		16, 17, 18, 19, 20, 21, 
		20, 21, 22, 23, 24, 25, 
		24, 25, 26, 27, 28, 29, 
		28, 29, 30, 31, 32, 1
	};

	string ans = "";
	for(int i=0;i<48;i++)
		ans += text[expPermtab[i] - 1];
	return ans;
}

string _substitution(string text){
	int sub_boxes[][64] = {
		{
			14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 
			0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 
			4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 
			15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
		},
		{
			15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 
			3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 
			0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 
			13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
		},
		{
			10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 
			13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 
			13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 
			1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
		},
		{
			7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 
			13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 
			10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 
			3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
		},
		{
			2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
			14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
			4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
			11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
		},
		{
			12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 
			10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
			9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
			4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
		},
		{
			4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 
			13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 
			1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
			6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
		},
		{
			13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 
			1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
			7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
			2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
		}
	};
	
	string ans = "";
	for( int i=0;i<text.length();i+=6)
	{
		int row = binstrtoint(text.substr(i,1) + text.substr(i + 5,1));
		int col = binstrtoint(text.substr(i + 1,4));
		
		int _sub = sub_boxes[i / 8][row*16 + col];
		ans += _bitbin(_sub, 4);
	}
	return ans;
}

string _permutation(string text){
	int permtab[] = {
		16, 7, 20, 21, 29, 12, 28, 17, 
		1, 15, 23, 26, 5, 18, 31, 10, 
		2, 8, 24, 14, 32, 27, 3, 9, 
		19, 13, 30, 6, 22, 11, 4, 25
	};

	string ans = "";
	for(int i=0;i<32;i++)
		ans += text[permtab[i] - 1];
	return ans;
}

string _inversePerm(string text){
	int invpermtab[] = {
		40, 8, 48, 16, 56, 24, 64, 32, 
		39, 7, 47, 15, 55, 23, 63, 31, 
		38, 6, 46, 14, 54, 22, 62, 30, 
		37, 5, 45, 13, 53, 21, 61, 29, 
		36, 4, 44, 12, 52, 20, 60, 28, 
		35, 3, 43, 11, 51, 19, 59, 27, 
		34, 2, 42, 10, 50, 18, 58, 26, 
		33, 1, 41, 9, 49, 17, 57, 25, 
	};

	string ans = "";
	for(int i=0;i<64;i++)
		ans += text[invpermtab[i] - 1];
	return ans;
}

string _DEShelper(string text,string key,bool decrypt){
	text = strtobin(text);
	text = _IP(text);
	key = _PC1(key);

	string key_l = key.substr(0,28);
	string key_r = key.substr(28);
	string text_l = text.substr(0,32);
	string text_r = text.substr(32);

	int numshifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 0 };
	int numrounds = 16;

	for(int i=0;i<numrounds;i++){
		if(decrypt){
			cir_shift(key_l,numshifts[numrounds - i],true);
			cir_shift(key_r,numshifts[numrounds - i],true);
		}
		else{
			cir_shift(key_l,numshifts[i]);
			cir_shift(key_r,numshifts[i]);
		}

		string roundkey = _PC2(key_l + key_r);
		string roundtext = _expPerm(text_r);
		roundtext = strXOR(roundtext,roundkey);
		roundtext = _substitution(roundtext);
		roundtext = _permutation(roundtext);
		roundtext = strXOR(text_l,roundtext);

		text_l = text_r;
		text_r = roundtext;
	}

	string bitswap = (text_r + text_l);
	return _inversePerm(bitswap);
}

string DES(string text,string key,bool decrypt){
	while(text.length()%8!=0)
		text += " ";

	key = strtobin(key); 
	cout<<"\nKey in binary: "<<key;
	string ans = "";
	for(int i=0;i<text.length();i+=8){
		ans += _DEShelper(text.substr(i,8),key,decrypt);
	}

	if(decrypt)
		cout<<"\nDecrypted text in Binary: "<<ans;
	else
		cout<<"\nEncrypted text in Binary: "<<ans;
	ans = toText(ans);
	return ans;
}

int main(){
	string plaintext, key;
	do{
		cout<<"\nEnter the key(8-charecters): ";
		getline(cin,key);
		if(key.length() != 8)
			cout<<"\nKey length should be 8-charecters, please re-enter the key";
	}while(key.length() != 8);

	cout<<"\nEnter the plaintext(No whitespace): ";
	getline(cin,plaintext);

	cout<<"\nEncrypting.........";
	string ciphertext = DES(plaintext,key,false);
	cout<<"\nEncrypted text: "<<ciphertext;

	cout<<"\nDecrypting the encrypted text...........";
	string _plaintext = DES(ciphertext,key,true);
	cout<<"\nDecrypted text: "<<_plaintext;

	return 0;
}
