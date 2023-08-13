
/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 12/08/23 13:36:04
 **/
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Streets {
   public static void main(String[] Team2Bits) {
      int n = io.nextInt();
      int q = io.nextInt();
      q *= 2;
      String[] a = new String[n];
      for (int i = 0; i < n; i++)
         a[i] = io.next();
      String[] b = new String[q];
      for (int i = 0; i < q; i += 2) {
         b[i] = io.next();
         b[i + 1] = io.next();
      }
      solve(q, a, b);
      io.close();
      System.exit(0);
   }

   static FastReader io = new FastReader();

   public static void solve(int q, String a[], String b[]) {
      int n = a.length;
      for (int i = 0; i < q; i += 2) {
         int fi = 0, se = 0;
         for (int l = 0; l < n; l++) {
            if (b[i].equals(a[l]))
               fi = l;
            if (b[i + 1].equals(a[l]))
               se = l;
            if (fi != 0 && se != 0)
               break;
         }
         io.println(abs(fi - se) - 1);
      }
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