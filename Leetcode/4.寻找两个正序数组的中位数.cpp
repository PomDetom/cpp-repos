class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       int i = 0;
       int j = 0;
       int s = 0;
       int nums1_len = nums1.size();
       int nums2_len = nums2.size();
       std::vector<int> sum(nums1_len + nums2_len);

       while (i < nums1_len || j < nums2_len)
       {
           if (j == nums2_len)
           {
               sum[s] = nums1[i];
               ++s;
               ++i;
           }
           else if (i == nums1_len)
           {
               sum[s] = nums2[j];
               ++s;
               ++j;
           }
           else if (nums1[i] < nums2[j])
           {
               sum[s] = nums1[i];
               ++s;
               ++i;
           }
           else
           {
               sum[s] = nums2[j];
               ++s;
               ++j;
           }
       }
       
       int judge = nums1_len + nums2_len;

       if (judge % 2 == 0)
       {
           judge = judge/2 - 1;
           return ((double)(sum[judge] + sum[judge + 1]) / 2.0f);
       }
       else
       {
           judge = (judge - 1)/2;
           return (double)sum[judge];
       }
   }
};