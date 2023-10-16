package up.mi.cm.TD1;

public class UtilMath{
    public static int somme3(int a,int b, int c){
        return a+b+c;
    }

    public static long fact(int n){
        long res=1;
        while(n>0){
            res*=(n--);
        }
        return res;
    }

    public static long puissance(int n, int m){
        long res=1;
        int a=m;
        while(a>0){
            res*=n;
            a--;
        }
        return res;
    }
}