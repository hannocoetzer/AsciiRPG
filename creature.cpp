#include "creature.h"

creature::creature(int x, int y, bool temp_hero, char temp_look, bool temp_ai,
                   int temp_speed, int temp_hitpoints, int temp_agility,
                   char *temp_color, int temp_mapweaponcount,
                   int temp_treasurecount, char *temp_weaponname,
                   int temp_weapondamage, char *temp_name, int temp_x1,
                   int temp_y1, int temp_x2, int temp_y2) {
  // char* weaponname = new char[10];
  // char* color = new char[10];
  // char* name = new char[10];

  sight = 6;
  killcount = 0;
  itemcount = 0;
  weaponcount = 0;
  total++;
  win_x1 = temp_x1;
  win_y1 = temp_y1;
  win_x2 = temp_x2;
  win_y2 = temp_y2;
  pre_x = pos_x = x;
  pre_y = pos_y = y;
  hero = temp_hero;
  look = temp_look;
  speed = temp_speed * 1000;
  hitpoints = temp_hitpoints;
  agility = temp_agility;
  color = temp_color;
  mapweaponcount = temp_mapweaponcount;
  treasurecount = temp_treasurecount;
  treasureremain = treasurecount;
  weaponname = temp_weaponname;
  weapondamage = temp_weapondamage;
  name = temp_name;
  alive = true;
  advance = false;
  suspend = false;
  ai = temp_ai;
  exitstate = false;
  keystatus = false;
}

creature::~creature() {}

int creature::gettotal() { return total; }
int creature::getweaponcount() { return weaponcount; }
int creature::getpos_x() { return pos_x; }
int creature::getpos_y() { return pos_y; }
bool creature::getalive() { return alive; }
bool creature::getadvance() { return advance; }
char *creature::getname() { return name; }
char *creature::getweaponname() { return weaponname; }
void creature::setweapon(char *, int) {}
int creature::getweapondamage() { return weapondamage; }
int creature::gethitpoints() { return hitpoints; }

void creature::sethitpoints(int temp_hitpoints) { hitpoints = temp_hitpoints; }
void creature::kill() {
  look = '.';
  wmove(map_win, pos_y, pos_x);
  waddstr(map_win, ".");
  wrefresh(map_win);
  alive = false;
}
void creature::addweapon(char *temp_weaponname, int temp_weapondamage) {
  weaponname_array[weaponcount] = temp_weaponname;
  weapondamage_array[weaponcount] = temp_weapondamage;
  weaponcount++;
}
void creature::additem(char *temp_item) {
  itemname_array[itemcount] = temp_item;
  itemcount++;
}
void creature::addkilllist(char *temp_creaturename) {

  creaturekill_array[killcount] = temp_creaturename;
  killcount++;
}
int creature::getagility() { return agility; }

void creature::run() {

  if (alive) {
    int ch;

    if (hero) {
      direction = getch();
      // todo/note when I added this the map suddenly became all colourful and
      //  alive
      std::cout << direction;
      movement();
    }
    if (!hero) {
      if (ai & weaponcount == 0) {
        hero_pos_x = creatures[0]->getpos_x();
        hero_pos_y = creatures[0]->getpos_y();
        findhero();
        movement();
      }
      if (ai & weaponcount > 0) {
        directionrandomizer();
        movement();
      }

      if (!ai) {
        directionrandomizer();
        movement();
      }
    }
  }
}

void creature::precleanup() {
  if (visiblemap[pre_y][pre_x] == 1) {
    wmove(map_win, pre_y, pre_x);
    charcoloroff(pre_y, pre_x);
    waddch(map_win, mapchar[pre_y][pre_x]);

    wrefresh(map_win); /* Print it on to the real screen */
  }
  if (visiblemap[pre_y][pre_x] == 0) {
    wmove(map_win, pre_y, pre_x);

    waddch(map_win, ' ');
    wrefresh(map_win); /* Print it on to the real screen */
  }
}

