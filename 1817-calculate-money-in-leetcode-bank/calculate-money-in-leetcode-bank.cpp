class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n / 7;
        int remainingDays = n % 7;

        int total = fullWeeks * 28 + (7 * fullWeeks * (fullWeeks - 1)) / 2;

        int start = fullWeeks + 1;
        total += (remainingDays * (2 * start + remainingDays - 1)) / 2;

        return total;
    }
};