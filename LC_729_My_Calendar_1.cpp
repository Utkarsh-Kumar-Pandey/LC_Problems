class MyCalendar {
public:
    vector<pair<int, int>> vec;
    MyCalendar() {}

    bool book(int startTime, int endTime) {

        for (auto it : vec) {
            if (max(it.first, startTime) < min(it.second, endTime)) {
                return false;
            }
        }
        vec.push_back({startTime, endTime});
        return true;
    }
};
