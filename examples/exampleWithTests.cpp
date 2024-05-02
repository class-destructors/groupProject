#include<iostream>
#include"math.hpp"

using namespace std;

int main()
{
  const int num1 = 4;
  const int num2 = 7;
  cout << num1 << " squared is " << square(num1) << endl;
  cout << num2 << " squared is " << square(num2) << endl;
  cout << num1 << " times " << num2 << " is " << multiply(num1, num2) << endl;
}
