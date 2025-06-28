class Solution {
public:
    int minMoves(int target, int md) {
        int moves = 0;
        if(target == 1) return 0;

        while(target>1){
            if(md){
                if(target%2==0){
                    target = target/2;
                    md--;
                }
                else target--;
            }
            else break;
            moves++;
        }
        return moves+target-1;
    }
};