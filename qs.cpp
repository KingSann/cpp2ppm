/*
	quick see ppm file
*/

#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

#define INFILE ".ppm"

char s[100];

int main(int argc, char ** argv) {
  FILE *fin = fopen((string(argv[1]) + string(INFILE)).c_str(), "rb");
  char color[3];
  
  fgets(s, 100, fin);
  fgets(s, 100, fin);
  fgets(s, 100, fin);

  while(!feof(fin)) {
    fread(color, 1, 3, fin);
    if(color[0] == -1) break;
    putchar(color[0]);
  }
  
  fclose(fin);
}