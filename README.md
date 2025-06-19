# ASCII Game (C++ Ncurses)

This is a terminal-based ASCII game written in C++ using `ncurses` for rendering and standard C++ threads for timing and control.

---

## 📦 Dependencies

Install the following packages on Debian/Ubuntu:

```bash
sudo apt-get install g++
sudo apt-get install build-essential libncurses5-dev libncursesw5-dev gdb valgrind cmake libpthread-stubs0-dev
sudo apt-get install libncurses5-dev libncursesw5-dev
sudo apt-get install libncurses-dev

```
If some issues persist
```
sudo apt-get clean
sudo apt-get update
sudo apt --fix-broken install
```

Compile
```
g++ -g -pthread -c *.cpp
g++ -g -pthread -no-pie *.o -lncurses -o Game

```
Run
```
chmod + x Game
./Game
```
