class Solution {
public:
    int reverse(int x) {
        int n=0;
        while(x){
            if(n<=INT_MAX/10&&n>=INT_MIN/10){
                n=n*10+x%10;
                x/=10;
            }
            else return 0;
        }
        return n;
    }
};