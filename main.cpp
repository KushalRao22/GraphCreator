/*
A project that creates a graph using an adjacency matrix

Last modified: Kushal Rao

6/15/22
*/
//Imports
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//Making the verticies
struct vert {
	char name[50];
	vector <struct edge*> edges;
};
//Making the edges
struct edge {
	vert* start;
	vert* end;
	int weight;
};
//Method to check if there is a connection between two verticies
bool connection(vert* v1, vert* v2) {
  for (int i=0; i<v1->edges.size(); i++) {
    if (v1->edges[i]->end == v2) {
      return true;
    }
  }
  return false;
}
//Main
int main(){
	vector <vert*> verts; // Holds all verticies of the graph
	char input[50];
	bool quit = false;
	int size = 0;
	while(!quit){
		cout << "Type a valid command(AE(ADD EDGE), AV(ADD VERTEX), PRINT, RE(REMOVE EDGE), RV(REMOVE VERTEX), SP(SHORTEST PATH) QUIT)" << endl;//Prompt user for input
		cin >> input;
		if(strcmp(input, "AE") == 0){//If user wants to add an edge
			vert* start = NULL;//Create the vert to hold the starting vert
			vert* end = NULL;//Same for the end
			bool temp = true;//Bools for the loops 
			bool temp2 = true;
			while (temp) {
				cout << "Enter the starting node: "; 
				cin >> input;
				for (int i=0; i<verts.size(); i++) {//Check if the vert the user wants to start with exists
					if (strcmp(verts[i]->name,input) == 0) {
						start = verts[i];//If it does set it as the start
					}
				}
				if (start == NULL) {//If the user inputed node does not exist
					cout << "No node has that name." << endl;
				}
				else {
					temp = false;
				}
			}
			while (temp2) {
				cout << "Enter the end node: "; 
				cin >> input;
				for (int i=0; i<verts.size(); i++) {//Check for the ending node the user wants to use
					if (strcmp(verts[i]->name,input) == 0) {
						end = verts[i];//If it exists set it as end
					}
				}
				if (end == NULL) {
					cout << "No node has that label." << endl;//If it doesnt ask for another input
				}
				else {
					temp2 = false;
				}
			}
			int num;
			cout << "Enter the weight of the edge: "; 
			cin >> num;
			edge* n = new edge();//Create edge and set all the variables including weight
			n->start = start;
			n->end = end;
			n->weight = num;
			start->edges.push_back(n);//Add it to the vector of the starting vert
		}
		if(strcmp(input,"AV") == 0){//If user wants to add a vertex
			cout << "Enter the label for the new vertex: "; //Get name for the vert
			cin >> input;
			vert* n = new vert();
			strcpy(n->name, input);
			verts.push_back(n);//Add new vert to the vector

		}
		else if(strcmp(input, "RE")==0){//Remove an edge
			//Use basically the same code that was used to make the edge to find the edge
			vert* start = NULL;
			vert* end = NULL;
			bool temp;
			while (temp) {
				cout << "Enter the starting node of the edge:"; 
				cin >> input;
				for (int i=0; i<verts.size(); i++) {
					if (strcmp(verts[i]->name,input) == 0) {
						start = verts[i];
					}
				}
				if (start == NULL) {
					cout << "No node has that label." << endl;
				}
				else {
					temp = false;
				}
			}
			temp = true;
			while (temp) {
				cout << "Enter the end node" << endl;
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
					temp = false;
				}
			}
			if (!connection(start, end)) {//Check if a edge exists between the two points
				cout << "No edge" << endl;
			}
			else {//If there is an edge
				for (int i=0; i<start->edges.size(); i++) {
					if (start->edges[i]->end == end) {//Find the edge in the vector that is in the starting node
						start->edges.erase(start->edges.begin()+i);//Remove it from the vector once it is found
					}
				}
			}
		}
		else if(strcmp(input,"RV") == 0){//If user wants to remove a vert
			vert* removal = NULL;//vert to hold the vert we want to remove
			int index;
			cout << "Enter the vertex to delete: "; 
			cin >> input;
			for (int i=0; i<verts.size(); i++) {//find the vert in vector and its index
				if (strcmp(verts[i]->name,input) == 0) {
					removal = verts[i];
					index = i;
				}    
			}
			for (int i=0; i<verts.size(); i++) {//Go through all the verts to see if they point to the vert we want tor remove and if they do we remove them
				if (connection(verts[i],removal) == true) {
					for (int j=0; j<verts[i]->edges.size(); j++) {
						if (verts[i]->edges[j]->end == removal) {
							verts[i]->edges.erase(verts[i]->edges.begin()+i);
						}
					}
				}
			}
			//After removing all edges that point to the vert we delete the vert
			verts.erase(verts.begin()+index);
		}
		else if(strcmp(input,"PRINT") == 0){//If user wants to print adjacincy matrix
			for (int i=0; i<verts.size(); i++) {//Go through all the verts
				cout << verts[i]->name;
				for (int j=0; j<verts.size(); j++) {
					cout << "\t";//To have a second dimension of the array
					if (i == j) {
						cout << "X";//If the edge is supposed to be between the same point
					}
					else if (connection(verts[i],verts[j])) {//If there is an edge between the two points display the weight
						for(int k = 0; k < verts[i]->edges.size(); k++){
							if(verts[i]->edges[k]->end == verts[j]){
								cout << verts[i]->edges[k]->weight;
							}
						}

					}
					else {//If there is no edge
						cout << "0";
					}

				}
				cout << endl;
			}
		}
		else if(strcmp(input,"QUIT") == 0){//If user wants to quit
			quit = true;
		}
	}

	return 0;
}
