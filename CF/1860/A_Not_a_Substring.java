
/**
 *   author:  josuerom
 *   created: 17/08/23 09:54:11
**/
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;
import static java.lang.Math.*;

public class A_Not_a_Substring {
   public static void main(String[] authorJosuerom) {
      int tt = io.nextInt();
      while (tt-- > 0) {
         String s = io.next();
         solve(s);
      }
      io.close();
      System.exit(0);
   }

   static FastReader io = new FastReader();

   public static void solve(String s) {
      Stack<String> pl = new Stack<String>();
      int neg = 0, n = s.length();
      if (n % 2 != 0) {
         neg = -1;
      } else {
         for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
               pl.push("(");
            else if (!pl.empty())
               pl.pop();
            else
               neg--;
         }
      }
      if (neg < 0) {
         io.println("YES");
         StringBuilder sb = new StringBuilder();
         String x = "";
         for (int i = 0; i < n; i++) {
            x."()";
         }
         io.println(x);
         int i = x.indexOf(s);
      } else {
         io.println("NO");
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