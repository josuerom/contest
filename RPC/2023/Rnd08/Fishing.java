
/**
   █▀▄ █▀▀ ▄▀█ █▀█ █▀█ █▄░█ █▀▀
   █▄▀ ██▄ █▀█ █▀▄ █▄█ █░▀█ ██▄
    created: 17/07/23 19:38:52
**/
import java.util.Scanner;
import java.util.Arrays;
import static java.lang.Math.*;

public class Fishing {
   static final boolean DEBUG = false;

   public static void main(String[] args) {
      readInput();
   }

   public static void solve(int[] x, int[] y, int s, int n) {
      int small = x[0];
      int cont = 0;
      for (int i = 0; i < n - 1; i++) {
         if (x[i] < x[i + 1] && x[i] < small) {
            small = x[i];
         }
      }
      int max = small + s;
      for (int i = 0; i < n; i++) {
         if ((x[i] >= small && x[i] <= max) && (y[i] <= s)) {
            cont++;
         }
      }
      System.out.println(cont);

      // System.out.println(small);
      // System.out.println(Arrays.toString(x));
      // System.out.println(Arrays.toString(y));
   }

   public static void readInput() {
      Scanner sc = new Scanner(System.in);
      int s = sc.nextInt();
      int n = sc.nextInt();
      int x[] = new int[n];
      int y[] = new int[n];
      for (int i = 0; i < n; i++) {
         int cx = sc.nextInt();
         int cy = sc.nextInt();
         x[i] = cx;
         y[i] = cy;
      }
      solve(x, y, s, n);
      sc.close();
      System.out.close();
   }
}