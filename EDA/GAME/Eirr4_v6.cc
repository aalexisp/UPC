 #include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Eirr4_v6


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {  
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  typedef vector<int> VIA;
  typedef vector<vector<int> > MAP;

  void bfs_tresors(MAP &m){
    queue<Pos> q;
    int infinit = -1;
    for (int i = 2; i < 58; ++i){
      for (int j = 2; j < 58; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Si trobem una cova que no és nostra la distància és 0
        if (c.treasure) {
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).id == -1 and cell(nou).type != Granite and cell(nou).type != Abyss){
          if (m[nou.i][nou.j] == -1 or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 2; i < 58; ++i){
      for (int j = 2; j < 58; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.owner != me() and c.type == Cave and c.id == -1){
          m[i][j] = 0; q.push(p);
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_rock(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 2; i < 58; ++i){
      for (int j = 2; j < 58; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.type == Rock and c.id == -1){
          m[i][j] = 0; q.push(p);
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_outside(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.type == Outside and c.id == -1){
          m[i][j] = 0; q.push(p);
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).type == Cave and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_enemycell(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 2; i < 58; ++i){
      for (int j = 2; j < 58; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.owner != me() and c.owner != -1 and c.type == Cave and c.id == -1){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_wiz(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Guardem si hi ha un enano
        if (c.id != -1 and unit(c.id).player == me() and unit(c.id).type == Dwarf){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; x+=2){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).id == -1 and (cell(nou).type == Cave or cell(nou).type == Outside)){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_d_w(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Guardem si hi ha un enano
        if (c.id != -1 and unit(c.id).player == me() and unit(c.id).type == Wizard){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; x+=2){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).id == -1 and (cell(nou).type == Cave or cell(nou).type == Outside)){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_ally(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Guardem si hi ha un enano
        if (c.id != -1 and unit(c.id).player == me()){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).id == -1 and (cell(nou).type == Cave or cell(nou).type == Outside)){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_atck_out(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Si trobem un enemic que no és un troll o el balrog la distància és 0
        if (c.id != -1 and unit(c.id).player != me() and c.type == Outside and (i <= 25 or i >= 35) and (j <= 25 or j >= 35)){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }


  void bfs_atck(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Si trobem un enemic que no és un troll o el balrog la distància és 0
        if (c.id != -1 and unit(c.id).player != me() and unit(c.id).type != Troll and unit(c.id).type != Balrog){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_atck_low(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Si trobem un enemic que no és un troll o el balrog la distància és 0
        if (c.id != -1 and unit(c.id).player != me() and unit(c.id).health <= 40 and unit(c.id).type != Troll and unit(c.id).type != Balrog){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_atck_wiz(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Si trobem un enemic que no és un troll o el balrog la distància és 0
        if (c.id != -1 and unit(c.id).player != me() and unit(c.id).health <= 50 and (unit(c.id).type == Wizard or unit(c.id).type == Dwarf)){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and (cell(nou).type == Cave or cell(nou).type == Outside) and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_balrog(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.id != -1 and c.id == balrog_id()){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou) and cell(nou).type == Cave and cell(nou).id == -1){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void bfs_troll(MAP &m){
    queue<Pos> q;
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        Pos p = Pos(i, j);
        Cell c = cell(p);
        //Anem a les coves que no siguin del meu color i no hi hagi ningú
        if (c.id != -1 and unit(c.id).type == Troll){
          m[i][j] = 0; q.push(p); 
        }
      }
    }
    while (not q.empty()){
      Pos act = q.front(); q.pop();
      for (int x = 0; x < 8; ++x){
        Pos nou = act + Dir(x);
        if (pos_ok(nou)){
          if (m[nou.i][nou.j] == numeric_limits<int>::max() or m[act.i][act.j] + 1 < m[nou.i][nou.j]){
            m[nou.i][nou.j] = m[act.i][act.j] + 1;
            q.push(nou);
          }
        } 
      }
    }
  }

  void dist_min(int &min, Dir &d, Pos &p, MAP &m, MAP &mb, MAP &mtroll){
    min = 9999;
    for (int j = 0; j < 8; ++j){
      //MATRIZ DE DISTANCIAS AL BALROG
      Pos nou = p + Dir(j);
      if (pos_ok(nou) and m[nou.i][nou.j] < min and mb[nou.i][nou.j] > 2 
                and mtroll[nou.i][nou.j] > 1) {
        min = m[nou.i][nou.j];
        d = Dir(j);
      }
    }
  }

  void dist_min_r(int &min, Dir &d, Pos &p, MAP &m, MAP &mb, MAP &mtroll){
    min = 9999;
    d = Dir(8);
    vector<int> ve = random_permutation(8);
    for (int j = 0; j < 8; ++j){
      //MATRIZ DE DISTANCIAS AL BALROG
      Pos nou = p + Dir(ve[j]);
      if (pos_ok(nou) and m[nou.i][nou.j] < min and mb[nou.i][nou.j] > 2 
              and mtroll[nou.i][nou.j] > 1) {
        min = m[nou.i][nou.j];
        d = Dir(ve[j]);
      }
    }
  }


  void move_dwarf(MAP &m, MAP &ma, MAP &mt, MAP &mec, MAP &mo, MAP &mb, MAP &mr, MAP &mao, MAP &mdw, MAP &maw, MAP &mally, MAP &mtroll, MAP &mlow){
    vector<int> v = dwarves(me());
    int n = v.size();
    for (int i = 0; i < n; ++i){
      int id = v[i];
      Pos p = unit(id).pos;

      int min = 9999;
      Dir d = Dir(8);

      //Calculamos la distáncia al BALROG Como prioridad
      dist_min(min, d, p, mb, mb, mtroll);
      if (min <= 2) {
        //Si el BALROG está cerca vamos hacia outside
        dist_min(min, d, p, mo, mb, mtroll);
        command(id, d);
      }
      else {
        int aux;
        Dir daux = Dir(8);
        int aux2;
        Dir daux2 = Dir(8);
        dist_min(aux, daux, p, maw, mb, mtroll);
        dist_min(min, d, p, ma, mb, mtroll);
        dist_min(aux2, daux2, p, mlow, mb, mtroll);

        if (aux <= 2) command(id, daux);
        else if (aux2 <= 2) command(id, daux2);
        else if (unit(id).health > 20 and ((round() <= 100 and min <= 3)
                      or (round() > 100 and min <= 2) or (n >= 40 and min <= 2))) command(id, d);
        else {
          //BUSCAMOS ALIADOS
      //    dist_min(min, d, p, mally, mb, mtroll);
     //     if ((min <= 1 and round() <= 100) or (min <= 4 and round() > 100) or n <= 30){
       //     else {
              //Si el BALROG no está cerca buscamos al más cercano para atacar
            dist_min(min, d, p, mao, mb, mtroll);
              if (unit(id).health > 20 and round() <= 150 and n <= 50) command(id, d);
              else {
              //Si no hay nadie cerca entre la ronda 30 y 100 vamos a matar fuera
              dist_min(min, d, p, mdw, mb, mtroll);
              if (unit(id).health <= 20 or (unit(id).health <= 70 and min <= 10)) command(id, d);
              else {
                //Si tenemos un tesoro a menos de 4 de distancia vamos a por el
                dist_min(min, d, p, mt, mb, mtroll);
                if ((min <= 3 and n < 50) or (n >= 60 and min <= 10)) command(id, d);
                else {
                  //MATRIZ DE CELDAS ENEMIGAS
                    dist_min_r(min, d, p, mec, mb, mtroll);
                  if (min <= 5) command(id, d);
                  else {
                    //MATRIZ DE CELDAS LIBRES BLANCAS
                    dist_min_r(min, d, p, m, mb, mtroll);
                    if (min <= 7) command(id, d);
                    else {
                      dist_min(min, d, p, mr, mb, mtroll);
                      command(id, d);
                    }
                  }
                }
              }
            }
       //   } else command(id, d);
        }
      }
    }
  }

void move_wizard(MAP &m, MAP &mb, MAP &mo, MAP &ma){
    vector<int> v = wizards(me());
    int n = v.size();
    for (int i = 0; i < n; ++i){
      int id = v[i];
      Pos p = unit(id).pos;
      int min_bal, min;
      min_bal = min = 9999;
      Dir d = Dir(8);
      vector<int> ve = random_permutation(8);

      for (int j = 0; j < 8; j+=2){
        Pos nou = p + Dir(j);
        if (pos_ok(nou) and mb[nou.i][nou.j] < min) {
          min_bal = mb[nou.i][nou.j];
          d = Dir(j);
        }
      }

      if (min_bal > 2){
        for (int j = 0; j < 8; ++j){
          if (ve[j]%2 == 0){
            Pos nou = p + Dir(ve[j]);
            Cell c;
            if (pos_ok(nou)) c = cell(nou);
            if (pos_ok(nou) and m[nou.i][nou.j] < min and mb[nou.i][nou.j] > 2 and ma[nou.i][nou.j] > 1) {
              min = m[nou.i][nou.j];
              d = Dir(ve[j]);
            }
          }
        } 
        command(id, d);
      } else {
        min = 9999;
        for (int j = 0; j < 8; j+=2){
          Pos nou = p + Dir(j);
          if (pos_ok(nou) and mo[nou.i][nou.j] < min and mb[nou.i][nou.j] > 2 and ma[nou.i][nou.j] > 1) {
            min = mo[nou.i][nou.j];
            d = Dir(j);
          }
        }
        command(id, d);
      }
    }
  }


  /*void escriu(MAP &m){
    int infinit = numeric_limits<int>::max();
    for (int i = 0; i < 60; ++i){
      for (int j = 0; j < 60; ++j){
        if (m[i][j] == infinit) cerr << "-1 ";
        else cerr << m[i][j] << " ";
      }
      cerr << endl;
    }
  }*/

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    int infinit = numeric_limits<int>::max();
    MAP m(60, vector<int> (60, infinit));
    MAP ma(60, vector<int> (60, infinit));
    MAP mw(60, vector<int> (60, infinit));
    MAP mt(60, vector<int> (60, infinit));
    MAP mec(60, vector<int> (60, infinit));
    MAP mo(60, vector<int> (60, infinit));
    MAP mb(60, vector<int> (60, infinit));
    MAP mr(60, vector<int> (60, infinit));
    MAP mao(60, vector<int> (60, infinit));
    MAP mdw(60, vector<int> (60, infinit));
    MAP maw(60, vector<int> (60, infinit));
    MAP mally(60, vector<int> (60, infinit));
    MAP mtroll(60, vector<int> (60, infinit));
    MAP mlow(60, vector<int> (60, infinit));

    bfs_atck(ma);
    bfs(m);
    bfs_tresors(mt);
    bfs_enemycell(mec);
    bfs_outside(mo);
    bfs_balrog(mb);
    bfs_rock(mr);
    bfs_atck_out(mao);
    bfs_d_w(mdw);
    bfs_atck_wiz(maw);
    bfs_ally(mally);
    bfs_troll(mtroll);
    bfs_atck_low(mlow);

    /*if (round() == 199){
      escriu(mally);
      //escriu(m);
      //escriu(mt);
    }*/

    move_dwarf(m, ma, mt, mec, mo, mb, mr, mao, mdw, maw, mally, mtroll, mlow);

    bfs_wiz(mw);
    move_wizard(mw, mb, mo, ma);
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
