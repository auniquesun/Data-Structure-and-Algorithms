class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)        
            return false;
        else if(x == 0)
            return true;
        else{
            stack<int> bits;    //存放x每一位从左到右的结果
            vector<int> inverse_x;  

            do{
                int bit = x%10;
                bits.push(bit);
                inverse_x.push_back(bit);

                x /= 10;
            }while(x!=0);

            for(int i=0; i<inverse_x.size() && !bits.empty(); i++){
                int bit = bits.top();
                bits.pop();

                if(bit != inverse_x[i])
                    return false;
            }

            return true;
        }
    }
};