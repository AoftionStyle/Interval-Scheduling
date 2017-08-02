#include <stdio.h>
#include <stdlib.h>

struct GROUP{
	int s;//start
	int f;//finish
};

int IntervalScheduling(int maxweight);
int Solve(struct GROUP B[],int maxweight);

int main(){
	int MAXWORK = 13;
	printf("\nCount of compatible make maxwork : %d",IntervalScheduling(MAXWORK));
	return 0;
}

int IntervalScheduling(int maxwork){
	struct GROUP time[maxwork];
	//set input test
	 time[0].s=1;	 time[0].f=5;
	 time[1].s=3;	 time[1].f=8;
	 time[2].s=3;	 time[2].f=8;
	 time[3].s=3;	 time[3].f=8;
	 time[4].s=3;	 time[4].f=8;
	 time[5].s=7;	 time[5].f=12;
	 time[6].s=10;	 time[6].f=15;
	 time[7].s=13;	 time[7].f=18;
	 time[8].s=17;	 time[8].f=22;
	 time[9].s=17;	 time[9].f=22;
	time[10].s=17;	time[10].f=22;
	time[11].s=17;	time[11].f=22;
	time[12].s=20;	time[12].f=25;
	sort(time,maxwork);
	Print1D(time,maxwork);
	
	return Solve(time,maxwork);
	
}

int outscope(struct GROUP A,struct GROUP B){
	if(B.s>=A.s&&B.s<=A.f){
		//printf("temp %d - %d compare B[i] S: %d\n",A.s,A.f,B.s);
		return 0;
	}
	return 1;
}

int Solve(struct GROUP B[],int maxwork){
	int i,j,sum=0;
	int count = 1;
	struct GROUP temp;
	
	printf("\nInterval Scheduling\n");
	printf("Work%2d time(%d,%d)\n",count,B[0].s,B[0].f);
	
	temp = B[0];
	for(i=0;i<maxwork;i++){
		if(outscope(temp,B[i])==1){
			temp = B[i];
			count++;
			printf("Work%2d time(%d,%d)\n",i+1,B[i].s,B[i].f);
		}
	}
	return count;
}

void sort(struct GROUP A[],int size){
	int i,j,temp;
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if( A[i].f > A[j].f ){
				temp=A[i].s;    A[i].s=A[j].s;    A[j].s=temp;
				temp=A[i].f;    A[i].f=A[j].f;    A[j].f=temp;
			}
		}
	}
}

void Print1D(struct GROUP A[],int item){
	int i;
	printf("All work: ");
	for(i=0;i<item;i++)
		printf("%4d ",i+1);
	printf("\n");
	
	printf("Start   : ");
	for(i=0;i<item;i++)
		printf("%4d ",A[i].s);
	printf("\n");
	
	printf("Finish  : ");
	for(i=0;i<item;i++)
		printf("%4d ",A[i].f);
	printf("\n");
	
}
