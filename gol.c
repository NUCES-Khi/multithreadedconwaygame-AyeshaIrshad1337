#include <stdio.h>
#include <pthread.h>
#include <omp.h>

void print_grid(int n,int  grid[n][n]){
 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
int count_neighbors(int n, int m,int grid[4][4]){
int neighbors=0;
int col =m +1;
int row =n+1;
for(int c = m-1 ; m < col;m++){ 
	for(int r= n -1;n<col;n++){
	if (r >= 0 && r < 4 && c >= 0 && c < n && !(r == n && c == m) && grid[r][c] == 1) {
                    neighbors++;
                }
  }
 }
 return neighbors;
}
void update_grid(int n,int m,int grid[4][4],int neighbors,int newGrid[4][4]){
 // Update cell state based on neighbors
        if (grid[n][m] == 1) {
            if (neighbors == 2 || neighbors == 3) {
                newGrid[n][m] = 1;
            } else {
		newGrid[n][m] = 0;
            }
        } else {
            if (neighbors == 3) {
                newGrid[n][m] = 1;
            } else {
                newGrid[n][m] = 0;
            }
        }
    }
}
void grid_work(int grid[4][4], int newGrid[4][4],int row,int col){
int x
}
int main(){
int newGrid[4][4];
int grid[4][4];
for(int i=0;i<4;i++){
for(int j = 0 ; j < 4 ;j++){
newGrid[i][j]=0;
}
}
printf("Enter only 0 for no life and 1 for life\n");
for(int i=0;i<4;i++){
for(int j = 0 ; j < 4 ;j++){
scanf("%d",&grid[i][j]);
}
}
int gen=0;
printf("Enter number of generation: ");
scanf("%d",&gen);
}
