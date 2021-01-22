int guessNumber(int n)
{
    long left = 0, right = n, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        int gue = guess(mid);

        if (gue == 0)
        {
            return mid;
        }
        else if (gue == 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return mid;
}