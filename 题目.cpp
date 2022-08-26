#include<bits/stdc++.h>
using namespace std;
int main()
{	
	string s,sn,st;
	cin>>s;
	int k,m=-1,t,n;
	stringstream ss;
	for(int i=0;i<s.size();i++){
		k=i;t=0;
while(s[k]>='0'&&s[k]<='9'){
			k++;t++;
		}
		if(t>0){
			sn=s.substr(i,t);
			i=k;
			ss.clear();
ss<<sn;ss>>n;
			if(n>m)m=n;
		}	
	}
	ss.clear();	ss<<m;ss>>st;
	cout<<s.find(st)+1;
	
	return 0;
}
