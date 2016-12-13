#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#define WIDTH 140
#define HEIGHT 40

using namespace std;

//time delay function:
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
    usleep( ms * 1000 );
    }

#endif
//end time delay function

class Universum{
public:
Universum(const char *_width="140", const char *_height="40"):width(atoi(_width)),height(atoi(_height)){
	srand(time(NULL));
	grid=new bool*[height];
	storage = new char*[height];
	generation=0;
	for(int i=0;i<height;i++){
		grid[i]=new bool[width];
		storage[i]=new char[width];
		for(int j=0;j<width;j++){
			grid[i][j]=(rand()%3==1?1:0);
			storage[i][j]=0;
			}
		}
			
} //konstruktor-inicjalizator
~Universum(){
	for(int i=0;i<height;i++){
		delete grid[i];
		delete storage[i];
		}
	delete *grid;
	delete *storage;
}
void putNeighbors(int x, int y){
	int i=x+height-1,j=y+width-1;
	storage[i%height][j%width]+=1;
	storage[i%height][y]+=1;
	storage[i%height][(j+2)%width]+=1;
	storage[x][j%width]+=1;              
	storage[x][(j+2)%width]+=1;
	storage[(i+2)%height][j%width]+=1;
	storage[(i+2)%height][y]+=1;
	storage[(i+2)%height][(j+2)%width]+=1;
} //funkcja dodajaca sasiadow do przechowalni

void nextGen(){
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			grid[i][j]=storage[i][j]==3?true:(storage[i][j]==2?grid[i][j]:false);
			storage[i][j]=0;
			}
		}
	generation++;
} //funkcja ustawiajaca nowe pokolenie komorek

void life(){
	for(int i=0;i<height;i++) for(int j=0;j<width;j++) if(grid[i][j]) putNeighbors(i,j);
	nextGen();
} //funkcja zmieniajaca stany tablic

void render(){
	char a;
	for(int j=0;j<width;j++) cout<<"-";
	cout<<endl;
	for(int i=0;i<height;i++){
		cout<<"|";
		for(int j=0;j<width;j++){
			a=grid[i][j]?'#':' ';
			cout<<a;
			}
		cout<<"|"<<endl;
		}
	for(int j=0;j<width-16;j++){
		cout<<"-";
		if(j==round((width-16)/2)) cout<<"Pokolenie: "<<generation;
		}
	cout<<endl;
} //funkcja renderujaca tablice i wyswietlajaca ja na konsoli

void Start(const char *ms){
	while(true){
		system("clear");
		render();
		delay(atoi(ms));
		life();
	}
}
bool **grid; //plansza z komorkami
char **storage; //przechowalnia dla liczby sasiadow

int width;//wymiary
int height;//wymiary

int generation; //numer pokolenia komorek
};

int main(int argc, char *argv[]){
	Universum A((argc>1?argv[1]:"140"),(argc>2?argv[2]:"40"));
	A.Start(argc==4?argv[3]:"50");
	return 0;

}
