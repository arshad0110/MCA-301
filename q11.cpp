#include <iostream>


int count_Antisquad(int N, int K)
{
	int count = 0;
	//when the total no. of people is less than minimum count required for each group
	if(N<K && N!=0){
		count = 0;
	}
	when there are no people, only one partiton is possible that is empty set
	else if(N==0){
		count = 1;
	}
	else{
	/*	
	 returns partition count containing k and returns partition count not containing k
	 there combination gives total number of possible partitions */
	
	    count = count_Antisquad(N-K,K) + count_Antisquad(N,K+1);
	}
	return count;
}
int main()
{
    
    int N;
    int K;
    int num=0;
	    std::cout<<"\nEnter total no of people: ";
        std::cin >>N;
        std::cout<<"\nEnter minimum no of people required in each group: ";
        std::cin >>K;
        num=count_Antisquad(N,K);
        std::cout<<"\n The numner of ways in which we can form the groups is: ";
        std::cout<<num;
        std::cout<<"\nDo you want to continue: ";
        std::cin >>ch;
   
    return 0;
    /* 
	Time Complexity
     Base Case takes constannt of 0(1) time
     T(n,k)=T(n-k,k)+T(n,k+1)
     which on solving is atmost n^2
     =>time complexity=O(n^2)
     */
     
}