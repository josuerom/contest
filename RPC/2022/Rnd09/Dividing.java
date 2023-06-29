package RPC_2022;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author josuerom
 */
public class Dividing {
    public static void main(String[] args) {

    }

    public static void pc2Read() {
        String vec[], line, error = "Precision";
        double a = 0, n = 0, x = 0, m = 0;

        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

        try {
            line = buffer.readLine();

            while (error.equals("Precision")) {
                vec = line.split(" ");
                a = Double.parseDouble(vec[0]);
                n = Double.parseDouble(vec[1]);

                if ((a >= 1 && a <= 100) && (n >= 0 && n <= 10000)) {
                    x = 1 / Math.pow(a, n);
                    x = x * Math.pow(10, a);

                }
            }

            buffer.close();
        } catch (NullPointerException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}