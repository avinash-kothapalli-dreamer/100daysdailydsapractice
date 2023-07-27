class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int>pq;
        sort(courses.begin(),courses.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });

        int sum = 0;

        for(auto it:courses){
            int duration = it[0];
            int endday = it[1];

            if(duration+sum<=endday){
                pq.push(duration);
                sum+=duration;
            }else if(!pq.empty() && pq.top()>duration ){
                
                sum+=duration-pq.top();
                pq.pop();
                pq.push(duration);
            }
        }

     return pq.size();
    }
};