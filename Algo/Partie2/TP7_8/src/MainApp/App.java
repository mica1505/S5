// Par Sylvain Lobry, pour le cours "IF05X040 Algorithmique avancee"
// de l'Universite de Paris, 11/2020

package MainApp;

import MainApp.WeightedGraph.Edge;
import MainApp.WeightedGraph.Graph;
import MainApp.WeightedGraph.Vertex;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.HashSet;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.RenderingHints;
import javax.swing.JComponent;
import javax.swing.JFrame;


//Classe pour gerer l'affichage
class Board extends JComponent 
{
	private static final long serialVersionUID = 1L;
	Graph graph;
	int pixelSize;
	int ncols;
	int nlines;
	HashMap<Integer, String> colors;
	int start;
	int end;
	double max_distance;
	int current;
	LinkedList<Integer> path;
	
    public Board(Graph graph, int pixelSize, int ncols, int nlines, HashMap<Integer, String> colors, int start, int end)
    {
        super();
        this.graph = graph;
        this.pixelSize = pixelSize;
        this.ncols = ncols;
        this.nlines = nlines;
        this.colors = colors;
        this.start = start;
        this.end = end;
        this.max_distance = ncols * nlines;
        this.current = -1;
        this.path = null;
    }
    
    //Mise � jour de l'affichage
	public void paint(Graphics g) 
	{
		Graphics2D g2 = (Graphics2D) g;
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
				        	RenderingHints.VALUE_ANTIALIAS_ON);
		//Ugly clear of the frame
		g2.setColor(Color.cyan);
		g2.fill(new Rectangle2D.Double(0,0,this.ncols*this.pixelSize, this.nlines*this.pixelSize));
		
		
		int num_case = 0;
		for (WeightedGraph.Vertex v : this.graph.vertexlist)
		{
			double type = v.indivTime;
			int i = num_case / this.ncols;
			int j = num_case % this.ncols;

			if (colors.get((int)type).equals("green"))
				g2.setPaint(Color.green);
			if (colors.get((int)type).equals("gray"))
				g2.setPaint(Color.gray);
			if (colors.get((int)type).equals("blue"))
				g2.setPaint(Color.blue);
			if (colors.get((int)type).equals("yellow"))
				g2.setPaint(Color.yellow);
			g2.fill(new Rectangle2D.Double(j*this.pixelSize, i*this.pixelSize, this.pixelSize, this.pixelSize));
			
			if (num_case == this.current)
			{
				g2.setPaint(Color.red);
				g2.draw(new Ellipse2D.Double(j*this.pixelSize+this.pixelSize/2, i*this.pixelSize+this.pixelSize/2, 6, 6));
			}
			if (num_case == this.start)
			{
				g2.setPaint(Color.white);
				g2.fill(new Ellipse2D.Double(j*this.pixelSize+this.pixelSize/2, i*this.pixelSize+this.pixelSize/2, 4, 4));
				
			}
			if (num_case == this.end)
			{
				g2.setPaint(Color.black);
				g2.fill(new Ellipse2D.Double(j*this.pixelSize+this.pixelSize/2, i*this.pixelSize+this.pixelSize/2, 4, 4));
			}
			
			num_case += 1;
		}
		
		num_case = 0;
		for (WeightedGraph.Vertex v : this.graph.vertexlist)
		{
			int i = num_case / this.ncols;
			int j = num_case % this.ncols;
			if (v.timeFromSource < Double.POSITIVE_INFINITY)
			{
				float g_value = (float) (1 - v.timeFromSource / this.max_distance);
				if (g_value < 0)
					g_value = 0;
				g2.setPaint(new Color(g_value, g_value, g_value));
				g2.fill(new Ellipse2D.Double(j*this.pixelSize+this.pixelSize/2, i*this.pixelSize+this.pixelSize/2, 4, 4));
				WeightedGraph.Vertex previous = v.prev;
				if (previous != null)
				{
					int i2 = previous.num / this.ncols;
					int j2 = previous.num % this.ncols;
					g2.setPaint(Color.black);
					g2.draw(new Line2D.Double(j * this.pixelSize + this.pixelSize/2, i * this.pixelSize + this.pixelSize/2, j2 * this.pixelSize + this.pixelSize/2, i2 * this.pixelSize + this.pixelSize/2));
				}
			}
				
			num_case += 1;
		}
		
