class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(string str:strs){
            string tmp = "";
            for(char ch:str){
                if(tmp==""){
                    tmp = to_string(ch);
                    continue;
                }
                tmp = tmp + "-" + to_string(ch);
            }
            if(encoded_string.empty()){
                encoded_string = tmp + "+";
                continue;
            }
            encoded_string = encoded_string + tmp + "+";
        }
        cout<<encoded_string<<endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        // if(s==""){
        //     return {""};
        // }
        vector<string> strs = {};
        string str = "";
        string tmp = "";
        for(char c: s){
            if(c=='-'){
                str = str + (char)stoi(tmp);
                tmp = "";
            }else if(c=='+'){
                if(tmp.empty()){
                    strs.push_back("");
                    continue;
                }
                str = str + (char)stoi(tmp);
                strs.push_back(str);
                tmp = "";
                str = "";
            }else{
                tmp += c;
            }
        }
        // str = str + (char)stoi(tmp);
        // strs.push_back(str);
        return strs;
    }
};
