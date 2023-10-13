package up.mi.cm.td2;

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
	public static void main( String [ ] args ) {
		Personne p = new Personne ( "John" , "Lennon" ) ;
		p.addNumero( "0123456789" ) ;
		p.addNumero( "0132456789" ) ;
		p.addNumero( "0123996789" ) ;
		p.addNumero( "0123459876" ) ;
		System.out.println(p.toString());
	}
	
	public static String remplacerLettre(String str,String ch1,String ch2) {
		int len = ch2.length();
		System.out.println("HAHHA");
		return "a faire plus tard";
	}
	
}
		
		
		
		
		
		
		
		
		
		