int countSetBitsHelper(int n){
    int count  = 0;
    while(n){
        if(n%2 != 0){
            count++;
        }
        n >>=1;
    }

    return count;
}
int countSetBits(int n) {
    // Write your code here
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = (ans + countSetBitsHelper(i))%1000000007 ;
    }

    return ans;
    
}
