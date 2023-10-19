package up.mi.cm.td4;

public class UtilTab {
	
	public static Integer maxTab(Integer [] tab) {
		Integer res = tab[0];
		for(int i=0;i<tab.length;i++) {
			if(tab[i]>res) {
				res = tab[i];
			}
		}
		return res;
	}
	
    public static double moyenne(Integer [] tab){
        double res = 0;
        int length = tab.length;
        for(int i=0;i<length;i++){
            res+=tab[i];
        }
        return res/length;
    }
    
    public static void triTab(Integer [] t){
        Integer temp;
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
}
