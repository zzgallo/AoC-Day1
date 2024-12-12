#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>

using namespace std;

int main() {

ifstream inputFile("data.txt"); // Open input file
if (!inputFile.is_open()) {                             
    cerr << "Failed to open input file." << endl; // Return console error if input file fails to open
    return 1;
}
vector<int> list1; // Data storage for list 1
vector<int> list2; // Data storage for list 2
string line; // Temp variable that stores each line from the input file
/* the getLine() function reads the line and stores them as strings
then we use stringstream to convert them back to integers
*/

while (getline(inputFile, line)) {
    stringstream ss(line);
    int num1, num2;
    

    if (ss >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    } else {
        cerr << "Error" << line << endl;
    }
}

sort(list1.begin(), list1.end());
sort(list2.begin(), list2.end());

cout << "Column 1:" << endl;
for (int num : list1) {
    cout << num << endl;
}

cout << "Column 2:" << endl;
for (int num : list2) {
    cout << num << endl;
}

vector<pair<int, int>> listPairs;

for (size_t i= 0; i < list1.size(); ++i) {
    listPairs.push_back({list1[i], list2[i]});
}

vector<int> absDiff;

for (auto& p : listPairs) {
    int diff = abs(p.first - p.second);
    absDiff.push_back(diff);

}
cout << endl;
cout << "List of absolute differences: " << endl;
for (int diff : absDiff) {
    cout << diff << endl;
}

auto result = reduce(absDiff.begin(), absDiff.end());
cout << "Total distance: " << result << endl;

}