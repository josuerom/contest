/**
 *  author:  josuerom
 *  created: 11/03/23 16:22:07
 **/
import java.text.DecimalFormat;
import java.util.Scanner;
import static java.lang.Math.*;

public class Eruption {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat(".#########");
        Scanner sc = new Scanner(System.in);
        double N = sc.nextDouble();
        double r = sqrt(N/Math.PI);
        double p = 2*Math.PI*(r);
        String ans = String.valueOf(df.format(p));
        System.out.println(ans.replaceAll(",", "."));
    }
}
/* test case
 25.066282746
124.526709336
*/