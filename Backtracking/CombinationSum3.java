package Backtracking;
import java.util.*;

public class CombinationSum3 {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> currentCombination = new ArrayList<>();
        backtracking(k,n,1,ans,currentCombination);
        return ans;
    }

    public void backtracking(int k, int n, int number, List<List<Integer>> ans, List<Integer> currentCombination) {
        if(n==0 && k == 0) {
            ans.add(new ArrayList<>(currentCombination));
            return;
        }

        if(k <= 0 || number > 9) return;

        currentCombination.add(number);
        backtracking(k-1, n-number, number+1, ans, currentCombination);
        currentCombination.remove(currentCombination.size()-1);

        backtracking(k, n , number + 1, ans, currentCombination);
    }
}