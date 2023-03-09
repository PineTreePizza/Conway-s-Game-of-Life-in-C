#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int width = 60;
const int height = 40;

int chance(int n) {
  if (rand() % 100 <= n)
    return 1;
  else
    return 0;
}

void arrFill(char *arr, int n) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (chance(n))
        arr[i * width + j] = '#';
      else
        arr[i * width + j] = ' ';
    }
  }
}
void printArr(char *arr) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++)
      printf("%c ", arr[i * width + j]);
    printf("\n");
  }
}
void iterateArray(char *arr) {
  int neighbors = 0;
  char *temp = (char *)malloc(sizeof(char) * (width * height));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++) {
          int x = l - 1;
          int y = k - 1;
          if (arr[(i + y) * width + j + x] == '#' && !(x==0 && y==0))
            neighbors++;
        }

      if ((neighbors == 3 || neighbors == 2) && arr[i * width + j] == '#')
        temp[i * width + j] = '#';
      else if (neighbors == 3 && arr[i * width + j] == ' ')
        temp[i * width + j] = '#';
      else
        temp[i * width + j] = ' ';
      neighbors = 0;
    }
  }
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      arr[i * width + j] = temp[i * width + j];
}
int main() {
  srand(time(NULL));
  char *arr = (char *)malloc(sizeof(char) * (width * height));
  arrFill(arr, 30);
  while (1) {
    printArr(arr);
    iterateArray(arr);
    usleep(100000);
    system("clear");
  }
  return 0;
}
