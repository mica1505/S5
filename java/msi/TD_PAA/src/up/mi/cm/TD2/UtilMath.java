package up.mi.cm.TD2;
import up.mi.jgm.maths.*;

//rationnel = 9isma
public class UtilMath {
	public static Rationnel puissance(Rationnel r,int n){
		Rationnel res = new Rationnel(1,1);
		for(int i=0;i<n;i++) {
			res.multiplication(r);
		}
		return res;
	}
	public static Complexe Somme(Complexe c1,Complexe c2) {
		Complexe res = new Complexe(c1.getPartieReelle()+c2.getPartieReelle(),c1.getPartieImaginaire()+c2.getPartieImaginaire());	
		return res;
	}
	public static Complexe multiplication(Complexe c1,Complexe c2) {
		double rel,img;
		rel = (c1.getPartieReelle()*c2.getPartieReelle()) - (c1.getPartieImaginaire()*c2.getPartieImaginaire());
		img = (c1.getPartieReelle()*c2.getPartieImaginaire()) + (c1.getPartieImaginaire()*c2.getPartieReelle());
		Complexe res =  new Complexe(rel,img);
		return res;
	}
}
