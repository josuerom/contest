import java.util.Scanner;

public class Game {
    public static void main(String[] authorJosuerom) {
        readInput();
    }

    static void solve(int[] a) {
        System.out.print((a[0]*6+a[1]*3+a[2]*2+a[3]*1+a[4]*2) + " ");
    }

    static void readInput() {
        Scanner sc = new Scanner(System.in);
        int tt = 2;
        while (tt-- > 0) {
            int[] a = new int[5];
            for (int i = 0; i < 5; i++)
                a[i] = sc.nextInt();
            solve(a);
        }
        sc.close(); System.out.close();
    }
}