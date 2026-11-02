
import java.util.*;

class Solution {
    void solve(int i, int n, String currans, String curr,
               String s, List<String> ans) {

        if (n > 4) return;

        if (i == s.length()) {
            if (n == 3 && !curr.isEmpty() &&
                Integer.parseInt(curr) <= 255) {
                ans.add(currans + curr);
            }
            if (n == 4 && curr.isEmpty()) {
                ans.add(currans.substring(0, currans.length() - 1));
            }
            return;
        }

        char c = s.charAt(i);

        if (c == '0') {
            if (curr.isEmpty()) {
                solve(i + 1, n + 1,
                      currans + c + ".", "", s, ans);
            } else {
                if (Integer.parseInt(curr + c) <= 255) {
                    solve(i + 1, n, currans, curr + c, s, ans);
                }

                if (n < 3) {
                    solve(i + 1, n + 2,
                          currans + curr + "." + c + ".",
                          "", s, ans);
                }
            }
        } else {
            if (Integer.parseInt(curr + c) <= 255) {
                solve(i + 1, n, currans, curr + c, s, ans);
            }

            if (!curr.isEmpty() && n < 3) {
                solve(i + 1, n + 1,
                      currans + curr + ".", "" + c, s, ans);
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();

        if (s.length() < 4 || s.length() > 12) return ans;

        solve(0, 0, "", "", s, ans);
        Collections.sort(ans);
        return ans;
    }
}
