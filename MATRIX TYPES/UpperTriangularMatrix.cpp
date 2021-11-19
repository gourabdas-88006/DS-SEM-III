#include <iostream>
using namespace std;

class upper_triangular_matrix
{
	int* D;
	int len;
	public:
		upper_triangular_matrix(int n)
		{
			len=n;
			if(len>=0)
				D = new int[len*((len+1)/2)];
			else
				D = 0;
		}
		~upper_triangular_matrix()
		{
			delete [] D;
		}
		void store(int r,int c,int data)
		{
			if(r>=0 && r<len && c>=0 && c<len && r<=c)
			{
				int ad=((c * (c - 1)) / 2) + r - 1;
				D[ad] = data;
			}
		}
		int value(int r,int c)
		{
			r=r-1;
			c=c-1;
			if(r>=0 && r<len && c>=0 && c<len){
				if(r<=c){
					int ad=((c * (c - 1)) / 2) + r - 1;
					return D[ad];
				}
				else
					return 0;
			}
			else{
				cout<<"Wrong Input";
			}
		}
		void show()
		{
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<len;j++)
				{
					if(i<=j)
					{
						int ad=((j * (j - 1)) / 2) + i - 1;
						cout<<D[ad]<<" ";
						
					}else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	int temp;
	upper_triangular_matrix utm = upper_triangular_matrix(5);
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			temp=i+j+2;
			utm.store(i,j,temp);
		}
	}
	utm.show();
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<endl<<"Printing element at index["<<i+1<<","<<j+1<<"] : "<<utm.value(i+1,j+1);
		}
	}
	
	
}
