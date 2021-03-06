/*
	Program : C program to implement a DFA for a language having odd number of 0’s and even number of 1’s.
	Author : Rinchin Dorjee
	Date : 12/08/20

	Algorithm :

    Step 1: Create a 2D table T.  
	    Step 1.1: Declare state as one dimension.  
	    Step 1.2: Declare Input symbol as another one dimension. 
    Step 2: For every transition Si →Sk define T[i,a] = k.  
    Step 3: Declare one more one dimensional char array for input string named as input.  
    Step 4: Specify the initial state and final states.  
    Step 5: Take transition functions from the user
	    Step 5.1 : for eg, the following are the transition functions for the given problem :
		                δ(q0,0) = 3                                                                                                                                     
                        δ(q0,1) = 1                                                                                                                                     
                        δ(q1,0) = 2                                                                                                                                     
                        δ(q1,1) = 0                                                                                                                                     
                        δ(q2,0) = 1                                                                                                                                     
                        δ(q2,1) = 3                                                                                                                                     
                        δ(q3,0) = 0                                                                                                                                     
                        δ(q3,1) = 2   
        Step 5.2 : Print the transition table
    Step 6: Use determine() recursively to reach the last state.
    Step 7: if(the last state is same as the final state)
	  Step 7.1: , then the input string is accepted
	     else call determine()
*/

//Source code : 

#include<stdio.h>
#include<string.h>

int count = 0,ch,len;
int flag = 0,T[20][20],final[20],n_final;
int determine(int state, char *input);
int main()
{
	int n, n_sym, start, symbols[20];
	int i, j, k;
	char input[10];
	printf("Enter the number of states : ");
	scanf("%d", &n);
	printf("Enter the number of symbols : ");
	scanf("%d", &n_sym);
	
	for(i=0; i<n_sym; i++)
	{
		printf("Enter symbol %d : ", i+1);
		scanf("%d", &symbols[i]);
	}
	
	printf("Enter the start state : ");
	scanf("%d",&start);
	printf("Enter the number of final states : ");
	scanf("%d", &n_final);
	
	printf("Enter the final states : ");
	
	for(i=0; i<n_final; i++)
	{
		int temp;
		scanf("%d", &temp);
        final[i] = temp;
	}
	
	//Transition table 

	int count_1 = 0;
	printf("Enter the transition functions : \n");
	for(i=start; count_1<n; i++){
	    for(j=0; j<n_sym; j++){
	        int temp;
	        printf("d(q%d,%d) = ",i,j);
	        scanf("%d",&temp);
	        T[i][symbols[j]] = temp;
	    }
	   if(i==n-1)
	       i = -1;
	   count_1++;
	}

   	printf("\nTransition table : \nd\t0\t1\n-------------------\n");
   	int count_2 = 0;
	for(i=start; count_2<n; i++){
	    printf("q%d\t",i);
	    for(j=0; j<n_sym; j++){
	        printf("%d\t",T[i][symbols[j]]);     
	    }
	    printf("\n");
	   if(i==n-1)
	       i = -1;
	   count_2++;
	}
	
	printf("\nEnter the string : ");
	scanf("%s",&input);
	len = strlen(input);
	printf("\nTransition sequence : \n\n");
	
	if(determine(start,input)==1)
	    printf("\nAccepted!");
	 else
	    printf("\nRejected!");
    
    return 0;
}

int determine(int state, char *input){
    ch++;
    int i = 0;
    int digit = (input[count] - '0');
    int new_state = T[state][digit];
    printf("q%d--%d-->q%d\n",state,digit,new_state);
    for(i=0;i<n_final;i++){
        if(new_state==final[i] && count==len-1)
            flag = 1;
    }
    
    if(flag==0){
         if(ch!=len){
              count++;
              determine(new_state,input);
         }
    }
    return flag;
}

/*

Expected I/O :

Enter the number of states : 4                                                                                                                  
Enter the number of symbols : 2                                                                                                                 
Enter symbol 1 : 0                                                                                                                              
Enter symbol 2 : 1                                                                                                                              
Enter the start state : 0                                                                                                                       
Enter the number of final states : 1                                                                                                            
Enter the final states : 3                                                                                                                      
Enter the transition functions :                                                                                                                

δ(q0,0) = 3                                                                                                                                     
δ(q0,1) = 1                                                                                                                                     
δ(q1,0) = 2                                                                                                                                     
δ(q1,1) = 0                                                                                                                                     
δ(q2,0) = 1                                                                                                                                     
δ(q2,1) = 3                                                                                                                                     
δ(q3,0) = 0                                                                                                                                     
δ(q3,1) = 2                                                                                                                                     
                                                                                                                                                
Transition table :                                                                                                                              

δ       0       1                                                                                                                               
-------------------                                                                                                                             
q0      q3      q1                                                                                                                              
q1      q2      q0                                                                                                                              
q2      q1      q3                                                                                                                              
q3      q0      q2                                                                                                                              
                                                                                                                                                
Enter the string : 01010      

Transition sequence :                                                                                                                           
                                                                                                                                                
q0--0-->q3                                                                                                                                      
q3--1-->q2                                                                                                                                      
q2--0-->q1                                                                                                                                      
q1--1-->q0                                                                                                                                      
q0--0-->q3                                                                                                                                      
                                                                                                                                                
Accepted!       
*/