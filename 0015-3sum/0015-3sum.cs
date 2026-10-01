// public class Solution {
//     public IList<IList<int>> ThreeSum(int[] nums) {
        
//         Array.Sort(nums);
//         IList< IList < int> > ans = new List< IList <int> >() ;
//         for(int i = 0; i < nums.Length- 2 ; i++){
//             for(int j = i+1 ; j < nums.Length - 1; j++){
//                 int k = nums.Length - 1 ;
//                 while(j<k){
//                     int sum = nums[i] + nums[j] + nums[k];
//                     if(sum == 0 ) ans.Add(new List<int> { nums[i], nums[j], nums[k] });
//                     else if(sum < 0) k++;
//                     else k--;
//                 }
//             }
//         }
//         return ans;
//     }
// }




public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        Array.Sort(nums);

        IList<IList<int>> ans = new List<IList<int>>();

        for (int i = 0; i < nums.Length - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.Length - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    ans.Add(new List<int> { nums[i], nums[j], nums[k] });

                    while (j < k && nums[j] == nums[j + 1])
                        j++;

                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return ans;
    }
}
