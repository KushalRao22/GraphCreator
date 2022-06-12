#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


struct vert {
	char name[50];
	vector <struct edge*> edges;
};

struct edge {
	vert* start;
	vert* end;
	int weight;
};

bool connection(vert* v1, vert* v2) {
  // checks if a directed edge from n1 to n2 exists
  for (int i=0; i<v1->edges.size(); i++) {
    if (v1->edges[i]->end == v2) {
      return true;
    }
  }
  return false;
}

int main(){
	vector <vert*> verts;
	char input[50];
	bool quit = false;
	int size = 0;
	while(!quit){
		cout << "Type a valid command(AE(ADD EDGE), AV(ADD VERTEX), PRINT, RE(REMOVE EDGE), RV(REMOVE VERTEX), SP(SHORTEST PATH) QUIT)" << endl;//Prompt user for input
		cin >> input;
		if(strcmp(input, "AE") == 0){
			vert* start = NULL;
			vert* end = NULL;
			bool temp = true;
			bool temp2 = true;
			while (temp) {
				cout << "Enter the starting node: "; 
				cin >> input;
				for (int i=0; i<verts.size(); i++) {
					if (strcmp(verts[i]->name,input) == 0) {
						start = verts[i];
					}
				}
				if (start == NULL) {
					cout << "No node has that name." << endl;
				}
				else {
					temp = false;
				}
			}
			while (temp2) {
				cout << "Enter the end node: "; 
				cin >> input;
				for (int i=0; i<verts.size(); i++) {
					if (strcmp(verts[i]->name,input) == 0) {
						end = verts[i];
					}
				}
				if (end == NULL) {
					cout << "No node has that label." << endl;
				}
				else {
					temp2 = false;
				}
			}
			int num;
			cout << "Enter the weight of the edge: "; 
			cin >> num;
			edge* n = new edge();
			n->start = start;
			n->end = end;
			n->weight = num;
			start->edges.push_back(n);
		}
		if(strcmp(input,"AV") == 0){//If user wants to add students
			cout << "Enter the label for the new vertex: "; 
			cin >> input;
			vert* n = new vert();
			strcpy(n->name, input);
			verts.push_back(n);

		}
		else if(strcmp(input, "RE")==0){

		}
		else if(strcmp(input,"RV") == 0){//If user wants to delete a specific student
			vert* removal = NULL;
			int index;
			cout << "Enter the vertex to delete: "; 
			cin >> input;
			for (int i=0; i<verts.size(); i++) {
				if (strcmp(verts[i]->name,input) == 0) {
					removal = verts[i];
					index = i;
				}    
			}
			for (int i=0; i<verts.size(); i++) {
				if (connection(verts[i],removal) == true) {
					for (int j=0; j<verts[i]->edges.size(); j++) {
						if (verts[i]->edges[j]->end == removal) {
							verts[i]->edges.erase(verts[i]->edges.begin()+i);
						}
					}
				}
			}
			verts.erase(verts.begin()+index);
		}
		else if(strcmp(input,"PRINT") == 0){//If user wants to print a specific student
		}
		else if(strcmp(input,"SP") == 0){//If user wants to print a specific student

		}
		else if(strcmp(input,"QUIT") == 0){//If user wants to quit
			quit = true;
		}
	}

	return 0;
}
