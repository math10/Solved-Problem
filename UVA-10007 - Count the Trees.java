/**
 *
 * @author Sanim
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        BigInteger B[] = new BigInteger[302];
        BigInteger fact[] = new BigInteger[302];
        B[1] = BigInteger.ONE;
        for(int i = 2;i<=300;i++){
            B[i] = B[i-1].multiply(BigInteger.valueOf(4*i - 2));
            B[i] = B[i].divide(BigInteger.valueOf(i+1));
        }
        
        fact[0] = BigInteger.ONE;
        for(int i = 1;i<=300;i++)fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        for(int i = 1;i<=300;i++) B[i] = B[i].multiply(fact[i]);
        
        Scanner sc = new Scanner(System.in);
        int num;
       
        while(true){
            num = sc.nextInt();
            if(num == 0) break;
            System.out.println(B[num]);
        }
        
    }
}