		int prev = -1;
		if (this.path != null)
		{
			g2.setStroke(new BasicStroke(3.0f));
			for (int cur : this.path)
			{
				if (prev != -1)
				{
					g2.setPaint(Color.red);
					int i = prev / this.ncols;
					int j = prev % this.ncols;
					int i2 = cur / this.ncols;
					int j2 = cur % this.ncols;
					g2.draw(new Line2D.Double(j * this.pixelSize + this.pixelSize/2, i * this.pixelSize + this.pixelSize/2, j2 * this.pixelSize + this.pixelSize/2, i2 * this.pixelSize + this.pixelSize/2));
				}
				prev = cur;
			}
		}
	}
	
	//Mise � jour du graphe (� appeler avant de mettre � jour l'affichage)
	public void update(Graph graph, int current)
	{
		this.graph = graph;
		this.current = current;
		repaint();
	}
	
	//Indiquer le chemin (pour affichage)
	public void addPath(Graph graph, LinkedList<Integer> path)
	{
		this.graph = graph;
		this.path = path;
		this.current = -1;
		repaint();
	}
}

//Classe principale. C'est ici que vous devez faire les modifications
public class App {
	
	//Initialise l'affichage
	private static void drawBoard(Board board, int nlines, int ncols, int pixelSize)
	{
	    JFrame window = new JFrame("Plus court chemin");
	    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    window.setBounds(0, 0, ncols*pixelSize+20, nlines*pixelSize+40);
	    window.getContentPane().add(board);
	    window.setVisible(true);
	}
	
	//Methode A*
	//graph: le graphe representant la carte
	//start: un entier representant la case de depart
	//       (entier unique correspondant a la case obtenue dans le sens de la lecture)
	//end: un entier representant la case d'arriv�e
	//       (entier unique correspondant � la case obtenue dans le sens de la lecture)
	//ncols: le nombre de colonnes dans la carte
	//numberV: le nombre de cases dans la carte
	//board: l'affichage
	//retourne une liste d'entiers correspondant au chemin.
	private static LinkedList<Integer> AStar(Graph graph, int start, int end, int ncols, int numberV, Board board)
	{
		graph.vertexlist.get(start).timeFromSource=0;
		int number_tries = 0;
		
		//TODO: mettre tous les noeuds du graphe dans la liste des noeuds a visiter: DONE
		HashSet<Integer> to_visit = new HashSet<Integer>();
		for(Vertex v : graph.vertexlist) {
			to_visit.add(v.num);
		}
		//TODO: Remplir l'attribut graph.vertexlist.get(v).heuristic pour tous les noeuds v du graphe:
		int xEnd,yEnd,xCurrent,yCurrent;
		
		/*
		 * ON RECUPERE LES COORDONNEES DU SOMMET D'ARRIVEE
		*/
		xEnd = end/ncols;
		yEnd = end%ncols;

		/*
		 * ON RECUPERE LES COORDONNEES DE CHAQUE SOMMET
		 * ON CALCULE L'HEURESTIQUE DE CHAQUE SOMMET EN CALCULANT LA DISTANCE EUCLEDIENNE ENTRE LE SOMMET COURANT ET LE SOMMET D'ARRIVEE
		 * CAR UN SOMMET A 8 VOISINS 
		*/
		for(int index = 0;index<graph.vertexlist.size();index++) {
			xCurrent = index/ncols;
			yCurrent =  index%ncols;
			graph.vertexlist.get(index).heuristic = Math.sqrt(Math.pow(Math.abs(xCurrent-xEnd),2)+Math.pow(Math.abs(yCurrent-yEnd),2));
		}
		while (to_visit.contains(end))
		{
			//TODO: trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
			//      (graph.vertexlist.get(v).timeFromSource + heuristic) minimale. : DONE
			/*SOMMET COURANT*/
			Integer min_v = 0;
			Double distanceTemporaireMinimale = Double.POSITIVE_INFINITY; 
			for(Integer v: to_visit) {
				if(distanceTemporaireMinimale>=graph.vertexlist.get(v).timeFromSource + graph.vertexlist.get(v).heuristic) {
					min_v = v;
					distanceTemporaireMinimale=graph.vertexlist.get(v).timeFromSource + graph.vertexlist.get(v).heuristic;
				}
			}
			//On l'enleve des noeuds a visiter
			to_visit.remove(min_v);
			number_tries += 1;
			
			//TODO: pour tous ses voisins, on verifie si on est plus rapide en passant par ce noeud. : DONE
			for (int i = 0; i < graph.vertexlist.get(min_v).adjacencylist.size(); i++)
			{
				int to_try = graph.vertexlist.get(min_v).adjacencylist.get(i).destination;
				if(graph.vertexlist.get(min_v).adjacencylist.get(i).weight 
						+ 
					graph.vertexlist.get(min_v).timeFromSource
						< 
					graph.vertexlist.get(to_try).timeFromSource) 
				{
					graph.vertexlist.get(to_try).timeFromSource = graph.vertexlist.get(min_v).adjacencylist.get(i).weight + graph.vertexlist.get(min_v).timeFromSource;
					graph.vertexlist.get(to_try).prev = graph.vertexlist.get(min_v);
				}
				//A completer
			}
			//On met a jour l'affichage
			try {
	    	    board.update(graph, min_v);
	    	    Thread.sleep(10);
	    	} catch(InterruptedException e) {
	    	    System.out.println("stop");
	    	}
	            
		}
		
		System.out.println("Done! Using A*:");
		System.out.println("	Number of nodes explored: " + number_tries);
		System.out.println("	Total time of the path: " + graph.vertexlist.get(end).timeFromSource);
		LinkedList<Integer> path=new LinkedList<Integer>();
		path.addFirst(end);
		//TODO: remplir la liste path avec le chemin : DONE
		Vertex tmp = graph.vertexlist.get(end);
		for(Vertex pere = tmp.prev;pere!=null;pere = pere.prev) {
				path.addFirst(pere.num);
		}
		board.addPath(graph, path);
		return path;
	}

