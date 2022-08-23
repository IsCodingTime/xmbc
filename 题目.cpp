#include <iostream>

using namespace std;

int num_int(string num_s)
{
	int num_i[num_s.size()]={0};
	
	for(int i=0;i<num_s.size();i++)
	{
		if(num_s[i]>='0'&&num_s[i]<='9')
		{
			num_i[i]=num_s[i]-48;
		}
	}
	
	int num=num_i[0];
	
	for(int i=0;i<num_s.size();i++)
	{
		num+=num_i[i]*(i*10);
	}
	
	return num;
}

int main()
{
	string in;
	
	cin>>in;
	
	int op=0,num_i1=0,num_i2;
	string num_s;
	
	for(int i=0;i<=in.size();i++)
	{
		if(in[i]=='+'||in[i]=='-'||in[i]=='=')
		{
			for(int j=op;j<i-1;j++)
			{
				num_s[j]=in[j];
			}
			
			if(in[i]=='+'||in[i]=='-')
			{
				op=i;				
			}

			num_i2=num_int(num_s);
			
			if(in[i]=='+')
			{
				num_i1+=num_i2;
			}
			else if(in[i]=='-')
			{
				num_i1-=num_i2;
			}
			else if(in[i]=='=')
			{
				if(in[op]=='+')
				{
					num_i1+=num_i2;
				}
				else if(in[op]=='-')
				{
					num_i1-=num_i2;
				}
			}
		}
	}
	
	cout<<num_i1;

	return 0;	
} 
