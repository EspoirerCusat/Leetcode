class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> s;
        for(auto& itr : bank){
            s.insert(itr);
        }
        if(s.find(end) == s.end()){
            return -1;
        }
        queue<string> q;
        set<string> vis;
        q.push(start);
        vis.insert(start);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string x = q.front();
                if(x == end){
                    return ans;
                }
                q.pop();
                for(int i=0; i<x.size(); i++){
                    char t = x[i];
                    for(char c : {'A','C','G','T'}){
                        x[i] = c;
                        if(s.find(x) != s.end() && vis.find(x) == vis.end()){
                            q.push(x);
                            vis.insert(x);
                        }
                    }
                    x[i] = t;
                }
            }
            ans++;
        }
        return -1;
    }
};




































