package up.mi.cm.TD1;

public class UtilMoy{
    public static double moyenne(double exam, double cc){
        double res;
        if(exam>cc){
            res = cc;
        }
        else{
            res = (cc+exam)/2;
        }
        return res;
    }
    public static double[] moyTab(double [] tab){
        int length = tab.length;
        double [] res = new double[length/2];
        for(int i=0;i<length;i+=2){
            res[i] = moyenne(tab[i],tab[i+1]);
        }
        return res;
    }
}