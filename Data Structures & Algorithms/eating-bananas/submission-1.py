import math
def ok(piles , mid , h):
        hours = 0
        for banana in piles:
            time_taken = max(1 , math.ceil(banana/mid))
            hours += time_taken
        print(mid , hours)
        return hours<=h

class Solution:
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = int(1e10)
        ans = -1
        while(l<=r):
            mid  = l+ (r-l)//2
            if(ok(piles , mid , h)):
                ans = mid
                r = mid-1
            else:
                l = mid+1
        return int(ans)

        