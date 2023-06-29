import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Boundary {
	public static void main(String[] args) {
		FastReader sc = new FastReader();
        int t = sc.nextInt(), x, y;
        TreeSet<Integer> arbol;
        for(int i = 0;i < t;i++) {
            arbol = new TreeSet<>();
            x = sc.nextInt();
            y = sc.nextInt();
            arbol.add(2);
            for(int j=1; j <= Math.sqrt(x); j++) {
                if(x%j==0) {
                    if((y-2)%j == 0) {
                    	arbol.add(j);
                    }
                    if((y-2)%(x/j) == 0) {
                    	arbol.add(x/j);
                    }
                }
                if((x-1)%j == 0) {
                    if((y-1)%j == 0) {
                    	arbol.add(j);
                    }
                    if((y-1)%((x-1)/j)==0) {
                    	arbol.add((x-1)/j);
                    }
                }
                if((x-2)%j == 0) {
                    if((y)%j == 0) {
                    	arbol.add(j);
                    }
                    if(y%((x-2)/j) == 0) {
                    	arbol.add((x-2)/j);
                    }
                }
            }
            System.out.print(arbol.size());
            for (Iterator<Integer> iterator = arbol.iterator(); iterator.hasNext();) {
            	System.out.print(" " + iterator.next());
			}
            System.out.println();
        }
	}
	static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader( 
                new InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() { 
        	return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
        	return Long.parseLong(next()); 
        } 
  
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
    }
}