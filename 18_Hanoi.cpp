
#include<iostream>
using namespace std;

void tower(int n,char source,char auxiliary,char destination){
	if(n==1){
		cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
		return;
	}

	tower(n-1,source,destination,auxiliary);
	cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	tower(n-1,auxiliary,source,destination);
}

int main(){
	int n;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;
	cout<<"Enter number of disks: ";
	cin>>n;

	if(n<=0){
		cout<<"Invalid number of disks";
		return 0;
	}

	tower(n,'A','B','C');

	cout<<"Total moves: "<<((1<<n)-1)<<endl;

	return 0;
}
