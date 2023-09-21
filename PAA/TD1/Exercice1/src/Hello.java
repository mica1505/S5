import java.util.Scanner;

public class Hello{
    public static void main(String args[]){
        //Scanner 
        System.out.println("chaud cacao");
        System.out.println("Passe ton nom");
        Scanner nom = new Scanner(System.in);
        String ton_nom = nom.next();
        System.out.println("Hello "+ton_nom+"! Comment ca va?");

        //Passage de parametres
        if(args.length == 3){
            String param1,param2,param3;
            param1 = args[0];
            param2 = args[1];
            param3 = args[2];
            System.out.println("1 : "+param1+" \n"+"2 : "+param2+" \n"+"3 : "+param3+" \n");
        }
        else{
            System.out.println("Il manque un parametre");
        }
        System.out.println(args[0]);
    }
}