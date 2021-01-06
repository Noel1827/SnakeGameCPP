#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;
bool gameOver;
const int witdh = 20;
const int height = 20;
int x,y,fruitX,fruitY,score,timer=0;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void SetUp(){
    gameOver = false;
    dir = STOP;
    x = witdh / 2;
    y = height / 2;
    fruitX= 14;
    fruitY = 14;
    score=0;
}
void Draw(){
    system("cls");
    for (int i = 0; i < witdh; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j <= witdh; j++){
            if (j == 0 || j == witdh - 1)
                cout << "#";
            else
                cout << " ";

             if(i==y && j==x)
                 cout << "O";
            else if(i==fruitX && j==fruitY)
                 cout << "F";
        }
        cout << endl;
    }

for(int i = 0; i < witdh; i++)
    cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;

 }


void Input(){
if(_kbhit()){
  switch(_getch()){
      case 'a':
      dir = LEFT;
      break;
      case 'd':
      dir = RIGHT;
      break;
      case 'w':
      dir = UP;
      break;
      case 's':
      dir = DOWN;
      break;
      case 'x':
      gameOver=true;
      break;

  }
}
}
void Logic(){
   
    timer++;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    for(int i = 1; i < nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i] = prevX;
        tailY[i] = prev
    }
    if(timer>10){
        timer=0;
switch(dir){
    case LEFT:
    x--;
    break;
    case RIGHT:
    x++;
    break;
    case UP:
    y--;
    break;
    case DOWN:
    y++;
    break;
    default:
    break;
    }
    if (x > witdh || x < 0 || y > height || y < 0)
        gameOver = true;
    }
        if (x == fruitX && y == fruitY){
            nTail++;
        score += 10;
        srand(time(NULL));
        fruitX = rand() % witdh;
        fruitY = rand() % height;
    }
}

int main(){

SetUp();
while(gameOver == false){
    Draw();
    Input();
    Logic();
    //Sleep(10);
}


    return 0;
}