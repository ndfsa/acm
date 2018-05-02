#include <iostream>
#include <cmath>
using namespace std;

int limit;
int count;
int direction;
/**
* direction = 0 : up
* direction = 1 : right
* direction = 2 : down
* direction = 3 : left
*/
int level;
int iter;
double xcoord;
double ycoord;
int numerator[520000];
int denominator[520000];
double value[520000];
void fillArrays();
bool verify(double number);
double absolute();
void found();
int main() {
  std::ios::sync_with_stdio(false);
  int a;
  int b;
  long long int number = 0;
  limit = 100;
  count = 0;
  xcoord = 0;
  ycoord = 0;
  level = 1;
  iter = 0;
  direction = 0;
  fillArrays();
  while(cin >> number) {
    if (number>limit) {
      limit = number + 1;
      fillArrays();
    }
    a = abs(numerator[number]);
    b = abs(denominator[number]);
    if (denominator[number]*numerator[number] < 0) {
      cout << "-" << a << " / " << b << endl;
    }else{
      cout << a << " / " << b << endl;
    }
  }
  return 0;
}
void found(){
  if (xcoord != 0 && verify(ycoord/xcoord)) {
    numerator[count] = ycoord;
    denominator[count] = xcoord;
    value[count] = ycoord/xcoord;
    value[count+1] = 80000;
    count++;
  }
  iter++;
}
bool verify(double number){
  double temp;
  for (int i = 0; i < count; i++) {
    temp = number - value[i];
    if(temp == 0){
      return false;
    }
  }
  return true;
}
void fillArrays(){
  switch (direction) {
    case 0: goto up;
    case 1: goto right;
    case 2: goto down;
    case 3: goto left;
  }
  while(count < limit){
    up:
      found();
      ycoord++;
      if (iter < level) {
        if (count >= limit) {
          direction = 0;
          break;
        }
        goto up;
      }else{
        iter = 0;
        if (count >= limit) {
          direction = 0;
          break;
        }
      }
    right:
      found();
      xcoord++;
      if (iter < level) {
        if (count >= limit) {
          direction = 1;
          break;
        }
        goto right;
      }else{
        iter = 0;
        level++;
        if (count >= limit) {
          direction = 0;
          break;
        }
      }
    down:
      found();
      ycoord--;
      if (iter < level) {
        if (count >= limit) {
          direction = 2;
          break;
        }
        goto down;
      }else{
        iter = 0;
        if (count >= limit) {
          direction = 0;
          break;
        }
      }
    left:
      found();
      xcoord--;
      if (iter < level) {
        if (count >= limit) {
          direction = 3;
          break;
        }
        goto left;
      }else{
        iter = 0;
        level++;
        if (count >= limit) {
          direction = 0;
          break;
        }
      }
  }
}
