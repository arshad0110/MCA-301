#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool selColumn(const vector<int>& v1, const vector<int>& v2) {
    
    return v1[1] < v2[1];
}



class Triathlon {
    
    public:
    int n;
    void Schedule(vector<vector<int>> &data)
    {
        sort(data.begin() , data.end() , selColumn );
    cout << "\n Order of contestants for small completion time\n\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i][0] << "\t";
    }
    cout << endl;
    }
    void display(vector<vector<int>> data)
    {
        cout << "\n-----------------------------------------------------------------";
    cout << "\nContestant Number\t|\tSwim Time\t|\tBike Time\t|\tRun Time\n";
    cout << "-----------------------------------------------------------------\n";
    for ( int i = 0; i < data.size(); i++ ) {
        cout << "\t\t" << data[i][0] << "\t\t\t|\t\t" << data[i][1] << "\t\t|\t\t" << data[i][2] << "\t\t|\t" << data[i][3];
        cout << endl;
    }
    }
    void Input()
    {
    cout << "\nEnter Number of contestants\t:\t";
    cin >> n;
    vector<vector<int>> data(n);
    cout << "\nEnter Values";
    cout << "\nSwim Time , Bike Time and then Run Time\n";
    for ( int i = 0; i < n; i++) {
        data[i] = vector<int>(4);
        data[i][0] = i + 1;
        cin >> data[i][1];
        cin >> data[i][2];
        cin >> data[i][3];
    }
    display(data);
    Schedule(data);
    data.clear();
    }
};


int main() {
    Triathlon T;
    T.Input();
    return 0;
    /* Time Complexity:
       Schedule function takes 0(nlogn) to sort the input
       and Input() takes O(n) time 
       Therefore,
       T(n)=O(nlogn) + O(n)
       T(n)=O(nlogn)
}