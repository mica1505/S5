package up.mi.cm.td1;

import java.util.Scanner;

public class InterfaceUtilMath{
    public static void main(String [] args){
        
        boolean quit = false;
        while(!quit) {
        	System.out.println("Veuiller choisir une opération a effectuer : \n S :  Addition de trois entiers. \n F : Factorielle d'un entier. \n P : Puissance m-eme d'un entier. \n Q : Quitter.");
        	Scanner inputChoice = new Scanner(System.in);
            switch(inputChoice.next().toUpperCase()) {
                case "S" : 
                	int a,b,c;
                	System.out.println("Entrez le premier entier : ");
                	Scanner s = new Scanner(System.in);
                	a = s.nextInt();
                	System.out.println("Entrez le deuxieme entier : ");
                	b = s.nextInt();   
                	System.out.println("Entrez le troisieme entier : ");
                	c = s.nextInt(); 
                	System.out.println("La somme de ces trois entiers est : "+UtilMath.somme3(a,b,c));
                	//s.close();
                	break;
                case "F" :
                	int f;
                	System.out.println("Entrez un entier : ");
                	Scanner sf = new Scanner(System.in);
                	f = sf.nextInt();
                	System.out.println("Resultat : "+ UtilMath.fact(f));
                	//sf.close();
                	break;
                case "P" :
                	int m,n;
                	System.out.println("Entrez le premier entier : ");
                	Scanner sp = new Scanner(System.in);
                	m = sp.nextInt();
                	System.out.println("Entrez le deuxieme entier : ");
                	n = sp.nextInt();
                	System.out.println("Resultat : "+ UtilMath.puissance(m, n));
                	break;
                case "Q":
                	quit = true;
                	inputChoice.close();
                	break;
                
            }
        }
        

    }
}
