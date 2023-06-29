
import java.util.Scanner;

/**
 * @author Dearone
**/
public class Coffee {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char s[] = sc.next().toCharArray();
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                index = i;
                //System.out.println(index);
                break;
            }
        }
        int contC = 0;
        int contR = 0;
        for (int i = index; i < n; i++) {
            if (s[i] == '1') {
                contC = 2; // 2 cafes
                contR++;   // 1 cafe
                //System.out.println(contC+" "+contR);
            } else if (s[i] == '0') {
                if (contC > 0) {
                    contC--;
                    contR++;
                }
            }
        }
        System.out.println(contR);
    }
}