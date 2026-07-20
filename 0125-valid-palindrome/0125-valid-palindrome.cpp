class Solution {
public:
    bool isalphaNum(char ch ){
                if((ch>='0' && ch <='9') || (tolower(ch) >= 'a' && tolower(ch)<='z')){
                    return true ;
                }
                return false;
    }
    bool isPalindrome(string str) {
            int start = 0 ;
            int end = str.length()-1;
            while(start<end){
               if(!isalphaNum(str[start])){
                    start++ ; continue;
               }
               if(!isalphaNum(str[end])){
                    end-- ; continue;
               }

               if(tolower(str[start])!= tolower(str[end])) {
                return false ;
               }
               start++ ; end-- ;
            } return true ;
    }
};