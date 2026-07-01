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
        map<int,int> overlapCount;
        for(auto& interval:intervals){
            overlapCount[interval.start]++;
            overlapCount[interval.end]--;
        }
        int overlaps = 0;
        int result = 0;
        for(auto& t:overlapCount){
            overlaps+=t.second;
            result = max(result,overlaps);
        }
        return result;
    }
};
