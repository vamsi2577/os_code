#include<stdio.h>


struct process_struct{
	int process_id;
	int ari_time;
	int burst_time;
	int comp_time;
	int rem_time;
}y[100], k[100], p[100];

int n, vc=0, ac=0, uc=0;
int quanta;

void roundRobin(){
	int time= p[0].ari_time, tick=0, kk=0, i, lc;
	while(time!=120 && kk!=uc){
		for(i=0; i<=tick; i++){
			if(p[i].rem_time > quanta){
				time += quanta;
				p[i].rem_time -= quanta;
			}
			else if(p[i].rem_time <=quanta && p[i].rem_time !=0){
				time += p[i].rem_time;
				p[i].rem_time =0;
				p[i].comp_time = time;
				kk++;
			}
			else;
		}
		int start = tick+1;
		for(lc= start; lc<uc; lc++){
			if(p[lc].ari_time <= time){
				tick++;
			}
		}
	}	
}

void comb(){
	int iac=0, ivc= 0, min, flag;
	if( vc!=0  && ac!=0){
		while(iac<ac && ivc<vc){
			if(y[ivc].ari_time == k[iac].ari_time){
				p[uc] = y[ivc];
				uc++;
				ivc++;
				p[uc]= k[iac];
				uc++;
				iac++;
			}
			else if(y[ivc].ari_time < k[iac].ari_time){
				p[uc]= y[ivc];
				uc++;
				ivc++;
			}
			else if(y[ivc].ari_time > k[iac].ari_time){
				p[uc]= k[iac];
				uc++;
				iac++;
			}
			else;
		}
		if(uc != (vc+ac)){
			if(vc!=ivc){
				while(ivc!=vc){
					p[uc]= y[ivc];
					uc++;
					ivc++;
				}
			}
			else if(ac!=iac){
				while(iac!=ac){
					p[uc]= k[iac];
					uc++;
					iac++;
				}
			}
		}
	}
	else if(vc==0){
		while(iac!=ac){
			p[uc]= k[iac];
			uc++;
			iac++;
		}
	}
	else if(ac==0){
		while(ivc!=vc){
			p[uc]= y[ivc];
			uc++;
			ivc++;
		}
	}
	else {
		printf("\n No valid process available.\n");
	}
}

void summary(){
	int i=0, total=0, sum=0; 
	double avg;
	printf("\nSummary for the Execution\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<uc; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		p[i].process_id, (p[i].ari_time+1000), p[i].burst_time, (p[i].comp_time+1000), (p[i].comp_time-p[i].ari_time), ((p[i].comp_time-p[i].ari_time)- p[i].burst_time));
		total= p[i].comp_time;
		sum+= (p[i].comp_time-p[i].ari_time);
	}
	avg = sum/uc;
	printf("\n\ntime Spent for all queries: %d", total);
	printf("\nAverage query time: %lf", avg);
	printf("\nProcess Execution Complete");
}

void input(){
	int map,  i, t;
	printf("Enter total number of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries\n"); }
	else{
		printf("\nEnter Quanta for each Process: "); scanf("%d", &quanta);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\nquery Type (faculty)or(student)  "); scanf("%d", &map);
			if(map==1){
				printf("Query Id: "); scanf("%d", &y[vc].process_id);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nEnter correct time");
					input();
				}
				else{y[vc].ari_time= t-1000;}
				printf("Burst Time: "); scanf("%d", &y[vc].burst_time);y[vc].rem_time= y[vc].burst_time; 
				vc++;
			} else{
				printf("Query Id: "); scanf("%d", &k[ac].process_id);
				printf("Arrival Time: "); scanf("%d", &t); 
				if(t<1000 || t>1200){
					printf("\nEnter Correct time\n");
					input();
				}
				else {k[ac].ari_time= t-1000; }
				printf("Burst Time: "); scanf("%d", &k[ac].burst_time);	 k[ac].rem_time= k[ac].burst_time;
				ac++;
			}
		}
	}
}
 main(){
 	
 	printf("\n\n***Please follow these instruction for proper ececution of the program"
			"\n***>Enter time in 2400 hours format. example for 10:30 AM enter 1030"
			"\n***>arival time must be between 10am to 12am i.e 1000 to 1200 as per the problem"
			"\n***>Enter Query arrival times in ascending order, i.e., in real time arrival manner\n"
			"\nAll Time units are in minutes.\n"
			);
	input();
	comb();
	roundRobin();
	summary();
}

