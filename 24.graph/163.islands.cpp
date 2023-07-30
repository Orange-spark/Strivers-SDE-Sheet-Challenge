void help(int i,int j,int **&arr,int n,int m){

   if(i<0 || i>=n || j<0 || j>=m)return;

   if(arr[i][j]==1)arr[i][j]=0;

   else{

      return;

   }

   if(i-1>=0)help(i-1,j,arr,n,m);

   if(j-1>=0)help(i,j-1,arr,n,m);

   if(i+1<n)help(i+1,j,arr,n,m);

   if(j+1<m)help(i,j+1,arr,n,m);

   if(i-1>=0 && j-1>=0)help(i-1,j-1,arr,n,m);

   if(i-1>=0 && j+1<m)help(i-1,j+1,arr,n,m);

   if(i+1<n && j-1>=0)help(i+1,j-1,arr,n,m);

   if(i+1<n && j+1<m)help(i+1,j+1,arr,n,m);

}

int getTotalIslands(int** arr, int n, int m)

{

   int cnt=0;

   for(int i=0;i<n;i++){

      for(int j=0;j<m;j++){

         if(arr[i][j]==1){

            cnt++;

            help(i,j,arr,n,m);

         }

      }

   }

   return cnt;

}

 
