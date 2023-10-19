package up.mi.cm.td4.geometrie;
import up.mi.cm.td2.*;
public class Disque extends Figure{
	private Point centre;
	private double rayon;
	
	public Disque(Point centre,double rayon) {
		super("Disque");
		this.centre = centre;
		this.rayon = rayon;
	}
	
	
	public double perimetre() {
		return Math.PI*2*this.rayon;
	}
	public double surface() {
		return Math.PI*this.rayon*this.rayon;
	}
	public Figure translation(Vecteur V) {
		return null;
	}
	public String toString() {
		return super.toString() + "Perimetre : " + this.perimetre() +  " Surface : " + this.surface();
	}
}
