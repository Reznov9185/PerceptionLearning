#include<iostream>

using namespace std;

int t;
double w1=0.5,w2=0.5,b=0;
int fnc;

	class data
{
public:
	int in1;
	int in2;
	int out;
};

data d[100];

int check_fnc()
{
	int flag=0;
	for(int i=1;i<=t;i++)
	{
		if(d[i].out==0 || d[i].out==1)
			flag=1;
		else if(d[i].out==1 || d[i].out==-1)
			flag=2;
	}
	if(flag==1)
		return 0;
	else 
		return 1;
}

void update(int i, int a)
{
	double e;
	e=d[i].out-a;
	w1=w1+e*d[i].in1;
	w2=w2+e*d[i].in2;
	b=b+e;
}

void set_ukw()
{
	int a,tmp;
	int count=0;
	for(int i=1;i<=t;i++)
	{
		if(count==t)
		{
			break;
		}
		if(fnc==0)
		{
			tmp=(w1*d[i].in1)+(w2*d[i].in2)+b;
			if(tmp>=0)
				a=1;
			else if(tmp<0)
				a=0;
		}
		else if(fnc==1)
		{
			tmp=(w1*d[i].in1)+(w2*d[i].in2)+b;
			if(tmp>=0)
				a=1;
			else if(tmp<0)
				a=-1;
		}
		if(a==d[i].out)
			count++;
		else
		{
			count=0;
			update(i,a);
		}
		if(i==t)
			i=0;
	}
}

int main()
{
	int x,y,n,r;
	cout<<"Enter no. of training sets: ";
	cin>>t;
	cout<<"Enter the input sets: "<<endl;
	for(int i=1;i<=t;i++)
	{
		cin>>d[i].in1>>d[i].in2>>d[i].out;
	}
	fnc=check_fnc();
	set_ukw();
	//cout<<fnc;
	cout<<w1<<"\t"<<w2<<"\t"<<b<<endl;
	for(int i=1;i<=t;i++)
	{
		cout<<"Enter your values: ";
		cin>>x>>y;
		n=w1*x+w2*y+b;
		if(n>=0)
			r=1;
		else
			r=0;
		cout<<"Result: "<<r<<endl;
	}
	
}