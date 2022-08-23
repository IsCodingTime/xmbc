#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
	string s,sn;
	
	cin>>s;
	
	int sum,length=s.size(),k,t,n;
	stringstream ss;
	
	for(int i=0;i<length-1;i++)
	{
		k=i;
		t=0;
		
		while(s[k]>='0'&&s[k]<='9')
		{
			k++;
			t++;
		}
		
		if(t>0)
		{
			sn=s.substr(i,t);
			
			ss.clear();
			
			ss<<sn;
			ss>>n;
			
			if(s[i-1]=='-')
			{
				sum-=n;
			}
			else
			{
				sum+=n;
			}
			
			i=k;
		}
	}
	
	cout<<sum;

	return 0;	
} 
