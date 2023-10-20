package up.mi.cm.td2;

public class Point {
	
	private double x,y;
	
	public Point(double x,double y) {
		this.x = x;
		this.y = y;
	}
	
	public double getX() {
		return this.x;
	}
	
	public double getY() {
		return this.y;
	}
	
	public double Distance(Point p) {
		double x = p.getX() - this.getX();
		double y = p.getY()  - this.getY();
		return Math.sqrt((x*x)+(y*y));
	}
	
	public Point translation(Vecteur v) {
		return this;
	}
}
