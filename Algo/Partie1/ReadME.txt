ReadMe
===
## TP0

Commande pour lancer le programme sur les listes chainées : 
```
gcc listeChainees.c
.\a.exe
```
Commande pour lancer le programme sur les arbres : 
```
gcc arbres.c
.\a.exe
```

* Les listes chainees et les arbres étants créés dans le main, on n'a pas besoin d'entrées clavier.

## TP1

Commande pour lancer le programme sur les graphes : 
```
gcc graphe.c
.\a.exe
```

* Les entrées claviers pour générer le graphe : 

```
8
11
0 1
0 2
1 4
1 2
1 3
2 5
4 6
6 7
7 5
3 6
3 7
```

## TP2
Commande pour lancer le programme sur le plus court chemin : 
```
gcc cheminGraphe.c
.\a.exe
```
* Les entrées claviers pour générer le graphe : 

```
8
11
0 1
0 2
1 4
1 2
1 3
2 5
4 6
6 7
7 5
3 6
3 7
```
## TP3
Commande pour lancer le programme sur les arbres : 
```
gcc arbres.c
.\a.exe
```

* Les entrées claviers pour générer l'arbre : 
```
1
1
1
1
0
0
1
0
---------------------------------------------
Est-ce que le noeud 'a' a des fils ? (0 : non/1 : oui) 1

Est-ce que le noeud 'a' a un fils gauche ? (0 : non/1 : oui) 1

Est-ce que le noeud 'b' a des fils ? (0 : non/1 : oui) 1

Est-ce que le noeud 'b' a un fils gauche ? (0 : non/1 : oui) 1

Est-ce que le noeud 'c' a des fils ? (0 : non/1 : oui) 0

Est-ce que le noeud 'b' a un fils droit ? (0 : non/1 : oui) 0

Est-ce que le noeud 'a' a un fils droit ? (0 : non/1 : oui) 1

Est-ce que le noeud 'd' a des fils ? (0 : non/1 : oui) 0

Pacrour prefixe : a  b  c  d 
Pacrour infixe :  c  b  a  d 
Pacrour suffixe :  c  b  d  a 
```

## TP4

Commande pour lancer l'algorithme de prim : 
```
gcc prim.c
.\a.exe
```

* Entrées claviers : 
```
8
11
0 1 3
0 2 1
1 4 5
1 2 4
1 3 3
2 5 2
4 6 4
6 7 1
7 5 6
3 6 2
3 7 3
```

Commande pour lancer l'algorithme de kruskal : 
```
gcc kruskal.c
.\a.exe
```

* Entrées claviers : 
```
0 1 3
0 2 1
1 4 5
1 2 4
1 3 3
2 5 2
4 6 4
6 7 1
7 5 6
3 6 2
3 7 3
```

## TP5 
Commande pour lancer l'algorithme de coloration de graphe : 
```
gcc chatGPTGraphe.c
.\a.exe
```

* Le graphe étant créé dans le main, on n'a pas besoin d'entrées clavier.
-------------------------------------------------------
NB : les exemples d'éxcécution de chaque fichier sont presents dans le rapport.
-------------------------------------------------------