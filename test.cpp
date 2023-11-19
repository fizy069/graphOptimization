#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    cout << arr[0] << arr[1] << arr[2] << endl;
}

int main()
{

    vector<int> arr{5, 2, 3};
    func(arr);
    cout << arr[0] << arr[1] << arr[2] << endl;
    return 0;
}