	//Methode Dijkstra
	//graph: le graphe representant la carte
	//start: un entier representant la case de depart
	//       (entier unique correspondant a la case obtenue dans le sens de la lecture)
	//end: un entier representant la case d'arrivee
	//       (entier unique correspondant a la case obtenue dans le sens de la lecture)
	//numberV: le nombre de cases dans la carte
	//board: l'affichage
	//retourne une liste d'entiers correspondant au chemin.
	private static LinkedList<Integer> Dijkstra(Graph graph, int start, int end, int numberV, Board board)
	{	/*on recup l'entree et on met sa distance a 0*/
		graph.vertexlist.get(start).timeFromSource=0;
		int number_tries = 0;
		
		//TODO: mettre tous les noeuds du graphe dans la liste des noeuds a  visiter: DONE
		HashSet<Integer> to_visit = new HashSet<Integer>();
		for(Vertex v : graph.vertexlist) {
			to_visit.add(v.num);
		}
		/*TANT  QUE LA SORTIE N'A PAS ETE VISITE*/
		while (to_visit.contains(end))
		{
			//TODO: trouver le noeud min_v/courant parmis tous les noeuds v ayant la distance temporaire
			//      graph.vertexlist.get(v).timeFromSource minimale. : DONE
			/*SOMMET COURANT*/
			Integer min_v = 0;
			Double distanceTemporaireMinimale = Double.POSITIVE_INFINITY;
			for(Integer v: to_visit) {
				if(distanceTemporaireMinimale>=graph.vertexlist.get(v).timeFromSource) {
					min_v = v;
					distanceTemporaireMinimale=graph.vertexlist.get(v).timeFromSource;
				}
			}
			//On l'enleve des noeuds  visiter
			//get vertex with min dist
			to_visit.remove(min_v);
			number_tries += 1;
			
			//TODO: pour tous ses voisins, on verifie si on est plus rapide en passant par ce noeud. : DONE
			
			/*ON BOUCLE SUR LES VOISINS DU SOMMET COURANT*/
			for (int i = 0; i < graph.vertexlist.get(min_v).adjacencylist.size(); i++)
			{
				/*SOMMET VOISIN DE MIN_V/COURANT*/
				int to_try = graph.vertexlist.get(min_v).adjacencylist.get(i).destination;
				/*On regarde pour ses voisins si la distance en passant par le noeud courant 
				 * (donc distance temporaire plus distance du noeud courant au voisin(weight)) 
				 * est plus petite que la distance temporaire
				*/
				if(graph.vertexlist.get(min_v).adjacencylist.get(i).weight 
						+ 
					graph.vertexlist.get(min_v).timeFromSource
						< 
					graph.vertexlist.get(to_try).timeFromSource) 
				{
					/*Si tel est le cas, on mets à jour la distance temporaire*/
					graph.vertexlist.get(to_try).timeFromSource = graph.vertexlist.get(min_v).adjacencylist.get(i).weight + graph.vertexlist.get(min_v).timeFromSource;
					/*on enregistre le noeud courant comme noeud parent du voisin dans le chemin*/
					graph.vertexlist.get(to_try).prev = graph.vertexlist.get(min_v);
				}
				//A completer
			}
			//On met a jour l'affichage
			try {
	    	    board.update(graph, min_v);
	    	    Thread.sleep(10);
	    	} catch(InterruptedException e) {
	    	    System.out.println("stop");
	    	}
	            
		}
		
		System.out.println("Done! Using Dijkstra:");
		System.out.println("	Number of nodes explored: " + number_tries);
		System.out.println("	Total time of the path: " + graph.vertexlist.get(end).timeFromSource);
		LinkedList<Integer> path=new LinkedList<Integer>();
		path.addFirst(end);
		//TODO: remplir la liste path avec le chemin : DONE
		Vertex tmp = graph.vertexlist.get(end);
		for(Vertex pere = tmp.prev;pere!=null;pere = pere.prev) {
			//faut check avc des tests
				path.addFirst(pere.num);
		}
		board.addPath(graph, path);
		return path;
	}
	
