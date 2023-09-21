public class UtilMath{
    public static int somme3(int a,int b, int c){
        return a+b+c;
    }

    public static long fact(int n){
        long res=n;
        while(res>0){
            res*=res--;
        }
        return res;
    }

    public static long puissance(int n, int m){
        long res=n;
        int a=m;
        while(a>0){
            res*=n;
            a--;
        }
        return res;
    }
}