#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

bool checktime(float start,float cooldowntime,bool &keychange,bool &firsttime){
	cout <<(clock() - start )/(double)CLOCKS_PER_SEC<<endl;
	if(firsttime){
		keychange=false;
		firsttime = false;
		return true;
	}
	if((clock()-start)/(double)CLOCKS_PER_SEC>cooldowntime) {
		keychange=true;
		return true;
	}
	else {
		keychange=false;
		return false;	
	}
}

int main(){
	char x;
	bool keychange=true,firsttime=true;
	int  start;
	
	srand(time(0));
	
	while(true){
		x=_getch();
		if(x=='w'){
			if(keychange){
				start = clock();
			}
			if(checktime(start,5,keychange,firsttime)){
				cout << "Attack :";
			}else cout << "Cooldowning : ";
		}	
	}
	
	
	return 0;
}
