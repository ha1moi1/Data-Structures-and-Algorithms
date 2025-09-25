#include <iostream>
using namespace std;
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

class Solution
{
public:
    int romanToInt1(string s) //Noob (riel)
    {
        int result = 0;
        int length = s.size();
        int* a = new int[length];
        for(int i = 0; i < length; i++)
        {
            switch(s[i])
            {
                case 'I':
                {
                    a[i] = 1;
                    break;
                }
                case 'V':
                {
                    a[i] = 5;
                    break;
                }
                case 'X':
                { 
                    a[i] = 10;
                    break;
                }
                case 'L':
                {
                    a[i] = 50;
                    break;
                }
                case 'C':
                {
                    a[i] = 100;
                    break;
                }
                case 'D':
                {
                    a[i] = 500;
                    break;
                }
                case 'M':
                {
                    a[i] = 1000;
                    break;
                }
            }
        }

        int i = 0;
        while (i < length)
        {
            if (i + 1 < length && a[i] < a[i + 1])
            {
                result += a[i + 1] - a[i];
                i += 2;
            }
            else
            {
                result += a[i];
                i++;
            }
        }
        return result;
    }
    int romanToInt2(string s) //Pro
    {
        int result = 0;
        
        switch(s[0])
        {
            case 'I':
                {
                    result += 1;
                    break;
                }
                case 'V':
                {
                    result += 5;
                    break;
                }
                case 'X':
                { 
                    result += 10;
                    break;
                }
                case 'L':
                {
                    result += 50;
                    break;
                }
                case 'C':
                {
                    result += 100;
                    break;
                }
                case 'D':
                {
                    result += 500;
                    break;
                }
                case 'M':
                {
                    result += 1000;
                    break;
                }
        }

        for(int i = 1; i < s.size(); i++)
        {
            switch(s[i])
            {
                case 'I':
                    {
                        result += 1;
                        break;
                    }
                    case 'V':
                    {
                        if(s[i - 1] == 'I')
                        {
                            result += 3;
                            break;
                        }
                        result += 5;
                        break;
                    }
                    case 'X':
                    {
                        if(s[i - 1] == 'I')
                        {
                            result += 8;
                        }
                        else result += 10;

                        break;
                    }
                    case 'L':
                    {
                        if(s[i - 1] == 'X')
                        {
                            result += 30;
                        }
                        else result += 50;
                        break;
                    }
                    case 'C':
                    {
                        if(s[i - 1] == 'X')
                        {
                            result += 80;
                        }
                        else result += 100;
                        break;
                    }
                    case 'D':
                    {
                        if(s[i - 1] == 'C')
                        {
                            result += 300;
                        }
                        else result += 500;
                        break;
                    }
                    case 'M':
                    {
                        if(s[i - 1] == 'C')
                        {
                            result += 800;
                        }
                        else result += 1000;
                        break;
                    }
            }
        }
        return result;
    }
};
