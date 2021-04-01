vector<vector<int> > anagrams(const vector<string> &A) {
    unordered_map<string, int>container;
    string tempString;
    vector< vector<int> > groupOfAnagrams;
    for(int i = 0; i<A.size(); i++){
        tempString = A[i];
        sort(tempString.begin(), tempString.end());
        if(container.find(tempString) == container.end()){
            groupOfAnagrams.push_back({i + 1});
            container[tempString] = groupOfAnagrams.size() - 1;
        }
        else groupOfAnagrams[container[tempString]].push_back(i + 1);
    }
    return groupOfAnagrams;
}

Time Complexity : O(n*m*log*m) { n =  size of the list given by user , m = size of max string in the list of string given by user }
Space Complxity : O(n) { first is for hashmap of max n size }
