#include <iostream>
#include <cstring>

using namespace std;

struct vert{
  char name[100];
};

struct edge{
  vert* vert1 = NULL;
  vert* vert2 = NULL;
  int weight = 0;
};


void aVertex(vert** verts, int &size);
void aEdge(vert** verts, edge** edges);
void rmVertex(vert** verts);
void rmEdge(vert** verts, edge** edges);


int main(){
  vert** verts = new vert*[1];
  edge** edges = new edge*[1];
  char input[7];
  bool quit = false;
  int size = 0;
  while(!quit){
    cout << "Type a valid command(AE(ADD EDGE), AV(ADD VERTEX), PRINT, RE(REMOVE EDGE), RV(REMOVE VERTEX), SP(SHORTEST PATH) QUIT)" << endl;//Prompt user for input
    cin >> input;
    if(strcmp(input, "AE") == 0){
      
    }
    if(strcmp(input,"AV") == 0){//If user wants to add students
      vert** temp = new vert*[(sizeof(verts)/sizeof(verts[0]))+1];
      cout << (sizeof(verts)/sizeof(verts[0])) << endl;
      delete verts;
      verts = temp;
      cout << (sizeof(verts)/sizeof(verts[0])) << endl;
      aVertex(verts, size);
    }
    else if(strcmp(input, "RE")==0){
      
    }
    else if(strcmp(input,"RV") == 0){//If user wants to delete a specific student
      
    }
    else if(strcmp(input,"PRINT") == 0){//If user wants to print a specific student
      cout << (sizeof(verts)/sizeof(verts[0])) << endl;
      for(int i = 0; i < (sizeof(verts)/sizeof(verts[0])); i ++){
	cout << verts[i]->name << endl;
      }
    }
    else if(strcmp(input,"SP") == 0){//If user wants to print a specific student
      
    }
    else if(strcmp(input,"QUIT") == 0){//If user wants to quit
      quit = true;
    }
  }
  
  return 0;
}

void aVertex(vert** verts, int &size){
  char temp[100];
  cout << "What is the name of the vertex" << endl;
  cin >> temp;
  cin.clear();
  vert* n = new vert;
  strcpy(n->name, temp);
  verts[size] = n;
  size++;
}
