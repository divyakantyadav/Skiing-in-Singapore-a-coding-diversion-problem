#include <iostream>
using namespace std;
#include <ctime> // time_t
#include <cstdio>

long int input[1000][1000] ,lpath[1000][1000],lsize[1000][1000],r,c;

void calculate_path_size_from_here(int i,int j);

void check_for_next(int i,int j, int k,int l){
    if(k<r && l<c && k>=0 && l>=0  && input[i][j] > input[k][l]){
            if(lpath[k][l] == 0){
                calculate_path_size_from_here(k,l);      
            }
          if(lpath[i][j] < lpath[k][l]+1){
              lpath[i][j] = lpath[k][l]+1;
                lsize[i][j] = (input[i][j]-input[k][l]) + lsize[k][l];    
          } else if(lpath[i][j] == lpath[k][l]+1 && lsize[i][j] < ((input[i][j]-input[k][l]) + lsize[k][l])){
                lsize[i][j] = (input[i][j]-input[k][l]) + lsize[k][l];    
          }
    }
}

void calculate_path_size_from_here(int i,int j){
    if(lpath[i][j] == 0){
        lpath[i][j] = 1;
        lsize[i][j] = 0;
        check_for_next( i, j, i, j+1);
        check_for_next( i, j, i, j-1);
        check_for_next( i, j, i+1, j);
        check_for_next( i, j, i-1, j);
        
    }
}

int main() {
    long int i=0,j=0,k=0;
    cin>>r>>c;
    
    time_t begin,end; // time_t is a datatype to store time values.
    time (&begin); // note time before execution
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>input[i][j];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(lpath[i][j] == 0){
                calculate_path_size_from_here(i,j);    
            }
        }
    }
    
    long int ans_path_len = lpath[0][0], ans_steepness = lsize[0][0];
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
                if(lpath[i][j] > ans_path_len ){
                    ans_path_len=lpath[i][j];
                    ans_steepness = lsize[i][j];
                } else if(lpath[i][j] ==  ans_path_len && ans_steepness < lsize[i][j]){
                    ans_steepness = lsize[i][j];
                }
            
        }
        
    }
    
    time (&end); // note time after execution
    double difference = difftime (end,begin);
    printf ("time taken %.2lf seconds.\n", difference );
    cout<<"length"<<ans_path_len<<" steepness "<<ans_steepness<<"\n";
    
	return 0;
}

