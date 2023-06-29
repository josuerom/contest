package RPC_2022;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Impossible {
    public static void main(String[] args) {
        String vec[], line;
        int n, longitud = 0, digitos = 0;
        long menor = 0, arr[], encontrado = 0;
        boolean son_consecutivos = true;

        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

        try {
            line = buffer.readLine();
            n = Integer.parseInt(line);
            vec = new String[n-1];

            line = buffer.readLine();
            vec = line.split(" ");
            longitud = vec.length;
            arr = new long[longitud];

            if ((n >= 10 && n <= 1000000) && (vec.length == (n - 1))) {

                for (int i = 0; i < arr.length; i++) {
                    arr[i] = Integer.valueOf(vec[i]);
                }
                Arrays.sort(arr);
                menor = arr[0] + 1;
                digitos = vec[0].length();

                if ((digitos >= 6 && digitos <= 10) && (arr[longitud-1] <= 1000000000)) {
                    for (int i = 1; i < longitud; i++) {
                        if (menor == arr[i]) {
                            menor++;
                        } else if (menor != arr[i]) {
                            encontrado = menor;
                            son_consecutivos = false;
                            break;
                        }
                    }
                }

                if (son_consecutivos == true) {
                    System.out.println("IMPOSSIBLE");
                } else {
                    System.out.println(menor);
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