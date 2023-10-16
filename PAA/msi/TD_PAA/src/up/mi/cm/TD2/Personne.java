package up.mi.cm.TD2;

import java.util.List;
import java.util.ArrayList;

public class Personne {
	private String nom ;
	private String prenom ;
	private List <String > numerosTelephone;
	
	public Personne ( String prenom , String nom) {
		this.prenom = prenom ;
		this.nom = nom ;
		numerosTelephone = new ArrayList <String > () ;
		}

	public void addNumero( String numero ) {
		numerosTelephone.add (numero) ;
	}
	
	public String toString() {
		StringBuilder resultat = new StringBuilder(prenom + " " + nom + " \n") ;
		for ( int i = 0 ; i < numerosTelephone.size() ; i++){
			resultat.append("numero " + ( i +1) + " : " );
			resultat.append(numerosTelephone.get(i) + " \n" );
		}
		return resultat.toString();
	}
	public String getNom() {
		return this.nom;
	}
	public String getPrenom() {
		return this.prenom;
	}
	public String getNum() {
		StringBuilder resultat = new StringBuilder("");
		for ( int i = 0 ; i < numerosTelephone.size() ; i++){
			resultat.append("numero " + ( i +1) + " : " );
			resultat.append(numerosTelephone.get(i) + " \n" );
		}
		return resultat.toString();
	}
	public boolean equals(Object o) {
		if(o == null || !(o instanceof Personne)) {
			return false;
		}
		if(o == this) {return true;}
		Personne p = (Personne) o;
		return ((this.getNom()).equals(p.getNom())) && ((this.getPrenom()).equals(p.getPrenom()));
	}
	
	public static String remplacerLettre(String str,String ch1,String ch2) {
		//si l chaine de remplacement est plus longue que la chaine originale on fait un delete puis on append 
		//sinon
		//on gare ce que j;ai fait
		int len = ch2.length();
		StringBuilder res = new StringBuilder(str);
		int lenRemplacement = ch2.length();
		
		for(int i=res.indexOf(ch1);i!=-1;i=res.indexOf(ch1)) {
			res.replace(i, i+lenRemplacement, ch2);
		}
		return res.toString();
	}
	
	public static void main( String [ ] args ) {
		Personne p = new Personne ( "John" , "Lennon" ) ;
		p.addNumero( "0123456789" ) ;
		p.addNumero( "0132456789" ) ;
		p.addNumero( "0123996789" ) ;
		p.addNumero( "0123459876" ) ;
		System.out.println("dans personne : ");
		System.out.println(remplacerLettre("Bonjonr","j","g"));
	}
	
}
		
		
		
		
		
		
		
		
		
		