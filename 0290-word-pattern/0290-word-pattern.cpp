class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                temp =  temp + s[i];
            }else{
                words.push_back(temp);
                temp = "";
            }
        }
        words.push_back(temp);
        for(int i = 0; i < words.size(); i++){
            cout << words[i] << endl;
        }
        if(words.size() != pattern.length()){
            return false;
        }
        unordered_map<char, string> umap;
        for(int i = 0; i < pattern.length(); i++){
            char key = pattern[i];
            auto check = umap.find(key);
            if(check == umap.end()){
                umap[key] = words[i];
            }else{
                if(check -> second != words[i]){
                    return false;
                }
            }
        }
        unordered_map<string, char> umap2;
        for(int i = 0; i < pattern.length(); i++){
            string key = words[i];
            auto check = umap2.find(key);
            if(check == umap2.end()){
                umap2[key] = pattern[i];
            }else{
                if(check -> second != pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};