void creature::draw() {
  borderverify();
  pathverify();
  treasureverify();
  weaponverify();
  doorverify();
  randomitemverify();
  revealarea();

  precleanup();

  pre_x = pos_x; // save current coordinates as previous
  pre_y = pos_y; // save current coordinates as previous

  if (visiblemap[pos_y][pos_x] == 1) {
    colorcheck();
    wmove(map_win, pos_y, pos_x); // move creature to new coordinates
    waddch(map_win, look);
    wrefresh(map_win);
  }
  if (visiblemap[pos_y][pos_x] == 0) {
    // todo get check enemy character icon  here
    wmove(map_win, pos_y, pos_x); // move creature to new coordinates
    waddstr(map_win, " ");
    wrefresh(map_win);
  }
}

void creature::redraw() {
  colorcheck();
  wmove(map_win, pos_y, pos_x); // move creature to new coordinates
  waddch(map_win, look);
  wrefresh(map_win);
}

void creature::colorcheck() {

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_BLACK);
  init_pair(9, COLOR_BLACK, COLOR_BLACK);

  if (strcmp("red", color) == 0) {
    wattron(map_win, COLOR_PAIR(6));
  }
  if (strcmp("green", color) == 0) {
    wattron(map_win, COLOR_PAIR(8));
  }
  if (strcmp("yellow", color) == 0) {
    wattron(map_win, COLOR_PAIR(3));
  }
  if (strcmp("blue", color) == 0) {
    wattron(map_win, COLOR_PAIR(2));
  }
  if (strcmp("magenta", color) == 0) {
    wattron(map_win, COLOR_PAIR(7));
  }
  if (strcmp("cyan", color) == 0) {
    wattron(map_win, COLOR_PAIR(5));
  }
  if (strcmp("white", color) == 0) {
    wattron(map_win, COLOR_PAIR(1));
  }
  if (strcmp("black", color) == 0) {
    wattron(map_win, COLOR_PAIR(9));
  }
}
void creature::borderverify() {

  if (pos_x < win_x1) {
    pos_x++;
  }
  if (pos_x > win_x2) {
    pos_x--;
  }
  if (pos_y < win_y1) {
    pos_y++;
  }
  if (pos_y > win_y2) {
    pos_y--;
  }
}

/*		This function does checking for all the characters that may not
 * be crossed                         */

void creature::pathverify() {
  if (mapchar[pos_y][pos_x] == '#') {
    pos_x = pre_x;
    pos_y = pre_y;
  }
  if (mapchar[pos_y][pos_x] == '=') {
    pos_x = pre_x;
    pos_y = pre_y;
  }
}

/*                                treasureverify is temorary and will change a
 * bit		*/