	//Methode principale
	public static void main(String[] args) {
		//Lecture de la carte et creation du graphe
		try {
			//TODO: obtenir le fichier qui decrit la carte
		      File myObj = new File("C:\\Users\\pc\\Documents\\L3\\S5\\Algo\\Partie2\\TP7_8\\src\\graph.txt");
		      Scanner myReader = new Scanner(myObj);
		      String data = "";
		      //On ignore les deux premieres lignes
		      /*
		       * ==Metadata==
			   * =Size=
		       */
		      for (int i=0; i < 3; i++) {
		    	  data = myReader.nextLine();
		      }
		      
		      //Lecture du nombre de lignes
		      int nlines = Integer.parseInt(data.split("=")[1]);
		      //Et du nombre de colonnes
		      data = myReader.nextLine();
		      int ncols = Integer.parseInt(data.split("=")[1]);
		      
		      //Initialisation du graphe
		      Graph graph = new Graph();
		      /*HASHAMP DES NOMS DE SOMMETS ET LEUR TEMPS*/
		      HashMap<String, Integer> groundTypes = new HashMap<String, Integer>();
		      /*HASHAMP DES TEMPS ET DE SA COULEUR ASSOCIEE*/
		      HashMap<Integer, String> groundColor = new HashMap<Integer, String>();
		      /*ON IGNORE LA LIGNE =Types=*/
		      data = myReader.nextLine();
		      /*ON LIT LE PREMIER TYPE DE CASE*/
		      data = myReader.nextLine();
		      //Lire les differents types de cases
		      while (!data.equals("==Graph=="))
		      {	  /*ON LIT LE PREMIER TYPE DE CASE*/
		    	  /*NOM DU SOMMET*/
		    	  String name = data.split("=")[0];
		    	  /*POID/TEMPS DE L"ARETE*/
		    	  int time = Integer.parseInt(data.split("=")[1]);
		    	  /*TYPE DE COULEUR*/
		    	  data = myReader.nextLine();
		    	  String color = data;
		    	  /*ON MET LES TYPES DE SOMMET ET LEUR TEMPS DANS UN SET*/
		    	  groundTypes.put(name, time);
		    	  groundColor.put(time, color);
		    	  data = myReader.nextLine();
		      }
		      
		      //On ajoute les sommets dans le graphe (avec le bon type)
		      for (int line=0; line < nlines; line++)
		      {
		    	  data = myReader.nextLine();
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  /*ON AJOUTE LE SOMMET AU GRAPHE*/
		    		  graph.addVertex(groundTypes.get(String.valueOf(data.charAt(col))));
		    	  }
		      }
		      
		      //TODO: ajouter les arretes
		      for (int line=0; line < nlines; line++)
		      {
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  int sommetSource = line*ncols +col;
		    		  double poidSource = graph.vertexlist.get(sommetSource).indivTime;
		    		  if(col<ncols-1) { //droite 
		    			  graph.addEgde(sommetSource, line*ncols+col+1,(poidSource+graph.vertexlist.get(line*ncols+col+1).indivTime)/2);//a droite
		    		  }
		    		  if(col>0) { //la gauche 
		    			  graph.addEgde(sommetSource, line*ncols+col-1, (poidSource+graph.vertexlist.get(line*ncols+col-1).indivTime)/2);//a gauche
		    		  }
		    		  if(line >0){//HAUT //hadi ziada le resultat reste le meme 
		    			  graph.addEgde(sommetSource, (line-1)*ncols+col, (poidSource+graph.vertexlist.get((line-1)*ncols+col).indivTime)/2);//en haut
		    		  }
		    		  if(line<nlines-1) {//bas
		    			  graph.addEgde(sommetSource, (line+1)*ncols+col, (poidSource+graph.vertexlist.get((line+1)*ncols+col).indivTime)/2);//en bas
		    		  }
		    		  if(line>0 && col<ncols-1) { //diag droite haut
		    			  graph.addEgde(sommetSource, (line-1)*ncols+col+1, (poidSource+graph.vertexlist.get((line-1)*ncols+col+1).indivTime)/2);//diag droite haut
		    		  }
		    		  if(line<nlines-1 && col<ncols-1) { //diag droite bas
		    			  graph.addEgde(sommetSource, (line+1)*ncols+col+1, (poidSource+graph.vertexlist.get((line+1)*ncols+col+1).indivTime)/2);//diag droite bas
		    		  }
		    		  if(line>0 && col>0) { //diag gauche haut
		    			  graph.addEgde(sommetSource, (line-1)*ncols+col-1, (poidSource+graph.vertexlist.get((line-1)*ncols+col-1).indivTime)/2);//diag gauche haut
		    		  }
		    		  if(line<nlines-1 && col>0) { //diag gauche bas
		    			  graph.addEgde(sommetSource, (line+1)*ncols+col-1, (poidSource+graph.vertexlist.get((line+1)*ncols+col-1).indivTime)/2);//diag gauche bas
		    		  }
		    	  }
		      }
		      
