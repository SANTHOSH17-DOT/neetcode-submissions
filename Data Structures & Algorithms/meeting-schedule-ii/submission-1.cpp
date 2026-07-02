/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s,e;
        for(auto& interval:intervals){
            s.push_back(interval.start);
            e.push_back(interval.end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int sIdx=0,eIdx=0,count=0,res=0;
        while(sIdx<s.size()){
            if(s[sIdx]<e[eIdx]){
                sIdx++;
                count++;
            }else{
                eIdx++;
                count--;
            }
            res = max(res,count);
        }
        return res;
    }
};
