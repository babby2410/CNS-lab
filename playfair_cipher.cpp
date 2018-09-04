#include<bits/stdc++.h>
using namespace std;

#define SIZE 5

string decrypt(vector<vector<char> > &keytab, map<char, pair<int, int> > &alpha, char c1, char c2); 
pair<int, int> nextepos(pair<int, int> epos);
string encrypt(vector<vector<char> > &keytab, map<char, pair<int, int> > &alpha, char c1, char c2);


int main(void) {
	string key, text, ctext, dtext;
	map<char, pair<int, int> > alpha;
	vector<char> temp(SIZE, '#');
	vector<vector<char> > keytab(SIZE, temp);
	pair<int, int> epos = make_pair(-1, -1);
	
	cout<<"Enter the key : ";
	getline(cin, key);
	
	for(char c='A'; c<='Z'; c++) 
		alpha[c] = make_pair(-1, -1);
	
	//fill the key tabled first with the distinct characters in the key
	for(int i=0; i<key.size(); i++) {
		if(!isalpha(key[i]))
			continue;
		key[i] = toupper(key[i]);
		if(key[i] == 'Q')
			continue;
		if(alpha[key[i]].first == -1) {
			epos = nextepos(epos);
			alpha[key[i]] = epos;
			keytab[epos.first][epos.second]=key[i]; 
		}
	}
	
	
	for(char c='A'; c<='Z'; c++)  {
		if(c=='Q')
			continue;
		if(alpha[c].first == -1) {
			epos = nextepos(epos);
			alpha[c] = epos;
			keytab[epos.first][epos.second]=c;
		}
	}
	
	cout<<endl<<"Table for the give key is : "<<endl;
	for(int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++)
			cout<<keytab[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl<<"Enter the text to be encrypted: ";
	getline(cin, text);
	
	
	for(int i=text.size()-1; i>=0; i--) {
		if(!isalpha(text[i])) {
			text.erase(i, 1);
			continue;
		}
		text[i] = toupper(text[i]);
		if(text[i] == 'Q')
			text[i] = 'P';
	}
	if(text.size()%2)
		text+='Z';
		
	cout<<endl<<"Entered text (after formatting) : "<<text<<endl;
	
	for(int i=0; i<text.size(); i+=2) 
		ctext+=encrypt(keytab, alpha, text[i], text[i+1]);
	
	cout<<endl<<"The cipher text is "<<ctext<<endl<<endl;
	cout<<"Decrypting encrypted text...."<<endl;
	
	for(int i=0; i<ctext.size(); i+=2)
		dtext+=decrypt(keytab, alpha, ctext[i], ctext[i+1]);
		
	cout<<endl<<"Decrypted text is : "<<dtext<<endl<<endl;
}

pair<int, int> nextepos(pair<int, int> epos) {
	if(epos.first == -1)
		return make_pair(0, 0);
	epos.second++;
	if(epos.second == SIZE) {
		epos.first++;
		epos.second=0;
	}
	return epos;
}

string encrypt(vector<vector<char> > &keytab, map<char, pair<int, int> > &alpha, char c1, char c2) {
	pair<int, int> p1 = alpha[c1], p2 = alpha[c2];
	string res="";
	
	if(p1.first == p2.first) {
		res+=keytab[p1.first][(p1.second+1)%SIZE];
		res+=keytab[p2.first][(p2.second+1)%SIZE];
	}
	
	else if(p1.second == p2.second) {
		res+=keytab[(p1.first+1)%SIZE][p1.second];
		res+=keytab[(p2.first+1)%SIZE][p2.second];
	}
	
	else {
		res+=keytab[p1.first][p2.second];
		res+=keytab[p2.first][p1.second];
	}
	return res;
}

string decrypt(vector<vector<char> > &keytab, map<char, pair<int, int> > &alpha, char c1, char c2) {
	pair<int, int> p1 = alpha[c1], p2 = alpha[c2];
	string res="";
	
	if(p1.first == p2.first) {
		int cp1 = (p1.second-1)%SIZE, cp2 = (p2.second-1)%SIZE;
		if(cp1<0)
			cp1+=SIZE;
		if(cp2<0)
			cp2+=SIZE;
		res+=keytab[p1.first][cp1];
		res+=keytab[p2.first][cp2];
	}
	else if(p1.second == p2.second) {
		int cp1 = (p1.first-1)%SIZE, cp2 = (p2.first-1)%SIZE;
		if(cp1<0)
			cp1+=SIZE;
		if(cp2<0)
			cp2+=SIZE;
		res+=keytab[cp1][p1.second];
		res+=keytab[cp2][p2.second];
	}
	else {
		res+=keytab[p1.first][p2.second];
		res+=keytab[p2.first][p1.second];
	}
	return res;
}
