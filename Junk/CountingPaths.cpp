int solve_util(vector<vector<int> >arr,int n,int m,long long int k,int i,int j,long long int x){
    if(i==n-1 && j==m-1 && x==arr[i][j]%k)return 1;
    int temp=0;
    long long int rem = (x-(arr[i][j]%k)+k)%k;
    if(is_valid(i+1,j,n,m)){
        temp+=solve_util(arr,n,m,k,i+1,j,rem);
    }
    if(is_valid(i,j+1,n,m)){
        temp+=solve_util(arr,n,m,k,i,j+1,rem);
    }
    return temp;
}

int solve(vector<vector<int> >arr,int n,int m,long long int k){
    return solve_util(arr,n,m,k,0,0,0);
}