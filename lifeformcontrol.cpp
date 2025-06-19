#include "lifeformcontrol.h"

using namespace std;

lifeformcontrol::lifeformcontrol() {
  for (int x = 0; x <= 6; x++) {
    str_array[x] = "                                                           "
                   "            ";
  }
  count = 0;
  mapweaponcount = 0;
  treasurecount = 0;
}

void lifeformcontrol::start_windows() {
  windows main;
  main.create_action_win();
  main.create_map_win();
  main.create_status_win();
  main.create_option_win();
}

bool lifeformcontrol::start_gamecontrol(int temp_creaturecount) {
  creaturecount = temp_creaturecount;
  bool temp;
  int x = temp_creaturecount;

  do {
    try {

      for (int n = 1; n < x - 1; n++) {

        creatures[n]->run();
      }

      // todo uncomment
      creatures[0]->run(); // run hero last so that he can kill
      collision_check();

    } catch (...) {
      waddstr(status_win, "\n\n\n ***Some creature went Bad***    \n\n\n");
      wrefresh(status_win);
    }

  } while (creatures[0]->getalive() == true &
           creatures[0]->getadvance() == false);

  for (int n = 1; n < x - 1; n++) {

    creatures[n]->kill();
  }

  temp = creatures[0]->getadvance();

  return temp;
}

void lifeformcontrol::collision_check() {
  int count = creaturecount;
  for (int x = 1; x < count; x++) {
    if (creatures[x]->getalive() == true) {

      if (creatures[0]->getpos_x() == creatures[x]->getpos_x()) {
        if (creatures[0]->getpos_y() == creatures[x]->getpos_y()) {

          int num = rand() % creatures[x]->getagility() +
                    1; // Get random between 1 and MAX_RANGE
          if (num <= 10) {
            creature_collision_no = x;
            attack();
            creature_detail();
            hero_detail();
          } else {
            char str[100];

            strcpy(str, "You **MISSED** the <");
            strcat(str, creatures[x]->getname());
            strcat(str, ">. \n");

            waddstr(action_win, str);
            wrefresh(action_win);
          }
        }
      }
    }
  }
  // creatures[0]->redraw();
}

void lifeformcontrol::attack() {

  if (checkhealth()) {
    creatures[0]->sethitpoints(
        creatures[0]->gethitpoints() -
        creatures[creature_collision_no]->getweapondamage());
    creatures[creature_collision_no]->sethitpoints(
        creatures[creature_collision_no]->gethitpoints() -
        creatures[0]->getweapondamage());
  }
}

bool lifeformcontrol::checkhealth() {
  bool flag = true;

  // if the hero killed a creature, do the following :
  if (creatures[creature_collision_no]->gethitpoints() < 1) {
    creatures[0]->addkilllist(creatures[creature_collision_no]->getname());
    creatures[0]->addweapon(
        creatures[creature_collision_no]->getweaponname(),
        creatures[creature_collision_no]->getweapondamage());
    creatures[creature_collision_no]->kill();

    flag = false;
    hero_detail(); // this is to show that the hero got the killed creatures
                   // weapon

    char str[100];

    strcpy(str, "\nYou killed the <");
    strcat(str, creatures[creature_collision_no]->getname());
    strcat(str, "> . The slaughtered creature dropped his <");
    strcat(str, creatures[creature_collision_no]->getweaponname());
    strcat(str, "> .\n\n");
    waddstr(action_win, str);
    wrefresh(action_win);

    strcpy(str, "\nYou picked up the <");
    strcat(str, creatures[creature_collision_no]->getweaponname());
    strcat(str, "> of a(an) <");
    strcat(str, creatures[creature_collision_no]->getname());
    strcat(str, "> . Press F2 for more details...\n\n");

    waddstr(status_win, str);
    wrefresh(status_win);
  }
  if (creatures[0]->gethitpoints() < 1) {
    char str[100];
    char *temp;

    creatures[0]->kill();
    flag = false;

    strcpy(str, "\nThe <");
    strcat(str, creatures[creature_collision_no]->getname());
    strcat(str,
           "> have slaugtered you.RIP RIP RIP!!! .Press [e] to exit...\n\n");
    waddstr(status_win, str);
    wrefresh(status_win);

    int ch;
    bool flag = true;
    while (flag) {
      ch = getch();
      if (ch == 'e') {
        endwin();
        exit(0);
        flag == false;
      }
    }
    endwin();
    exit(0);
    delete temp;
  }

  return flag;
}

void lifeformcontrol::creature_detail() {
  if (creatures[creature_collision_no]->gethitpoints() > 0) {

    char weapondamage_str[3];
    char hitpoints_str[3];
    int weapondamage = creatures[creature_collision_no]->getweapondamage();
    int hitpoints = creatures[creature_collision_no]->gethitpoints();
    sprintf(weapondamage_str, "%d", weapondamage);
    sprintf(hitpoints_str, "%d", hitpoints);

    waddstr(action_win, "You **Hit** a(an) <");
    waddstr(action_win, creatures[creature_collision_no]->getname());
    waddstr(action_win, "> with a <");
    waddstr(action_win, creatures[creature_collision_no]->getweaponname());
    waddstr(action_win, "> that will take <");
    waddstr(action_win, weapondamage_str);
    waddstr(action_win, "> hitpoints from you. The creature has <");
    waddstr(action_win, hitpoints_str);
    waddstr(action_win, "> hitpoints.\n");

    wrefresh(action_win);
  }
}

void lifeformcontrol::hero_detail() {
  if (creatures[0]->gethitpoints() > 0) {

    char weapondamage_str[3];
    char hitpoints_str[3];
    int weapondamage = creatures[0]->getweapondamage();
    int hitpoints = creatures[0]->gethitpoints();
    sprintf(weapondamage_str, "%d", weapondamage);
    sprintf(hitpoints_str, "%d", hitpoints);

    waddstr(status_win, "You have a <");
    waddstr(status_win, creatures[0]->getweaponname());
    waddstr(status_win, "> in your hand with a value of <");
    waddstr(status_win, weapondamage_str);
    waddstr(status_win, ">.Your still alive with <");
    waddstr(status_win, hitpoints_str);
    waddstr(status_win, "> health.\n");

    wrefresh(status_win);
  }
}

bool lifeformcontrol::start_map(char *temp_filename) {
  bool flag = true;
  int x = 0, y = 0;
  char ch;
  ifstream infile(temp_filename);
  if (infile) {
    while (infile) {

      infile.get(ch);
      if (ch != 10) {
        mapchar[y][x] = ch;
        x++;
      } else if (ch == 10) // line feed (new line) detected
      {
        y++;
        x = 0;
      }
    }
  } else {
    wmove(map_win, 15, 20);
    waddstr(map_win, "The file <");
    waddstr(map_win, temp_filename);
    waddstr(map_win, "> does not exists. Press any key to quit... ");
    wrefresh(map_win);
    getch();
    flag = false;
  }
  wrefresh(map_win);

  return flag;
}

void lifeformcontrol::start_visiblemap() {
  for (int y = 0; y < 31; y++) {
    for (int x = 0; x < 91; x++) {
      visiblemap[y][x] = 0;
    }
  }
}
