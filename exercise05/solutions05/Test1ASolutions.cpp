#include <iostream>

using namespace std;

//Task 1
int FindRemainderToTheClosestNumber(int n)
{
    int remainder = n % 20;

    if(remainder > 10)
    {
        //We get the greatest number;
        return 20 - remainder;
    }

    //We get the smaller number;
    return remainder;
}

//Task 2
int IsStrangeSequence(int n)
{
    if(n < 3)
    {
        return -1;
    }

    int previous, current, numbersRead = 2;
    cin >> previous >> current;

    while(numbersRead < n && previous <= current)
    {
        previous = current;
        cin >> current;

        ++numbersRead;
    }

    if(numbersRead == 2)
    {
        return -1;
    }

    if(numbersRead == n && previous >= current)
    {
        return n - 2;
    }

    if(numbersRead == n)// && previous < current)
    {
        return -1;
    }

    int result = numbersRead - 2;
    while(numbersRead < n && previous >= current)
    {
        previous = current;
        cin >> current;

        ++numbersRead;
    }

    if(numbersRead == n)
    {
        return result;
    }

    return -1;
}

//Task 3
void FindMinimumFigure(int n)
{
    int minX, maxX, minY, maxY;
    int x, y;

    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        if(i == 0)
        {
            minX = x;
            maxX = x;
            minY = y;
            maxY = y;
        }

        if(x < minX)
        {
            minX = x;
        }
        if(x > maxX)
        {
            maxX = x;
        }
        if(y < minY)
        {
            minY = y;
        }
        if(y > maxY)
        {
            maxY = y;
        }
    }

    //rectangle
    cout << "rectangle\n";
    cout << minX << " " << maxY << " ";
    cout << maxX - minX << " " << maxY - minY << endl;

    //square
    int side = maxX - minX;
    if(side < maxY - minY)
    {
        side = maxY - minY;
    }
    cout << "square\n";
    cout << minX << " " << maxY << " ";
    cout << side << endl;
}

int main()
{
    int n;
    cin >> n;
    FindMinimumFigure(n);

    return 0;
}
