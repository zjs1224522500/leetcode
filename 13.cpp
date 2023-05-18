class Solution
{
public:
    int romanToInt(string s)
    {
        int size = s.length();
        int result = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (i < size - 1 && getValue(s[i]) < getValue(s[i + 1]))
            {
                result -= getValue(s[i]);
            }
            else
            {
                result += getValue(s[i]);
            }
        }
        return result;
    }

    int getValue(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
};