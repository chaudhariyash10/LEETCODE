class Solution
{
public:
    bool canWinNim(int n)
    {
        if(n == 1)
            return true;
        if (n % 3 == 1)
            return false;

        else
            return true;
    }
};