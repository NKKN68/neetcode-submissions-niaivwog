class Solution {
public:
    void reverseString(vector<char>& s) {
        char* ptr1 = &s[s.size() - 1];
        char* ptr2 = &s[0];
        while(ptr2 < ptr1){
            char temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
            ptr1 = ptr1 - 1;
            ptr2 = ptr2 + 1;
        }
    }
};