int firstBadVersion(int n) {
        long long l = 0, h = n;
        while(l <= h){
            int m = (l + h)/2;
            bool res = isBadVersion(m), prev = isBadVersion(m-1);
            if(res and !prev)return m;
            else if(!res)l = m + 1;
            else if(res and prev)h = m - 1;
        }
        return 0;
    }