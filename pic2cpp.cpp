/*
  convert ppm file to cpp file
*/

#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

#define INFILE ".ppm"
#define OUTFILE ".cpp"

char s[100];

int main(int argc, char ** argv) {
  FILE *fin = fopen((string(argv[1]) + string(INFILE)).c_str(), "rb");
  FILE *fout = fopen((string(argv[1]) + string(OUTFILE)).c_str(), "wb");
  char color[3];
  
  fgets(s, 100, fin);
  fgets(s, 100, fin);
  fgets(s, 100, fin);

  while(!feof(fin)) {
    fread(color, 1, 3, fin);
    if(color[0] == -1) break;
    fputc(color[0], fout);
  }
  
  fclose(fin);
  fclose(fout);
}