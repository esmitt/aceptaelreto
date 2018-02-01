#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() 
{
  long long ncases;
  string line;
  getline(cin, line);
  ncases = std::stoll(line);
  while (ncases--) 
  {
    getline(cin, line);
    int number = std::stoi(line);
    long long iterations = 0;
    while (number != 6174) 
    {
      int dimNum = line.size();
      std::string original = std::string(4 - dimNum, '0').append(line);
      std::sort(original.begin(), original.end());
      int minor = std::stoi(original);
      std::reverse(original.begin(), original.end());
      int major = std::stoi(original);
      number = major - minor;
      if (number == 0) 
      {
        iterations = 8;
        break;
      }
      string newNumber = std::to_string(number);
      line = std::string(4 - newNumber.size(), '0').append(newNumber);
      iterations++;
    }
    cout << iterations << endl;
  }
  return 0;
}