class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        //white
        if((source[0]%2==0 && source[1]%2==0)||(source[0]%2!=0 && source[1]%2!=0)){
            if((target[0]%2==0 && target[1]%2==0)||(target[0]%2!=0 && target[1]%2!=0)){
                if(source[0]+source[1] == target[0]+target[1]) return 1;
                else{
                    if(source[0] == source[1] && target[0] == target[1]) return 1;
                    int diff = abs(source[0] - target[0]);
                    if(abs(source[1] - target[1]) == diff) return 1;
                    return 2;
                }
            }
        }else{//black
             if((target[0]%2==0 && target[1]%2!=0)||(target[0]%2!=0 && target[1]%2==0)){
                 if(source[0]+source[1] == target[0]+target[1]) return 1;
                 else{
                    int diff = abs(source[0] - target[0]);
                    if(abs(source[1] - target[1]) == diff) return 1;
                    return 2;
                 }
             }
        }
        return -1;
    }
};
