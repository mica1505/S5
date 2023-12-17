#include <stdio.h>
#include <stdlib.h>


int burn_around(int x, int y, int N, int M, char map[N][M]) {
  //retourne 1 si gameover
  //'A' pour éviter que les flammes soient propagées le même tour où elles sont crées
  if (y != 0) {
    if (map[y-1][x] == '.') map[y-1][x] = 'A';//si c'est un mur on l'enflemme
    else if (map[y-1][x] == 'S' || map[y-1][x] == 'D') return 1;
  }
  if (x != 0) {
    if (map[y][x-1] == '.') map[y][x-1] = 'A';
    else if (map[y][x-1] == 'S' || map[y][x-1] == 'D') return 1;
  }
  if (y != N-1) {
    if (map[y+1][x] == '.') map[y+1][x] = 'A';
    else if (map[y+1][x] == 'S' || map[y+1][x] == 'D') return 1;
  }
  if (x != M-1) {
    if (map[y][x+1] == '.') map[y][x+1] = 'A';
    else if (map[y][x+1] == 'S' || map[y][x+1] == 'D') return 1;
  }
  //retourne zero => on a proparge le feu
  return 0;
}
//top bottom left right
int can_move_dir(int x, int y, char dir, int N, int M, char map[N][M]) {
    //peut biuger ssi c'est un chemin (pas un feu ni un mur)
  if (dir == 'T') return y != 0 && map[y-1][x] == '.';
  else if (dir == 'B') return y != N-1 && map[y+1][x] == '.';
  else if (dir == 'L') return x != 0 && map[y][x-1] == '.';
  else if (dir == 'R') return x != M-1 && map[y][x+1] == '.';
  else return 0;
}

int can_move(int x, int y, int N, int M, char map[N][M]) {
  //retourne nombre de directions possibles
  int top = can_move_dir(x, y, 'T', N, M, map);
  int bottom = can_move_dir(x, y, 'B', N, M, map);
  int left = can_move_dir(x, y, 'L', N, M, map);
  int right = can_move_dir(x, y, 'R', N, M, map);
  return top + left + right + bottom;
}

int win_move(int x, int y, int N, int M, char map[N][M]) {
  //retourne le nombre de directions possibles vers la sortie
  int top = (y != 0 && map[y-1][x] == 'S');
  int bottom = (y != N-1 && map[y+1][x] == 'S');
  int left = (x != 0 && map[y][x-1] == 'S');
  int right = (x != M-1 && map[y][x+1] == 'S');
  return top || left || right || bottom;
}

int move_prisoner(int N, int M, char map[N][M]) {
  //retourne 1 si victoire
  //L signifie que le prisonnier est déjà passé par cette case
  //contient les coordonnees du risonnier
  int prisoner_position[2];
  //contient les coordonnees de la sortie
  int exit_position[2];

  for (int j = 0; j < N; j++) {
    for (int k = 0; k < M; k++) {
      if (map[j][k] == 'S') {
        exit_position[0] = k;
        exit_position[1] = j;
      }
      else if (map[j][k] == 'D') {
        prisoner_position[0] = k;
        prisoner_position[1] = j;
      }
    }
  }
  //printf("%d %d %d %d \n",exit_position[0],exit_position[1],prisoner_position[0],prisoner_position[1]);
    //distance entre le priosonnier et la sortie
  int delta_x = prisoner_position[0] - exit_position[0];//ligne
  int delta_y = prisoner_position[1] - exit_position[1];//collone
  //on verifie si le prisonnier est juste a cote de la sortie
  //inverser le slignes et les colonnes
  int win = win_move(prisoner_position[0], prisoner_position[1], N, M, map);
  //printf("----%d\n",win);
  if (win) {
    //printf("\nWIN\n");
    return 2;//si la sortie est juste a cote
  }
  else {
    //printf("\nJ'AVANCE\n");
    int nb_move = can_move(prisoner_position[0], prisoner_position[1], N, M, map);
    if (nb_move > 0) {
        //on recupere la pose initiale du prisonnier
      int x = prisoner_position[0];//ligne
      int y = prisoner_position[1];//colonne
      int top = can_move_dir(x, y, 'T', N, M, map);
      int bottom = can_move_dir(x, y, 'B', N, M, map);
      int left = can_move_dir(x, y, 'L', N, M, map);
      int right = can_move_dir(x, y, 'R', N, M, map);

      if (nb_move == 1) {
        map[x][y] = 'L'; //Bloque la position actuelle pour ne plus y revenir
        if (top) map[y-1][x] = 'D';
        else if (bottom) map[y+1][x] = 'D';
        else if (right) map[y][x+1] = 'D';
        else if (left) map[y][x-1] = 'D';
      }
      else {
        if (delta_x > 0 && left) map[y][x-1] = 'D';
        else if (delta_x < 0 && right) map[y][x+1] = 'D';
        else if (delta_y < 0 && bottom) map[y+1][x] = 'D';
        else if (delta_y > 0 && top) map[y-1][x] = 'D';
        else if (top) map[y-1][x] = 'D';
        else if (bottom) map[y+1][x] = 'D';
        else if (right) map[y][x+1] = 'D';
        else if (left) map[y][x-1] = 'D';
      }
      printf("", can_move(prisoner_position[0], prisoner_position[1], N, M, map));

      return 1;
    }
  else return 0;
  }
}

char run_instance(int N, int M, char map[N][M]) {
  int turn = 0;
  int arrive=0;
  while (turn < N*M) {
    //on tranforme les A en F
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (map[j][k] == 'A') {
          map[j][k] = 'F';
        }
      }
    }
    //on propage le feu
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (map[j][k] == 'F') {
          if (burn_around(k, j, N, M, map)) return 'N';
        }
      }
    }
    //on fait bouger le prisonnier
    /*printf("1---------------------POUR VOIR LE FEU----------------------------\n");
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        printf("%c", map[j][k]);
      }
      printf("\n");
    }
    printf("2---------------------------POUR VOIR LE FEU--------------------------\n");
    printf("\n");*/
    if(move_prisoner(N, M, map)==2){
        return 'Y';
    }
    printf("\n\n");
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        printf("%c", map[j][k]);
      }
      printf("\n");
    }

    turn++;
  }
  //printf("\narrive : %d\n");
  return 'N';
}


int main(void) {
  int N_INSTANCES;
  //nombre de labyrinths qu'onva saisir
  scanf("%d", &N_INSTANCES);
  for (int i = 0; i < N_INSTANCES; i++) {
    int N;
    int M;
    //dimensions du labyrinthe
    scanf("%d %d", &N, &M);
    char map[N][M];
    for (int j = 0; j < N; j++) {
      char entree[M];
      //valeur de la case du labyrinthe
      scanf("%s", entree);
      for (int k = 0; k < M; k++) {
        map[j][k] = entree[k];
      }
    }
    //on lance le jeu sur le labyrinthe j
    printf("\n%c\n", run_instance(N, M, map));
  }
  return 0;
}