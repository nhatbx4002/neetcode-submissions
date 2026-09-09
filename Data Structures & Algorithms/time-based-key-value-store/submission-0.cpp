class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> stores;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        stores[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
       auto it = stores.find(key);
        if (it == stores.end()) {
            return "";
        }

       const auto &list = it->second;

       int left = 0 ; 
       int right = list.size()-1;
       string res="";

       while (left <= right) {

            int mid = left + (right-left)/2;

            if(list[mid].first <= timestamp){
                res = list[mid].second;
                left = mid+1;
            }else{
                right = mid-1;
            }
       } 

       return res;
    }
};
