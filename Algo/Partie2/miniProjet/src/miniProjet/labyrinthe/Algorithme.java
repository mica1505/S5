// Par Sylvain Lobry, pour le cours "IF05X040 Algorithmique avancee"
// de l'Universite de Paris, 11/2020

package miniProjet.labyrinthe;
import java.util.HashSet;
import java.util.LinkedList;

import miniProjet.labyrinthe.WeightedGraph.Graph;
import miniProjet.labyrinthe.WeightedGraph.Vertex;



//Classe principale. C'est ici que vous devez faire les modifications
public class Algorithme {
	
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
	public static LinkedList<Integer> AStar(Labyrinthe lab, int start, int end, int ncols, int numberV)
	{
		lab.graph.vertexlist.get(start).timeFromSource=0;
		int number_tries = 0;
		
		//TODO: mettre tous les noeuds du graphe dans la liste des noeuds a visiter: DONE
		HashSet<Integer> to_visit = new HashSet<Integer>();
		for(Vertex v : lab.graph.vertexlist) {
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
		for(int index = 0;index<lab.graph.vertexlist.size();index++) {
			xCurrent = index/ncols;
			yCurrent =  index%ncols;
			lab.graph.vertexlist.get(index).heuristic = Math.abs(xCurrent-xEnd)+Math.abs(yCurrent-yEnd);
		}
		while (to_visit.contains(end))
		{
			//TODO: trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
			//      (graph.vertexlist.get(v).timeFromSource + heuristic) minimale. : DONE
			/*SOMMET COURANT*/
			Integer min_v = 0;
			Double distanceTemporaireMinimale = Double.POSITIVE_INFINITY; 
			for(Integer v: to_visit) {
				if(distanceTemporaireMinimale>=lab.graph.vertexlist.get(v).timeFromSource + lab.graph.vertexlist.get(v).heuristic) {
					min_v = v;
					//System.out.println("---------"+min_v);
					distanceTemporaireMinimale=lab.graph.vertexlist.get(v).timeFromSource + lab.graph.vertexlist.get(v).heuristic;
				}
			}
			//On l'enleve des noeuds a visiter
			to_visit.remove(min_v);
			number_tries += 1;
			
			//TODO: pour tous ses voisins, on verifie si on est plus rapide en passant par ce noeud. : DONE
			for (int i = 0; i < lab.graph.vertexlist.get(min_v).adjacencylist.size(); i++)
			{
				int to_try = lab.graph.vertexlist.get(min_v).adjacencylist.get(i).destination;
				//si il peut bouger et que le sommet voisin n'est pas un feu : 
				if(lab.can_move(min_v%ncols,min_v/ncols)>0 && lab.graph.vertexlist.get(to_try).type!='F'){
					//System.out.println(min_v+"->"+to_try+" : "+lab.can_move(min_v%ncols,min_v/ncols));
					if(lab.graph.vertexlist.get(min_v).adjacencylist.get(i).weight 
							+ 
						lab.graph.vertexlist.get(min_v).timeFromSource
							< 
						lab.graph.vertexlist.get(to_try).timeFromSource) 
					{
						lab.graph.vertexlist.get(to_try).timeFromSource = lab.graph.vertexlist.get(min_v).adjacencylist.get(i).weight + lab.graph.vertexlist.get(min_v).timeFromSource;
						lab.graph.vertexlist.get(to_try).prev = lab.graph.vertexlist.get(min_v);
					}
				}
				//A completer
			}	            
		}
		
		System.out.println("Done! Using A*:");
		System.out.println("	Number of nodes explored: " + number_tries);
		System.out.println("	Total time of the path: " + lab.graph.vertexlist.get(end).timeFromSource);
		LinkedList<Integer> path=new LinkedList<Integer>();
		path.addFirst(end);
		//TODO: remplir la liste path avec le chemin : DONE
		Vertex tmp = lab.graph.vertexlist.get(end);
		for(Vertex pere = tmp.prev;pere!=null;pere = pere.prev) {
				//System.out.println("path : "+pere.num);
				path.addFirst(pere.num);
		}
		for(int n: path) {
			System.out.print(n+" ");
		}
		System.out.println("\n");
		/*for(Vertex v : lab.graph.vertexlist) {
			System.out.print("--"+v.num+": "+v.timeFromSource);
		}*/
		return path;
	}
}