		      //On obtient les noeuds de depart et d'arrive
		      data = myReader.nextLine();
		      data = myReader.nextLine();
		      int startV = Integer.parseInt(data.split("=")[1].split(",")[0]) * ncols + Integer.parseInt(data.split("=")[1].split(",")[1]);
		      data = myReader.nextLine();
		      int endV = Integer.parseInt(data.split("=")[1].split(",")[0]) * ncols + Integer.parseInt(data.split("=")[1].split(",")[1]);

		      myReader.close();
		      
		      //A changer pour avoir un affichage plus ou moins grand
		      int pixelSize = 10;
		      Board board = new Board(graph, pixelSize, ncols, nlines, groundColor, startV, endV);
		      drawBoard(board, nlines, ncols, pixelSize);
		      board.repaint();
		      
		      try {
		    	    Thread.sleep(100);
		    	} catch(InterruptedException e) {
		    	    System.out.println("stop");
		    	}
		      
		      //On appelle Dijkstra
		      LinkedList<Integer> path = null;
		      //TODO: laisser le choix entre Dijkstra et A*
		      System.out.println("Vous voulez resoudre le probleme en utilisant : \n1)Dijkstra.\n2)Astar");
		      Scanner sc = new Scanner(System.in);
		      int choix = sc.nextInt();
		      if(choix == 1) {
		    	  path = Dijkstra(graph, startV,endV,nlines*ncols, board);
		      }
		      if(choix == 2) {
		    	  path = AStar(graph, startV, endV, ncols,nlines*ncols, board);
		      }
		      sc.close();
		      //�criture du chemin dans un fichier de sortie
		      try {
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
		      
			} catch (IOException e) {
				e.printStackTrace();
			  } 
		    } catch (FileNotFoundException e) {
		      System.out.println("An error occurred.");
		      e.printStackTrace();
		    }
	}

}
