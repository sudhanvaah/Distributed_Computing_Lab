#include <bits/stdc++.h>
using namespace std;
struct process
{
	int processID;
	bool crashed;
};
process processes[100];
int totalprocess;
int cordinator,initiator;
void init();
void ring(int);//actual logic function for this code
int main()
{
	init();
	while(true)
	{
		cout<<"\n1.Crash process \n 2. Recover Process\n";
		int choice;
		cout<<"Enter your choice?\n";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Which process u want to crash?";
			int p;
			cin>>p;
			processes[p].crashed=true;
			if(p==initiator)
			{
				int newinitiator=0;
				for(newinitiator=0;newinitiator<totalprocess;newinitiator++)
				{
					if(processes[newinitiator].crashed==false)
					{
						initiator=newinitiator;
						break;
					}
				}			
			}
			ring(initiator);
		}
		if(choice==2)
		{
			cout<<"Whoch process u want to recover:\n";
			int p;
			cin>>p;
			processes[p].crashed=false;
			ring(initiator);
		}
	}
}
void init()
{
	cout<<"Enter the no of process in the system\n";
	cin>>totalprocess;
	for(int i=0;i<totalprocess;++i)
	{
		processes[i].processID=i;
		cout<<"Enter the process id of the process- "<<i<<": "<<i<<endl;
		processes[i].crashed=false;
	}
	cout<<"Enter the initiator process no:\n";
	cin>>initiator;
	ring(initiator);
}

void ring(int processno)
{
	int uncrashed[100],count=0;
	for(int i=0;i<totalprocess;++i)
	{
		if(processes[i].crashed==false)
		{
			uncrashed[count++]=i;
		}
	}
	if(count==1)
	{
		cout<<"only process active is "<<uncrashed[0]<<" so coodinator is "<<uncrashed[0]<<endl;
		cordinator=uncrashed[0];
	}
	else if(count==0)
	{
		cout<<"No process is active\n";
		cordinator=-1;
	}
	else
	{
		int currprocessno=0;
		while(uncrashed[currprocessno]!=processno)
			currprocessno++;
		//this is getting the currprocessno same as initiator
		do//starting the ring algo from initiator i.e processno
		{
			cout<<"\nMessage sent from "<<uncrashed[currprocessno]<< "to "<<uncrashed[(currprocessno+1)%count];
			currprocessno=(currprocessno+1)%count;
		}while(uncrashed[currprocessno]!=processno);
		cordinator=uncrashed[count-1];
		cout<<"\n New cordinator is : "<<cordinator<<endl;
	}

}
