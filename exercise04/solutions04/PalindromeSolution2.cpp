#include <iostream>
#include <string>
#include <cmath>


int GetNthDigit(int n, int number)
{
    while(n)
    {
        number /= 10;
        n--;
    }
    return number % 10;
}

bool PalindromeNumCheck()
{
  int start(0), end(0), n;
  std::cin >> n;
  end = log10(n);  //position in reverse order of the first digit
  while (end > start)
  {
      //check if on parallel positions there are different numbers
      if (getNthDigit(start, n) != getNthDigit(end, n))
      {
          return false;
      }
      start++;
      end--;
  }
  return true;
}

int main()
{
    std::cout << PalindromeNumCheck();
    return 0;
}