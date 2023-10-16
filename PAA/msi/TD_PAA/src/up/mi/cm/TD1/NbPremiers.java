package up.mi.cm.TD1;


public class NbPremiers{
	
	static boolean premierKN(int n) {
		boolean premier = true;
		for(int i=0;i<n && premier;i++) {
			if(n%i==0) {
				premier = false;
			}
		}
		return premier;
	}
	
	static boolean premierK2I(int n) {
		if (n == 2)
			return true;
		if ((n < 2) || (n % 2) == 0)
			return false;
		//test que sur les nombre impairs
		for (int k = 3; k <= Math.sqrt(n); k += 2) {
			if ((n % k) == 0)
				return false;
		}
		return true;
	}
	
	static boolean premierSqrt(int n) {
		boolean premier = true;
		int impairs;
		for(int i=1;i<n && premier;i++) {
			impairs = (i*2)+1;
			if(impairs > Math.sqrt(n)){
				premier = false;
			}
		}
		return premier;
	}
	
	
	/**
	 * 
	 * @param n integer le nombre de nombre premiers voulus
	 */
	
	static String nPremiersNombrePremiers(int n) {
		StringBuffer res = new StringBuffer(n);
		for(int i=0;i<n;i++) {
			if(premierSqrt(i)) {
				res.append(" "+i);
			}
		}
		return res.toString();
	}
	
	public static void main(String [] args) {
		System.out.println(premierSqrt(15));
		nPremiersNombrePremiers(136);
	}
}
