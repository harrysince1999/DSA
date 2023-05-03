class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int>s1;
        set<int>s2;
        for(int i=0;i<nums1.size();i++)
            s1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            s2.insert(nums2[i]);
        
        set<int>a;
        set<int>b;
        
        for(int i=0;i<nums1.size();i++)
        {
            if(s2.find(nums1[i])==s2.end())
                a.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(s1.find(nums2[i])==s1.end())
                b.insert(nums2[i]);
        }
        vector<int> x;
        vector<int>y;
        for(auto it: a)
            x.push_back(it);
        for(auto it: b)
            y.push_back(it);
        
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};