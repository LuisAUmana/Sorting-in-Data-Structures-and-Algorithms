// Count inversions - homework
// Based off of mergesort
//By Luis Umana
#include <vector>
#include <algorithm> // For copy

using namespace std;

int merge(vector<int>& nums, int left, int middle, int right) {
   int m, n, o, p;
   int count = 0;
   m = left, n = middle, o = left, p = nums.size();
   vector<int> temp(n);
   while ((m <= middle - 1) && (n <= right)) {
       if (nums[m] <= nums[n])
           temp[o++] = nums[m++];
       else {
           temp[o++] = nums[n++];
           count = count + (middle - m);
       }
   }
   while (m <= middle - 1)
       temp[o++] = nums[m++];
   while (o <= right)
       temp[o++] = nums[n++];
   for (m = left; m <= right; m++) {
       nums[m] = temp[m];
   }

   return count;
}

int mergeInv(vector<int>& nums, int left, int right) {
   int middle, count = 0;
   if (right > left) {
       middle = (right + left) / 2;
       count += mergeInv(nums, left, middle);
       count += mergeInv(nums, middle + 1, right);
       count += merge(nums, left, middle + 1, right);
   }
   return count;
}

int countInv(vector<int>& nums) {
   return mergeInv(nums, 0, nums.size() - 1);
}

