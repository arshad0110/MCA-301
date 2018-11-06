#include<iostream>
#include<cstdlib>
#include<limits.h>

using namespace std;
 

int **multiplication_score,				// Matrix to store min no multiplication operations
		matrix_no,						// Number of matrices
			*dimension; // 				// dimensions for each matrices

int find_optimal(){


	int n = matrix_no+1;
    for (int i=1; i<n; i++) 
        multiplication_score[i][i] = 0; 		// multipilcation with single matrix
  												// will be 0 operation
  	

  	for (int i = 1; i < matrix_no+1; ++i)		// multipilcation of matrix A1 with A2 will
  	{											// be p*m*n operations where p,m,n are dimension of 
  												// A1 and A2
  		multiplication_score[i][i+1] = dimension[i]*dimension[i+1]*dimension[i+2];	
  	}
   
    

    for (int distance=2; distance<n; distance++)  // to increase number of matrices in multiplication 
    { 
        for (int i=1; i<n-distance+1; i++) 			// i is used for first matrix
        { 
            int j = i+distance-1; 					// j is used for last matrix
            multiplication_score[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 				// k is used for in between matrices of Ai and Aj 
            { 
                int count = multiplication_score[i][k] + multiplication_score[k+1][j] + dimension[i-1]*dimension[k]*dimension[j]; 
                if (count < multiplication_score[i][j]) 
                 {   multiplication_score[i][j] = count;
            }
        } 
        } 
    } 
  
    return multiplication_score[1][n-1]; 				// returning the optimal solution
}														// to multiply given number of matrices

void initial(){

	cout<<"\nEnter number of matrices : ";
	cin>>matrix_no;

	dimension = new int[matrix_no+1];			// pointer memory allocation

	multiplication_score = new int*[matrix_no+1];			//		Double pointer memory 
	for (int i = 0; i < matrix_no+1; ++i)					//		allocation
	{														//
		multiplication_score[i] = new int[matrix_no+1];
	}

	cout<<"\nEnter Matrix dimensions : ";

	for (int i = 0; i < matrix_no+1; ++i){
		cin>>dimension[i];
	}
	for (int i = 0; i < matrix_no; ++i){	
		
		for (int j = 0; j < matrix_no; ++j)
		{
			multiplication_score[i][j] = 0;
		}
	}
}


int main(){

	initial();			//intializing all global variables

	int result = find_optimal();		
	

	cout<<"\nMinimum No. of operations required are "<<result<<"\n";
	
	for (int i = 0; i < matrix_no+1; ++i){	
		for (int j = 0; j < matrix_no+1; ++j)
		{
			cout<<multiplication_score[i][j]<<"  ";
		}
		cout<<"\n";
	}


	return 0;
}


/*
 
 Time Complexity:-
 
 In this process, we are computing values in the array matrix but only half of them.
 Since we are performing chain multiplications of these matrices in the order of 2, 3 and so on,
 
 Therefore, we are generating n(n-1)/2 elements. For each element, we are calculating all values and finding the minimum
 out of them, which would be done at most n times.
 
 Hence, n(n-1)/2 * n --> which gives us the time complexity of O(n^3).
 
 
*/

