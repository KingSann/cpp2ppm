/*
  convert cpp file to ppm file
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

#define INFILE ".cpp"
#define OUTFILE ".ppm"

int WID = 0;
int HEI = 0;

int getSize(string name) {
  FILE *fin = fopen(name.c_str(), "rb");
  fseek(fin, 0, SEEK_END);
  int size=ftell(fin);
  fclose(fin);
  return size;
}

char color[3];
int tmp = 0;

void bd(char c) {
  color[0] = (c) & 255;
  color[1] = (1 + (rand() % 255)) & 255;
  color[2] = (1 + (rand() % 255)) & 255;
}

int main(int argc, char **argv) {

  int size = getSize(string(argv[1]) + string(INFILE));

  srand(size);

  FILE *fin = fopen((string(argv[1]) + string(INFILE)).c_str(), "rb");
  FILE *fout = fopen((string(argv[1]) + string(OUTFILE)).c_str(), "wb");


  WID = sqrt(size);
  HEI = ceil(size * 1.0 / WID);
  fprintf(fout, "P6\n%d %d\n255\n", WID, HEI);
  while(!feof(fin)) {
    tmp ++;

    char c = fgetc(fin);

    bd(c);

    fwrite(color, 1, 3, fout);
  }

  for( ; tmp <= WID * HEI ; tmp ++) {
    bd(32);

    fwrite(color, 1, 3, fout);
  }

  fclose(fin);
  fclose(fout);
}
