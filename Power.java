/**
 * Author: Sanjeev Kumar
 */

/** Question

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

**/


/**
 *  Input : x = 2, n = 3, d = 3
    Output : 2
    2^3 % 3 = 8 % 3 = 2.
 */
import java.util.*;

public class Power {

    public static int getPower(int x, int n,int d) {
        int res = 1;      
        x = x % d;  
      
        while (n > 0) 
        {  
            if((n & 1)==1) 
                res = (res * x) % d; 
            n = n >> 1;  
            x = (x * x) % d;  
        } 
        return res; 
    }
    
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int x = sc.nextInt(); 
        int n = sc.nextInt(); 
        int d = sc.nextInt(); 
        System.out.println("Output:"+ getPower(x, n, d));
    }
}