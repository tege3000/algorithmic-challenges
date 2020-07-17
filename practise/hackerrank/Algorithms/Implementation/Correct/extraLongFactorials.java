//========NOTE=========
// I would normally use cpp, however this particular problem 
// requires the use of languages that support BigIntegers.
// Cpp doesnt support BigIntegers, instead you would have to write 
// additional code to handle huge values.
// Hence why i chose Java

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {
        BigInteger result = new BigInteger("1");
        for(int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }

        System.out.printf("%d", result);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
