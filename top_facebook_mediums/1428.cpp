/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {        
        int i = 0;
        int j = binaryMatrix.dimensions()[1] - 1;
        int result = -1;
        while (j >= 0 && i < binaryMatrix.dimensions()[0]) {
            if (binaryMatrix.get(i, j) == 1) {
                result = j;
                --j;
            } else {
                ++i;
            }
    }
        return result;
    }
};
