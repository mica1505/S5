package miniProjet.labyrinthe;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

import miniProjet.labyrinthe.WeightedGraph.Edge;
import miniProjet.labyrinthe.WeightedGraph.Graph;
import miniProjet.labyrinthe.WeightedGraph.Vertex;

public class Resolution {
	public static void main(String[] args) {
		//Lecture de la carte et creation du graphe
		  Labyrinthe lab = initLab();
		  /*for(Vertex v: lab.graph.vertexlist) {
			  for(Edge e : v.adjacencylist) {
				  System.out.println(e.source +"->"+ e.destination + " "+e.weight);
			  }
		  }*/
	      LinkedList<Integer> path = null;
	      System.out.println(lab.run_instance());
	      //path = Algorithme.AStar(lab, lab.start, lab.end, lab.ncols,lab.nlines*lab.ncols);
	      //�criture du chemin dans un fichier de sortie
	      /*try {
		      File file = new File("out.txt");
		      if (!file.exists()) {
		    	  file.createNewFile();
		      } 
		      FileWriter fw = new FileWriter(file.getAbsoluteFile());
		      BufferedWriter bw = new BufferedWriter(fw);
		      
		      for (int i: path)
		      {
		    	  bw.write(String.valueOf(i));
		    	  bw.write('\n');
		      }
		      bw.close();	
	      
		}catch (IOException e) {
			e.printStackTrace();
		}*/
	}
	
	public static Labyrinthe initLab() {
		Labyrinthe lab=null;
		try {
			//TODO: obtenir le fichier qui decrit la carte
		      File myObj = new File("C:\\Users\\pc\\Documents\\L3\\S5\\Algo\\Partie2\\miniProjet\\src\\labyrinthe.txt");
		      Scanner myReader = new Scanner(myObj);
		      String data = "";
		      
		      //on lit le nombre de labyrinthe qu'on veut resoudre
		      data = myReader.nextLine();
		      System.out.println(data);
		      //Lecture du nombre de lignes
		      data = myReader.nextLine();
		      int nlines = Integer.parseInt(data);
		      System.out.println(data);
		      //Et du nombre de colonnes
		      data = myReader.nextLine();
		      System.out.println(data);
		      int ncols = Integer.parseInt(data);
		      
		      
		      
		      //Initialisation du graphe
		      Graph graph = new Graph();
		      char [][] grille = new char[nlines][ncols];
		      int start=0,end=0,fire=0;
		      //Lire les differents types de cases 
		      
		      //On ajoute les sommets dans le graphe (avec le bon type)
		      for (int line=0; line < nlines; line++)
		      {
		    	  data = myReader.nextLine();
		    	  //System.out.println(data);
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  //System.out.println(data.charAt(col));
		    		  /*ON AJOUTE LE SOMMET AU GRAPHE*/
		    		  if(Character.valueOf(data.charAt(col)) == 'D') {
		    			  start = line*ncols+col;
		    			  System.out.println("START : "+start);
		    		  }
		    		  if(Character.valueOf(data.charAt(col))=='S') {
		    			  end = line*ncols+col;
		    			  System.out.println("END : "+end);
		    		  }
		    		  if(Character.valueOf(data.charAt(col))=='F') {
		    			  fire = line*ncols+col;
		    			  System.out.println("Fire : "+fire);
		    		  }
		    		  grille[line][col] = Character.valueOf(data.charAt(col));
		    		  graph.addVertex(Character.valueOf(data.charAt(col)));
		    	  }
		      }
		      lab = new Labyrinthe(graph,grille,start,end,nlines,ncols,fire);
		      
		      System.out.println(lab);
		      
		      //TODO: ajouter les arretes
		      for (int line=0; line < nlines; line++)
		      {
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  int sommetSource = line*ncols +col;
		    		  double poidSource = graph.vertexlist.get(sommetSource).indivTime;
		    		  if(line<nlines-1) {//bas
		    			  lab.graph.addEgde(sommetSource, (line+1)*ncols+col, (poidSource+graph.vertexlist.get((line+1)*ncols+col).indivTime)/2);//en bas
		    		  }
		    		  if(line >0){//HAUT //hadi ziada le resultat reste le meme 
		    			  lab.graph.addEgde(sommetSource, (line-1)*ncols+col, (poidSource+graph.vertexlist.get((line-1)*ncols+col).indivTime)/2);//en haut
		    		  }
		    		  if(col<ncols-1) { //droite 
		    			  lab.graph.addEgde(sommetSource, line*ncols+col+1,(poidSource+graph.vertexlist.get(line*ncols+col+1).indivTime)/2);//a droite
		    		  }
		    		  if(col>0) { //la gauche 
		    			  lab.graph.addEgde(sommetSource, line*ncols+col-1, (poidSource+graph.vertexlist.get(line*ncols+col-1).indivTime)/2);//a gauche
		    		  }
		    	  }
		      }
		      myReader.close();
		      return lab;
		    } catch (FileNotFoundException e) {
		      System.out.println("File not found");
		      e.printStackTrace();
		    }
		return null;
	}
}
