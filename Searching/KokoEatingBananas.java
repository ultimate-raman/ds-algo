package Searching;

public class KokoEatingBananas {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = Integer.MIN_VALUE;

        for(int pile: piles) {
            right = Math.max(pile,right);
        }

        int mid = 0;

        int ans = 0;

        while(left<=right) {
            mid = (left + right)/2;

            if(valid(piles,mid) > h) {
                left = mid + 1;
            }
            else {
                ans = mid;
                right = mid-1; 
            }
        }

        return ans;
        
    }

    private int valid(int[] piles, int val) {
        int count = 0;

        for(int pile: piles) {
            count+=Math.ceil((double) pile / val);
        }

        return count;
    }
}
