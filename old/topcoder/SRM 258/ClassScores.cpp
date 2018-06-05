#include <bits/stdc++.h>

using namespace std;

class ClassScores {
    public:
    vector<int> findMode(vector<int> scores) {
        map<int, int> m;
        int best = 0;
        for (auto x : scores) {
            m[x]++;
            best = max(best, m[x]);
        }
        vector<int> ans;
        for (auto x : m) {
            if (x.second == best) ans.push_back(x.first); 
        }
        return ans;
    }
};

// CUT begin
ifstream data("ClassScores.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> scores, vector<int> __expected) {
    time_t startClock = clock();
    ClassScores *instance = new ClassScores();
    vector<int> __result = instance->findMode(scores);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "\033[32mPASSED!\033[0m" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "\033[31mFAILED!\033[0m" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> scores;
        from_stream(scores);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  \033[33mTestcase #" << cases - 1 << "\033[0m ... ";
        if ( do_test(scores, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1526259228;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : \033[33m" << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << "\033[0m points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ClassScores (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
