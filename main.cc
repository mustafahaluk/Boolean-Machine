#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
//Finds the connections and does the operations
int met(int f,int a [][50], int p [], int oo [],int kkk,int lll,int mmm){
	int i1= -1; //first connection to the node 
	int i2= -1; //second connection to the node 
	int s = -1; //Takes number of the node
	for (int i=0; i<kkk+lll; i++){
		for (int j=0; j<50; j++){
			if(a[i][j]==f){ s=i; i1=met(i,a,p,oo,kkk,lll,mmm); i= i+12;} } }
	for (int i=0; i<kkk+lll; i++){
		for (int j=0; j<50; j++){
			if(a[i][j]==f & i!= s){i2=met(i,a,p,oo,kkk,lll,mmm);i= i+12;} } }
	if(i1==-1 & i2==-1) {return p[f];}
	else if((i1==0 & i2==-1)&(oo[f]==1 || oo[f]==0)){return p[s];}
	else if((i1==1 & i2==-1)&(oo[f]==1 || oo[f]==0)){return p[s];}
	else if((i1==0 & i2==-1) & oo[f]==102){p[f]=1;return 1;}
	else if((i1==1 & i2==-1) & oo[f]==102) {p[f]=0;return 0;}
	else if((i1!=-1 & i2!=-1) & oo[f]==101){
		if(i1==1 & i2==1) {	p[f]=1;	return 1;}
		else {p[f]=0;return 0;}		}
	else if((i1!=-1 & i2!=-1) & oo[f]==103){
		if(i1==1 || i2==1) {	p[f]=1;	return 1;}
		else {	p[f]=0;	return 0;}	}
	else if((i1!=-1 & i2!=-1) & oo[f]==104){
		if(i1!=i2) {p[f]=1; return 1;}
		else { p[f]=0; return 0;}	}
}

int main(int argc, char *argv[]){
	ifstream graph(argv[1]);
	
	char line[1000];
	graph.getline(line,1000);
	char* x=strtok(line," ");
	
	//Taking the input
	int a = atoi(x);
	x = strtok(NULL," ");
	int b = atoi(x);
	x = strtok(NULL," ");
	int c = atoi(x);
	int* z= new int[a+b+c];
	int girdi[a+b][50];
	for (int i=0; i<a+b; i++){
		for (int j=0; j<50; j++){
			girdi[i][j]= -1;
			}	
		}
	int n = a+b+c;
	graph.getline(line,1000);
	x=strtok(line," ");
	z[0] = atoi(x);
	for(int i = 1; i<a; i++){
		x = strtok(NULL," ");
		z[i] = atoi(x);
		
	}
	for(int i = 0; i<b; i++){
		x = strtok(NULL," ");
		if(*x=='A'){
			z[a+i]==101;
			}
		else if(*x=='N'){
			z[a+i]==102;
			}
		else if(*x=='R'){
			z[a+i]==103;
			}
		else if(*x=='X'){
			z[a+i]==104;
			}
			
	}
	for(int i = 0; i<c; i++){
		
		z[i+a+b] = 0;
	}
	while(graph.good()){
		graph.getline(line,1000);
		x = strtok(line," ");
		int u,y;
		u = atoi(x);
		x = strtok(NULL," ");
		for(int mu= 0; x != NULL; mu++){//I could not complete this part
			y = atoi(x);
			girdi[u][mu]=y;
			x = strtok(NULL," ");
		}
	}	
	//And = 101, Not = 102, Or = 103, Xor = 104;
	
	int o[]={1,0,1,1,0,101,103,102,101,104,103,104,102,0,0,0};//Shows the operations
		for (int i=0; i<a+b; i++){
		for (int j=0; j<50; j++){
			cout<<girdi[i][j];}
			cout<<endl;}
		for(int h=0; h<a+b+c; h++){//Tries all nodes
			z[h]=met(h,girdi,z,o,a,b,c);
		}
		
	
		cout<<endl;
		for (int q=0; q<16; q++){
		cout<<z[q];
			cout<<" ";
		}
		
  return 0;
}


