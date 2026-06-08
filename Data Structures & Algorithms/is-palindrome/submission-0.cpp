class Solution {
public:
    bool isPalindrome(string s) {
        int a = 0; 
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i]) > 0){
                s[a] = s[i];
                s[a] = tolower(s[a]);
                a++;
            }
        }
        s.resize(a);
        char* ptr1 = &s[0];
        char* ptr2 = &s[s.size() - 1];
        while(ptr1 < ptr2){
            if(*ptr1 != *ptr2){
                return false;
            }
            ptr1++;
            ptr2--;
        }
        return true;
    }
};
