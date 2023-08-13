
/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 12/08/23 14:15:12
 **/
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Fading {
   public static void main(String[] Team2Bits) {
      int h = io.nextInt();
      int k = io.nextInt();
      int v = io.nextInt();
      int s = io.nextInt();
      solve(h, k, v, s);
      io.close();
      System.exit(0);
   }

   static FastReader io = new FastReader();

   public static void solve(int h, int k, int v, int s) {
      int ans = 0;
      while (h > 0) {
         v += s;
         v -= max(1, (v / 10));
         if (v >= k) {
            h += 1;
         } else if (v > 0 && v < k) {
            h -= 1;
            if (h == 0) {
               v = 0;
            }
         } else if (v <= 0) {
            h = 0;
            v = 0;
         }
         if (h > 0 && v > 0) {
            ans += v;
         }
         if (s > 0) {
            s -= 1;
         }
      }
      io.println(ans);
   }

   static class FastReader extends PrintWriter {
      private BufferedReader br;
      private StringTokenizer st;

      public FastReader() {
         this(System.in, System.out);
      }

      public FastReader(InputStream i, OutputStream o) {
         super(o);
         br = new BufferedReader(new InputStreamReader(i));
      }

      public FastReader(String problemName) throws IOException {
         super(problemName + ".out");
         br = new BufferedReader(new FileReader(problemName + ".in"));
      }

      public String next() {
         try {
            while (st == null || !st.hasMoreTokens())
               st = new StringTokenizer(br.readLine());
            return st.nextToken();
         } catch (Exception e) {
            e.printStackTrace();
         }
         return null;
      }

      public String nextLine() {
         String line = null;
         try {
            line = br.readLine();
         } catch (IOException e) {
            e.printStackTrace();
         }
         return line;
      }

      public int nextInt() {
         return Integer.parseInt(next());
      }

      public long nextLong() {
         return Long.parseLong(next());
      }

      public double nextDouble() {
         return Double.parseDouble(next());
      }

      public int[] readArray(int n) {
         int[] a = new int[n];
         for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
         }
         return a;
      }
   }
}