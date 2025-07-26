class Solution {
public:

    double myPow(double x, int n) {
        long long p = n;
        if(p < 0){
            x = 1 / x;
            p = -p;
        }
        return power(x, p);
    }

    double power(double x, long long n) {
        if (n == 0) return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};