// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int left, int right, bool fromRight) {
        if (right >= left) {
            if (right == left) return right;
            int middle = left + (right - left)/2;
            if (isBadVersion(middle) == true) {
                return binarySearch(left, middle, true);
            } else {
                return binarySearch(middle + 1, right, false);
            }
        } else {
            if (fromRight) return left;
            else return right;
        }
    }
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        return binarySearch(left, right, false);
    }
};
