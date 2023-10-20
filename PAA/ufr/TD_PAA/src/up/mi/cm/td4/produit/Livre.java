package up.mi.cm.td4.produit;

public class Livre extends Produit{
	private String titre,auteur;
	private int isbn;
	private double prix;
	
	public Livre(String titre,String auteur,int isbn,double prix) {
		super(prix,TVA.REDUIT);
		this.titre = titre;
		this.auteur=auteur;
		this.prix = prix;	
	}
	
	public double prixTTC(double prixHorsTax,TVA tva) {
		return prixHorsTax + tva.getTaux()*prixHorsTax;
	}
}
