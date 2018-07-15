//Josephus Circle

#include <iostream>
#include <vector>
using namespace::std;

int main() {
    int n, m;
    int trueLocation=0;
    int startPosition;
    int removePosition;
    int trueDelete;
    vector<int> userNo;

    cout << "Enter the number of players";
    cin >> n;
    cout << "Enter the execution mark";
    cin >> m;

    cout << "Number of players is: " << n << " & execution count is: " << m << "\n";
    cout << "Calculating survival position";

    for (int i = 1; i < n + 1; i++) {
        userNo.push_back(i);
    }


    while(userNo.size()>1)
    {

        removePosition=trueLocation+(m-1);
        trueDelete=removePosition%userNo.size();
        for(int i=trueDelete;i<userNo.size()-1;i++)
        {userNo[i]=userNo[1+i];}

        userNo.pop_back();

        trueLocation=trueDelete%userNo.size();
    }

    cout<<"Survivor postion (indexing:1) "<<userNo[0];

    return 0;
}