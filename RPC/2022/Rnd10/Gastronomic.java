import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Gastronomic {

    public static void main(String[] args) {
        pc2Read();
    }

    public static void process(int rooms, int vec[]) {
        int size = vec.length;
        long corridor = (int) rooms * 2;
        Arrays.parallelSort(vec);

        int[] temporal = new int[size];
        int j = 0;
        for (int i = 0; i < size-1; i++) {
            if (i != 0) {
                if (vec[i] != vec[i+1]){
                    temporal[j++] = vec[i];
                } else {
                    temporal[j++] = vec[i];
                    vec[i + 1] = 0;
                }
            }
        }

        for (int i = 0; i < temporal.length; i++) {
            corridor += (long) temporal[i];
        }
        System.out.println(Arrays.toString(vec));
        System.out.println(corridor);
    }

    public static void pc2Read() {
        String vec[], line;
        int n;

        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

        try {
            line = buffer.readLine();
            n = Integer.valueOf(line);

            line = buffer.readLine();
            vec = line.split(" ");
            buffer.close();
            int arr[] = new int[vec.length];

            for (int i = 0; i < vec.length; i++) {
                arr[i] = Integer.valueOf(vec[i]);
            }
            process(n, arr);
        } catch (NullPointerException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}