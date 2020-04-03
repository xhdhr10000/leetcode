// Author: xhdhr10000
// Date: 2020-04-03

class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> notPrime(n);
        for (int i=2; i<n; i++) {
            if (!notPrime[i]) primes.push_back(i);
            for (int j=0; j<primes.size(); j++) {
                if (i * primes[j] >= n) break;
                notPrime[i*primes[j]] = true;
            }
        }
        return primes.size();
    }
};
