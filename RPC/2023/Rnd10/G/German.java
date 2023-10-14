
/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 26/08/23 14:44:06
 **/
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class German {
   public static void main(String[] Team2Bits) {
      int n = io.nextInt();
      solve(n);
      io.close();
      System.exit(0);
   }

   static FastReader io = new FastReader();
   static ArrayList<Integer> a = new ArrayList<>();

   public static void preCalculate(ArrayList<Integer> a, int n) {
      for (int i = 11, k = 11; i <= n;) {
         a.add(i);
         if (i == 99 || i == 999 || i == 9999 || i == 99999 || i == 999999
               || i == 9999999 || i == 99999999 || i == 999999999) {
            k = k * 10 + 1;
            i = k;
         } else
            i += k;
      }
      // io.println(a.toString());
   }

   public static void solve(int n) {
      if (n < 10) {
         io.println(n + 1);
         return;
      }
      preCalculate(a, n);
      int sz = String.valueOf(n).length();
      sz = (sz > 2) ? sz - 2 : 0;
      io.println((10 + a.size() + sz));
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