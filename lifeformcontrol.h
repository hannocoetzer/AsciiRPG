
#ifndef _LIFECONTROL_H_
#define _LIFECONTROL_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <pthread.h>
#include <string>
#include <unistd.h>

#include "creature.h"
// #include "windows.h"
#include "mapvar.h"
#include "trecrewea.h"
#include "winvar.h"

class lifeformcontrol {
public:
  lifeformcontrol();
  bool start_gamecontrol(int);
  void start_windows();
  void collision_check();
  void attack();
  bool parry();
  bool checkhealth();
  void creature_detail();
  void hero_detail();
  bool start_map(char *);
  void start_visiblemap();

private:
  int creature_collision_no; // the creature no where collision is detected
  char *str_array[6];
  int count;
  int mapweaponcount;
  int treasurecount;
  int creaturecount;
};

#endif
