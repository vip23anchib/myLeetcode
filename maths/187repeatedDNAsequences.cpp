class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> mp;
        vector<string> ans;

        for(int i = 0; i + 10 <= s.length(); i++) {
            
            string sub = s.substr(i, 10);

            if(mp[sub] == 1) {
                ans.push_back(sub);
            }

            mp[sub]++;
        }

        return ans;
    }
};
