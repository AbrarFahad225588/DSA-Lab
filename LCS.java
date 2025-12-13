import java.util.Scanner;
import java.lang.Math;

public class LCS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String t = sc.next();
        
        int n = s.length();
        int m = t.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        StringBuilder lcs = new StringBuilder();
        int i = n, j = m;
        
        while (i > 0 && j > 0) {
            if (s.charAt(i - 1) == t.charAt(j - 1)) {
                lcs.append(s.charAt(i - 1));
                i--;
                j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--; 
            } else {
                j--; 
            }
        }

        System.out.println(lcs.reverse().toString());
        
        sc.close();
}
}