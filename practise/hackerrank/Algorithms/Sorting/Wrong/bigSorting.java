import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the bigSorting function below.
    static String[] bigSorting(String[] unsorted) {
        int n = unsorted.length;
        BigInteger [] tmp = new BigInteger[n];

        for(int i = 0; i < n; i++) {
            tmp[i] = new BigInteger(unsorted[i]);
        }
        // for(int i = 0; i < tmp.length; i++) {
        //     for(int j = i; j < tmp.length; j++) {
        //         if(tmp[j].compareTo(tmp[i]) != 0 && tmp[j].compareTo(tmp[i]) != 1) {
        //             BigInteger temp = tmp[i];
        //             tmp[i] = tmp[j];
        //             tmp[j] = temp;

        //         }
        //     }
        //     unsorted[i] = tmp[i].toString();
        // }


        Arrays.sort(tmp);

        for(int i = 0; i < n; i++) {
            unsorted[i] = tmp[i].toString();
        }
        return unsorted;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] unsorted = new String[n];

        for (int i = 0; i < n; i++) {
            String unsortedItem = scanner.nextLine();
            unsorted[i] = unsortedItem;
        }

        String[] result = bigSorting(unsorted);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
