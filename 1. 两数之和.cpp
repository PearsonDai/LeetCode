/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nElements=nums.size();
        unordered_map<int,int> hashTable;
        for(int i=0;i<nElements;++i){
            if(hashTable.find(target-nums[i])==hashTable.end()){
                hashTable.insert({nums[i],i});
            }
            else{
                return {(hashTable.find(target-nums[i]))->second,i};
            }
        }
        return {};
    }
};
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nElements=nums.size();
        unordered_map<int,int> hashTable;
        for(int i=0;i<nElements;++i){
            auto it=hashTable.find(target-nums[i]);
            if(it!=hashTable.end()){
                return {it->second,i};
            }
            hashTable[nums[i]]=i;
        }
        return {};
    }
};

