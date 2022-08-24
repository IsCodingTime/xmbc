#include <iostream>

using namespace std;

int main()
{
	int M,T,U,F,D;
	
	cin>>M>>T>>U>>F>>D;
	
	char rode;
	int time=0,sum=0;
	
	for(int i=1;i<=T;i++)
	{
		cin>>rode;
		
		if(time<M)
		{
			if(rode=='u'&&time+U+D<=M||rode=='d'&&time+D+U<=M)
			{ 
				time+=U+D;
				sum++;
			}
			else if(rode=='f'&&time+F*2<=M)
			{
				time+=F*2;
				sum++;
			}
		}
	}
	
	cout<<sum;

	return 0;	
} 
