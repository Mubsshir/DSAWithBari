/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
     public static void main(String[] args) {
        List<String> inputByLine=new ArrayList<String>();
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLong()) {
            long N = sc.nextLong();
            long max = find_max(N, map);
            System.out.println(max);
        }
    }

    static long find_max (long n, Map<Long,Long> map)
    {
        if(n ==0|| n==1) return n;
        if(map.containsKey(n)) return map.get(n);
        long max = Math.max(n, find_max(n/2,map) + find_max(n/3,map) + find_max(n/4,map));
        if(n<10000) map.put(n,max);
        return max;
    }
    
}