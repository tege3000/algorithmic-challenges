import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the separateNumbers function below.
    static void separateNumbers(String s) {
        BigInteger A, B; 
        int n = s.length();
        
    
        if(n < 2) {
            System.out.println("NO");
            return;
        }
        
        if(s.charAt(0) == '0') {
            System.out.println("NO");
            return;
        }

        String num = "";
        String oldNum = "";
        String og = "";
        int check = -1;
        int count = -1;
        
        for(int i = 0; i < n; i++) {
            og += s.charAt(i);
            oldNum = og;
            
            for(int j = i+1; j < n; j++) {
                num  += s.charAt(j);

                //System.out.println(oldNum + "    " + num);
                
                if(num.charAt(0) == '0') {
                    check = -1;
                    break;
                }
                
                A  = new BigInteger(oldNum);
                B  = new BigInteger(num);
                BigInteger diff = B.subtract(A);
                // System.out.println("A is " + A + " and B is " + B);
                // System.out.println("expr is " + expr);
                // System.out.println("diff is " + diff);


                if(B.compareTo(A) == 1 && diff.equals(BigInteger.ONE)) {
                    oldNum = num;
                    check = og.length();
                    num = ""; //clear num
                    
                    String rem = s.substring(j+1, n);
                    if(rem.length() == 0) {
                        count = 0;
                    }
                    else {
                        count = -1;
                    }

                    //System.out.println("count is " + count);
                    
                }
                 
            }
            
            num = "";
            if(count == 0) {
                break;
            }
        }

        
        if(check == -1) {
            System.out.println("NO");
        }
        else {
            if(count == 0) {
                System.out.printf("YES ");
                if(check == 0) {
                    System.out.printf("%s", s.charAt(0));
                }
                else {
                    for(int i = 0; i < check; i++) {
                        System.out.printf("%s", s.charAt(i));
                    }
                }
                System.out.printf("\n");
            }
            else {
                System.out.println("NO");
            }
            
            
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            separateNumbers(s);
        }

        scanner.close();
    }
}