void creature::treasureverify() {
  if (hero) {
    if (treasuregrid[pos_y][pos_x] == 5) {
      for (int x = 0; x < treasurecount; x++) {
        if (pos_x == treasures[x]->getpos_x()) {
          if (pos_y == treasures[x]->getpos_y()) {

            char str[100];
            char temp_increase[3];
            // temp_increase[0] = treasures[x]->gethitpointincrease() + 0;
            sprintf(temp_increase, "%d", treasures[x]->gethitpointincrease());

            strcpy(str, " <");
            strcat(str, treasures[x]->getname());
            strcat(str, "> Point inc : <");
            strcat(str, temp_increase);
            strcat(str, ">.");

            if (question(str)) {
              if (strcmp("key", treasures[x]->getname()) == 0) {
                keystatus = true;
              }

              init_pair(3, COLOR_YELLOW, COLOR_BLACK);
              hitpoints = hitpoints + treasures[x]->gethitpointincrease();
              treasureremain--;
              mapchar[pos_y][pos_x] = '.';
              treasuregrid[pos_y][pos_x] = 0;
              additem(treasures[x]->getname());
              herodetail();
              if (treasureremain < 1) {

                char str[100];

                strcpy(str, "\n\n\nYou gathered all the treasures. Press [e] "
                            "to exit or [c] to continue...");
                waddstr(action_win, str);
                wrefresh(action_win);
                int ch;
                bool flag = true;
                while (flag) {
                  ch = getch();

                  if (ch == 'e') {
                    endwin();
                    exit(0);
                    advance = false;
                    flag = false;
                  }
                  if (ch == 'c') {
                    alive = false;
                    advance = true;
                    flag = false;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

/*				weaponverify is tempory and will change a bit
 */
void creature::weaponverify() {
  if (hero) {
    if (mapchar[pos_y][pos_x] == '(') {
      for (int x = 0; x < mapweaponcount; x++) {
        if (pos_x == weapons[x]->getpos_x()) {
          if (pos_y == weapons[x]->getpos_y()) {
            char str[100];
            char temp_damage[3];

            sprintf(temp_damage, "%d", weapons[x]->getdamage());

            // temp_damage[0] = weapons[x]->getdamage() + 0;
            strcpy(str, "<");
            strcat(str, weapons[x]->getname());
            strcat(str, "> Hit Damage : <");
            strcat(str, temp_damage);
            strcat(str, ">.");

            if (question(str)) {
              init_pair(3, COLOR_YELLOW, COLOR_BLACK);
              addweapon(weapons[x]->getname(), weapons[x]->getdamage());
              mapchar[pos_y][pos_x] = '.';
              herodetail();
            }
          }
        }
      }
    }
  }
}

/*				doorverify is semi tempory and will change a bit
 */
void creature::doorverify() {
  if (hero) {
    if (mapchar[pos_y][pos_x] == '+' & keystatus == true) {
      if (question("A door to a new area.")) {
        mapchar[pos_y][pos_x] = '/';
        herodetail();
        keystatus = false;
      } else {
        pos_x = pre_x;
        pos_y = pre_y;
      }
    } else if (mapchar[pos_y][pos_x] == '+' & keystatus == false) {
      pos_x = pre_x;
      pos_y = pre_y;
    }
  }
  if (!hero) {
    if (mapchar[pos_y][pos_x] == '+') {
      pos_x = pre_x;
      pos_y = pre_y;
    }
  }
}

void creature::randomitemverify() {
  if (hero) {
    if (mapchar[pos_y][pos_x] == '0') {
      if (question("A teleport to new area")) {
        pos_x = 2;
        pos_y = 2;
        pre_x = pos_x;
        pre_y = pos_y;
      }
    }
  }
}

void creature::revealarea() {

  if (hero) {
    for (int x = 0; x < sight; x++) {
      if (pos_x + x <= win_x2) {
        for (int y = 0; y < sight; y++) {
          if (pos_y + y <= win_y2) {
            charcoloron(abs(pos_y + y), abs(pos_x + x));

            wmove(map_win, abs(pos_y + y), abs(pos_x + x));
            waddch(map_win, mapchar[abs(pos_y + y)][abs(pos_x + x)]);
            wrefresh(map_win);
            visiblemap[abs(pos_y + y)][abs(pos_x + x)] = 1;
          }

          if (pos_y - y >= win_y1) {
            charcoloron(abs(pos_y - y), abs(pos_x + x));
            wmove(map_win, abs(pos_y - y), abs(pos_x + x));
            waddch(map_win, mapchar[abs(pos_y - y)][abs(pos_x + x)]);
            wrefresh(map_win);

            visiblemap[abs(pos_y - y)][abs(pos_x + x)] = 1;
          }
        }
      }
      if (pos_x - x >= win_x1) {
        for (int y = 0; y < sight; y++) {
          if (pos_y + y <= win_y2) {
            charcoloron(abs(pos_y + y), abs(pos_x - x));
            wmove(map_win, abs(pos_y + y), abs(pos_x - x));
            waddch(map_win, mapchar[abs(pos_y + y)][abs(pos_x - x)]);
            wrefresh(map_win);
            visiblemap[abs(pos_y + y)][abs(pos_x - x)] = 1;
          }
          if (pos_y - y >= win_y1) {
            charcoloron(abs(pos_y - y), abs(pos_x - x));
            wmove(map_win, abs(pos_y - y), abs(pos_x - x));
            waddch(map_win, mapchar[abs(pos_y - y)][abs(pos_x - x)]);
            wrefresh(map_win);
            visiblemap[abs(pos_y - y)][abs(pos_x - x)] = 1;
          }
        }
      }
    }
  }

  wrefresh(map_win);
}

void creature::directionrandomizer() {
  int num = rand() % 8 + 1; // Get random between 1 and MAX_RANGE
  switch (num) {
  case 1:
    direction = KEY_UP;
    break;
  case 2:
    direction = KEY_DOWN;
    break;
  case 3:
    direction = KEY_LEFT;
    break;
  case 4:
    direction = KEY_RIGHT;
    break;
  case 5:
    direction = KEY_END;
    break;
  case 6:
    direction = KEY_HOME;
    break;
  case 7:
    direction = KEY_NPAGE;
    break;
  case 8:
    direction = KEY_PPAGE;
    break;
  }
}

void creature::movement() {
  // todo change speed
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  switch (direction) {
  case KEY_UP:
    pos_y--;
    draw();
    break;
  case KEY_DOWN:
    pos_y++;
    draw();
    break;
  case KEY_LEFT:
    pos_x--;
    draw();
    break;
  case KEY_RIGHT:
    pos_x++;
    draw();
    break;
  case '9':
    pos_x++;
    pos_y--;
    draw();
    break;
  case '7':
    pos_x--;
    pos_y--;
    draw();
    break;
  case '1':
    pos_x--;
    pos_y++;
    draw();
    break;
  case '3':
    pos_x++;
    pos_y++;
    draw();
    break;
  case '8':
    pos_y--;
    draw();
    break;
  case '2':
    pos_y++;
    draw();
    break;
  case '4':
    pos_x--;
    draw();
    break;
  case '6':
    pos_x++;
    draw();
    break;
  case KEY_END:
    pos_x--;
    pos_y++;
    draw();
    break;

  case KEY_HOME:
    pos_x--;
    pos_y--;
    draw();
    break;

  case KEY_NPAGE:
    pos_x++;
    pos_y++;
    draw();
    break;
  case KEY_PPAGE:
    pos_x++;
    pos_y--;
    draw();
    break;
  case KEY_F(1):
    endwin();
    exit(0);
    break;
  case KEY_F(2):
    weaponchooser();
    break;
  case KEY_F(3):
    itemlist();
    break;
  case KEY_F(4):
    killlist();
    break;
  case KEY_F(5):
    herodetail();
    break;
  case KEY_F(6):
    mission();
    break;
  case KEY_F(7):
    help();
    break;
  }
}

void creature::findhero() {
  int num = rand() % 2 + 1;
  if (num == 1) {
    if (hero_pos_x < pos_x) {

      direction = KEY_LEFT;
    }
    if (hero_pos_x > pos_x) {
      direction = KEY_RIGHT;
    }
  }
  if (num == 2) {
    if (hero_pos_y > pos_y) {
      direction = KEY_DOWN;
    }

    if (hero_pos_y < pos_y) {
      direction = KEY_UP;
    }
  }
}

void creature::weaponchooser() {

  int x;
  int ch;
  common_win = newwin(40, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Inventory window");
  wrefresh(common_win);

  wmove(common_win, 3, 2);
  waddstr(common_win, "No.          Weapon Name   ");
  wmove(common_win, 4, 2);
  waddstr(common_win, "--           -----------    ");
  wrefresh(common_win);

  for (x = 0; x < weaponcount; x++) {

    char x_str[2];

    sprintf(x_str, "%d", x);

    //			x_str[0] = x + 0;

    wmove(common_win, x + 6, 2);
    waddstr(common_win, x_str);
    waddstr(common_win, ") ");
    wmove(common_win, x + 6, 8);
    waddstr(common_win, weaponname_array[x]);

    // delete x_str;
  }

  if (weaponcount > 0) {
    wmove(common_win, x + 9, 2);
    waddstr(common_win, "Current : <");
    waddstr(common_win, weaponname);
    waddstr(common_win, "> Damage : <");
    waddch(common_win, weapondamage + 48);
    waddstr(common_win, ">");

    wmove(common_win, 34, 2);
    waddstr(common_win, "Choose a special weapon by no...  ");
    wmove(common_win, 35, 2);
    waddstr(common_win, "       or any key to exit  ");
    wrefresh(common_win);
    bool flag;
    flag = false;
    do {
      ch = getch();
      ch = ch - 48;
      if (ch >= 0 & ch < x) {
        weaponname = weaponname_array[ch];
        weapondamage = weapondamage_array[ch];
        flag = true;
      }

    } while (false);

  } else {
    wmove(common_win, 7, 4);
    waddstr(common_win, "No Weapons in inventory bag ");
    wmove(common_win, 37, 2);
    waddstr(common_win, "   Press any key to continue...");

    wrefresh(common_win);
    getch();
  }

  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);
  herodetail();
}

void creature::herodetail() {
  char str[100];
  char hit_str[3];

  char weapondamage_str[3];
  char hitpoints_str[3];
  sprintf(weapondamage_str, "%d", weapondamage);
  sprintf(hitpoints_str, "%d", hitpoints);

  strcpy(str, "You have a <");
  strcat(str, weaponname);
  strcat(str, "> in your hand with a value of <");
  strcat(str, weapondamage_str);
  strcat(str, "> . Your still alive with <");
  strcat(str, hitpoints_str);
  strcat(str, "> health.\n");

  waddstr(status_win, str);
  wrefresh(status_win);
}

void creature::itemlist() {
  int x;
  int ch;
  common_win = newwin(40, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Treasure List window");

  wmove(common_win, 3, 2);
  waddstr(common_win, "Treasure Name");
  wmove(common_win, 4, 2);
  waddstr(common_win, "-------------");

  for (x = 0; x < itemcount; x++) {
    wmove(common_win, x + 6, 2);
    waddstr(common_win, itemname_array[x]);
  }

  wmove(common_win, 37, 2);
  waddstr(common_win, "   Press any key to continue...");

  wrefresh(common_win);
  getch();

  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);
}

void creature::killlist() {
  int x;
  int ch;
  common_win = newwin(40, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Kill List window");

  wmove(common_win, 3, 2);
  waddstr(common_win, "Creature Name");
  wmove(common_win, 4, 2);
  waddstr(common_win, "-------------");

  for (x = 0; x < killcount; x++) {
    wmove(common_win, x + 6, 2);
    waddstr(common_win, creaturekill_array[x]);
  }

  wmove(common_win, 37, 2);
  waddstr(common_win, "   Press any key to continue...");

  wrefresh(common_win);
  getch();

  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);
}

void creature::mission() {
  int x;
  int ch;
  common_win = newwin(40, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Game Mission window");
  wrefresh(common_win);

  wmove(common_win, 3, 2);
  waddstr(common_win, "The Main purpose of the game, is");
  wmove(common_win, 4, 2);
  waddstr(common_win, "to run around and kill as many");
  wmove(common_win, 5, 2);
  waddstr(common_win, "creatures as possible. Remember ");
  wmove(common_win, 6, 2);
  waddstr(common_win, "that the creatures want's to kill");
  wmove(common_win, 7, 2);
  waddstr(common_win, "you as much as you want to kill");
  wmove(common_win, 8, 2);
  waddstr(common_win, "them. By taking a creature's ");
  wmove(common_win, 9, 2);
  waddstr(common_win, "life (S@#T happens) you recieve");
  wmove(common_win, 10, 2);
  waddstr(common_win, "the creature's weapon (the ");
  wmove(common_win, 11, 2);
  waddstr(common_win, "basstard that you just killed), ");
  wmove(common_win, 12, 2);
  waddstr(common_win, "the weapon is added to you're ");
  wmove(common_win, 13, 2);
  waddstr(common_win, "weapon inventory and you're one");
  wmove(common_win, 14, 2);
  waddstr(common_win, "step closer to being invinsible.");

  wmove(common_win, 16, 2);
  waddstr(common_win, "Remember that for each fight, you");
  wmove(common_win, 17, 2);
  waddstr(common_win, "aswell as the creature's hitpoints");
  wmove(common_win, 18, 2);
  waddstr(common_win, "is reduced by the amount of ");
  wmove(common_win, 19, 2);
  waddstr(common_win, "damage the weapon do. So it would ");
  wmove(common_win, 20, 2);
  waddstr(common_win, "be wise to battle creatures that ");
  wmove(common_win, 21, 2);
  waddstr(common_win, "have less hitpoints than others ");
  wmove(common_win, 22, 2);
  waddstr(common_win, "or to battle creatures that have ");
  wmove(common_win, 23, 2);
  waddstr(common_win, "a stupid weapon. Last ");
  wmove(common_win, 24, 2);
  waddstr(common_win, "man standing wins.");

  wmove(common_win, 26, 2);
  waddstr(common_win, "Some creatures might have enough ");
  wmove(common_win, 27, 2);
  waddstr(common_win, "courage to take you on if you ");
  wmove(common_win, 28, 2);
  waddstr(common_win, "have no weapons. Once you have ");
  wmove(common_win, 29, 2);
  waddstr(common_win, "killed a creature and takken his");
  wmove(common_win, 30, 2);
  waddstr(common_win, "weapon, the creatures will have ");
  wmove(common_win, 31, 2);
  waddstr(common_win, "enough intelligence to reconsider");
  wmove(common_win, 32, 2);
  waddstr(common_win, "the consiquences of there actions.");

  wmove(common_win, 37, 3);
  waddstr(common_win, "   Press any key to continue...");
  wrefresh(common_win);

  getch();

  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);
}

void creature::help() {
  int x;
  int ch;
  common_win = newwin(46, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Help window");

  wmove(common_win, 3, 2);
  waddstr(common_win, "Action window : ");
  wmove(common_win, 4, 2);
  waddstr(common_win, "------------- ");
  wmove(common_win, 5, 2);
  waddstr(common_win, "This window displays everything");
  wmove(common_win, 6, 2);
  waddstr(common_win, "that is happening. The name");
  wmove(common_win, 7, 2);
  waddstr(common_win, "of the creature being attacked");
  wmove(common_win, 8, 2);
  waddstr(common_win, "is displayed aswell as his weapon");
  wmove(common_win, 9, 2);
  waddstr(common_win, "and strenght.Creature that have");
  wmove(common_win, 10, 2);
  waddstr(common_win, "been slain is also displayed here.");

  wmove(common_win, 12, 2);
  waddstr(common_win, "Map window : ");
  wmove(common_win, 13, 2);
  waddstr(common_win, "---------- ");
  wmove(common_win, 14, 2);
  waddstr(common_win, "What more can I say, this window");
  wmove(common_win, 15, 2);
  waddstr(common_win, "displays the map, creatures and");
  wmove(common_win, 16, 2);
  waddstr(common_win, "the hero.");

  wmove(common_win, 18, 2);
  waddstr(common_win, "Status window : ");
  wmove(common_win, 19, 2);
  waddstr(common_win, "-------------");
  wmove(common_win, 20, 2);
  waddstr(common_win, "This window displays everything");
  wmove(common_win, 21, 2);
  waddstr(common_win, "concerned with the hero.His health,");
  wmove(common_win, 22, 2);
  waddstr(common_win, "hitpoints,selected weapon.It also");
  wmove(common_win, 23, 2);
  waddstr(common_win, "displays items picked-up such as ");
  wmove(common_win, 24, 2);
  waddstr(common_win, "weapons and treasures.");

  wmove(common_win, 26, 2);
  waddstr(common_win, "Option window : ");
  wmove(common_win, 27, 2);
  waddstr(common_win, "-------------");
  wmove(common_win, 28, 2);
  waddstr(common_win, "->F1 = Exit the game(are you sure)");
  wmove(common_win, 29, 2);
  waddstr(common_win, "->F2 = Choose the weopon to use");
  wmove(common_win, 30, 2);
  waddstr(common_win, "->F3 = List of items picked-up");
  wmove(common_win, 31, 2);
  waddstr(common_win, "->F4 = Display creatures killed");
  wmove(common_win, 32, 2);
  waddstr(common_win, "->F5 = Display hero heath & weapon");
  wmove(common_win, 33, 2);
  waddstr(common_win, "->F6 = Display game mission");
  wmove(common_win, 34, 2);
  waddstr(common_win, "->F7 = This Help window");

  wmove(common_win, 36, 2);
  waddstr(common_win, "Control Keys : ");
  wmove(common_win, 37, 2);
  waddstr(common_win, "------------");
  wmove(common_win, 38, 2);
  waddstr(common_win, "You may use the standard arrow");
  wmove(common_win, 39, 2);
  waddstr(common_win, "keys or the Key pad. Numlock may be");
  wmove(common_win, 40, 2);
  waddstr(common_win, "on or off to move the hero around.");

  wmove(common_win, 42, 2);
  waddstr(common_win, "   Press any key to continue...");

  wrefresh(common_win);
  getch();
  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);
}

bool creature::question(char *temp_str) {
  bool flag = false;
  int ch;
  common_win = newwin(46, 38, 8, 94);
  wborder(common_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wmove(common_win, 0, 7);
  waddstr(common_win, "Question window");

  wmove(common_win, 4, 2);
  waddstr(common_win, temp_str);

  wmove(common_win, 14, 2);
  waddstr(common_win, "To [open]/[pick-up]/[continue] ");
  wmove(common_win, 16, 2);
  waddstr(common_win, "       Press [y][n]...");
  wrefresh(common_win);
  ch = getch();

  if (ch == 89 | ch == 121) {

    flag = true;
  }

  wclear(common_win);
  wrefresh(common_win);
  delwin(common_win);

  return flag;
}

void creature::charcoloron(int y, int x) {
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_BLACK);

  if (mapchar[y][x] == '.') {
    wattron(map_win, COLOR_PAIR(3));
  }
  if (mapchar[y][x] == '#') {
    wattron(map_win, COLOR_PAIR(1));
  }
  if (mapchar[y][x] == '=') {
    wattron(map_win, COLOR_PAIR(2));
  }
  if (mapchar[y][x] == 'T') {
    wattron(map_win, COLOR_PAIR(8));
  }
  if (mapchar[y][x] == '+') {
    wattron(map_win, COLOR_PAIR(6));
  }
  if (mapchar[y][x] == '/') {
    wattron(map_win, COLOR_PAIR(6));
  }
  if (mapchar[y][x] == '(') {
    wattron(map_win, COLOR_PAIR(7));
  }
  if (mapchar[y][x] == '$') {

    wattron(map_win, COLOR_PAIR(5));
  }
}

void creature::charcoloroff(int y, int x) {

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_BLACK);

  if (mapchar[y][x] == '.') {
    wattron(map_win, COLOR_PAIR(3));
  }
  if (mapchar[y][x] == '#') {
    wattron(map_win, COLOR_PAIR(1));
  }
  if (mapchar[y][x] == '=') {
    wattron(map_win, COLOR_PAIR(2));
  }
  if (mapchar[y][x] == 'T') {
    wattron(map_win, COLOR_PAIR(8));
  }
  if (mapchar[y][x] == '+') {
    wattron(map_win, COLOR_PAIR(6));
  }
  if (mapchar[y][x] == '/') {
    wattron(map_win, COLOR_PAIR(6));
  }
  if (mapchar[y][x] == '(') {
    wattron(map_win, COLOR_PAIR(7));
  }
  if (mapchar[y][x] == '$') {

    wattron(map_win, COLOR_PAIR(5));
  }
}
