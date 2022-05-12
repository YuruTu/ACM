static const int modV = 1e9+7;
class Solution {
public:
    int countTexts(string pressedKeys) {
        //// 统计字符长度
        int nLen = pressedKeys.length();
        vector<int> dp(nLen+5);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;(i<=1)&&(i<nLen);++i){
            if(pressedKeys[i]==pressedKeys[i-1]){
                dp[i+1]=dp[i]+dp[i-1];
            }else{
                dp[i+1]=dp[i];
            }
            dp[i+1]%=modV;
        }
        for(int i=2;(i<=2)&&(i<nLen);++i){
            if((pressedKeys[i]==pressedKeys[i-1])&&(pressedKeys[i-1]!=pressedKeys[i-2])){
                dp[i+1]=dp[i]+dp[i-1];
            }else if((pressedKeys[i]==pressedKeys[i-1])&&(pressedKeys[i-1]==pressedKeys[i-2])){
                dp[i+1] =dp[i]+dp[i-1]+dp[i-2];
            }else{
                dp[i+1]=dp[i];
            }
            dp[i+1]%=modV;
        }

        for(int i=3;i<nLen;++i){
            dp[i+1]=dp[i];
            if((pressedKeys[i]==pressedKeys[i-1])){
                dp[i+1]+=dp[i-1];
                dp[i+1]%=modV;
            }
            if((pressedKeys[i]==pressedKeys[i-1])&&(pressedKeys[i-1]==pressedKeys[i-2])){
                dp[i+1]+=dp[i-2];
                dp[i+1]%=modV;
            }
            if((pressedKeys[i]==pressedKeys[i-1])&&(pressedKeys[i-1]==pressedKeys[i-2])&&
            (pressedKeys[i-2]==pressedKeys[i-3])&&((pressedKeys[i]=='7')||('9'==pressedKeys[i]))){
                dp[i+1]+=dp[i-3];
                dp[i+1]%=modV;
            }

        }

        return dp[nLen];
    }
};