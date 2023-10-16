package up.mi.cm.td2;

public class Vecteur{
	
	Point a,b;
	
	public Vecteur(Point a,Point b) {
		this.a=a;
		this.b=b;
	}
	
	public Point getA() {
		return this.a;
	}
	
	public Point getB() {
		return this.b;
	}
	
	public boolean equals(Object o) {
		if((o == null) || !(o instanceof Vecteur )) {
			return false;
		}
		if( (o==this)) { return true;}
		Vecteur v = (Vecteur) o;
		//notre vecteur c this et V
		boolean x =  (this.getB().getX() - this.getA().getX()) == (v.getB().getX() - v.getA().getX()) ;
		boolean y = (this.getB().getY() - this.getA().getY()) == (v.getB().getY() - v.getA().getY());
		return x && y;
	}
}
