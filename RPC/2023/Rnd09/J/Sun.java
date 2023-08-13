
/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 12/08/23 16:55:06
 **/
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Sun {
   public static void main(String[] Team2Bits) {
      int ds = io.nextInt();
      int ys = io.nextInt();
      int dm = io.nextInt();
      int ym = io.nextInt();
      solve(ds, ys, dm, ym);
      io.close();
      System.exit(0);
   }

   static FastReader io = new FastReader();

   public static void solve(int ds, int ys, int dm, int ym) {
      int mcm = MCM(ys, ym);
      int x = max(ds, dm);
      while ((x % mcm != ds % mcm) || (x % ym != dm % ym)) {
         x++;
      }
      io.println(mcm - ds);
   }

   public static int MCM(int a, int b) {
      int x = b, y = a;
      while (x != 0) {
         int t = x;
         x = y % x;
         y = t;
      }
      return (a * b) / y;
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