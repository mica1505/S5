package up.mi.cm.td1;


public class UtilTab{
    public static double moyenne(double [] tab){
        double res = 0;
        int length = tab.length;
        for(int i=0;i<length;i++){
            res+=tab[i];
        }
        return res/length;
    }

    public static void triTab(double [] t){
        double temp;
        for(int i=t.length;i>=1;i--){
            for(int j=0;i>=i-1;j++){
                if(t[j+1]<t[j]){
                    temp = t[j];
                    t[j]=t[j+1];
                    t[j+1]=temp;
                }
            }
        }
    }
    public static double mediane(double [] tab){
        double res;
        int len = tab.length;
        if(len%2==0){
            res = (tab[(len/2)-1] + tab[(len/2)])/2;
        }
        else{
            res = tab[(len/2)];
        }
        return res;
    }
    public static double moyP(double [] td, int [] ti){
        double res=0;
        int somme_coef = 0;
        for(int i=0;i<td.length;i++){
            res+=(td[i]*ti[i]);
            somme_coef+=ti[i];
        }
        return res/somme_coef;
    }
}
