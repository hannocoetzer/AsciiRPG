# ASCII Game (C++ Ncurses)

This is a terminal-based ASCII game written in C++ using `ncurses` for rendering and standard C++ threads for timing and control.

---

## 📦 Dependencies

Install the following packages on Debian/Ubuntu:

```bash
sudo apt-get install g++ build-essential libncurses5-dev libncursesw5-dev gdb valgrind cppcheck ccache cmake libgtest-dev libpthread-stubs0-dev

g++ -g -pthread -c *.cpp
g++ -g -pthread -no-pie *.o -lncurses -o Game

```
