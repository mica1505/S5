package up.mi.cm.TD2;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;


public class HashMapT9 {
	//constructeur aucune ptn d'idee
	public static byte getChiffreT9(char c) {
		switch(Character.toLowerCase(c)) {
			case 'a','b','c' : return 2;
			case 'd','e','f' : return 3;
			case 'g','h','i' : return 4;
			case 'j','k','l' : return 5;
			case 'm','n','o' : return 6;
			case 'p','q','r','s' : return 7;
			case 't','u','v' : return 8;
			case 'w','x','y','z'  : return 9;
			default : return 0;
		}
	}
	
	public static String codeToNum(String word) {
		StringBuffer res = new StringBuffer("");
		for(int i=0;i<word.length();i++) {
			res.append(getChiffreT9(word.charAt(i)));
		}
		return res.toString();
	}
	
	public static void enregistrer(HashMap<String, ArrayList<String>> dico, String chaine) {
		//on lui donne un mot on l'encode on cherche sa cle dans le dico et on l'ajoute dans l'arrayList
		String code =  codeToNum(chaine);
		if(dico.containsKey(code)) {
			dico.get(code).add(chaine);
		}
		else {
			dico.put(code, new ArrayList<String>(Arrays.asList(chaine)));
		}
	}
	
	public static ArrayList<String> recuperer(HashMap<String , ArrayList<String>> dico ,String chaineT9){
		ArrayList<String> res = dico.get(chaineT9);
			return (res==null)? new ArrayList<String>(): res;
	}
	
	public static void main(String [] args) {
		HashMap<String , ArrayList <String>> dico = new HashMap<String ,ArrayList <String>>();
				enregistrer( dico , "bonjour" ) ;
				enregistrer( dico , "bonne" ) ;
				enregistrer( dico , "comme" ) ;
				System.out.println(recuperer(dico , "26663" ) ) ;
				System.out.println( recuperer ( dico , "2665687" ) ) ;
				System.out.println( recuperer ( dico , "123456" ) ) ;
		
	}
}
