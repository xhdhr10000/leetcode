// Author: xhdhr10000
// Date: 2020-07-23

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int64_t x = 1, y = n, pia;
        while (pia = guess((x + y) / 2)) {
            pia < 0 ? y = (x + y) / 2 - 1 : x = (x + y) / 2 + 1;
        }
        return (x + y) / 2;
    }
};
