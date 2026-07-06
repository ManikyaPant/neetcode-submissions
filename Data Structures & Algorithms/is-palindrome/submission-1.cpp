class Solution {
public:
    bool isPalindrome(string arr) {
        int i = 0;
        int j = arr.length() - 1;

        while (i < j) {

            while (i < j && !isalnum(arr[i])) {
                i++;
            }

            while (i < j && !isalnum(arr[j])) {
                j--;
            }

            if (toupper(arr[i]) != toupper(arr[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};