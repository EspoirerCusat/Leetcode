class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        int ans = 0;
        int x = 0;
        for(auto& itr : mp){
            cout<<itr.first<<" "<<itr.second<<"\n";
            if(itr.first[0] != itr.first[1]){
                string t = itr.first;
                reverse(t.begin(),t.end());
                if(mp.count(t) > 0){
                    ans += min(itr.second,mp[t]);
                }
            }else{
                if(itr.second&1) x = 1;
                ans += (itr.second&1 > 0 ? itr.second-1 : itr.second);
            }
        }
        return 2*(ans+x);
    }
};