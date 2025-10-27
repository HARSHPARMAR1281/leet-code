class Solution {
public:    
    int f=1,s=2;
    int climbStairs(int n) {
    //     if(n==1) return n;
    //     int arr[n+1];
    //     arr[1]=1;
    //     arr[2] = 2;
    //     for(int i =3;i<=n;i++){
    //         arr[i]= arr[i-1]+arr[i-2];
    //     }
    //    return arr[n];
    if(n==1||n==2) return n;
    int sum = 0;
    for(int i =2;i<n;i++){
        sum = f+s;
        f=s;
        s=sum;
    }
    return sum;

    }
};