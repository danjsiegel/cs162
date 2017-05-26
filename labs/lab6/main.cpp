/* Dan Siegel
Lab6
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
struct Node{
	char data[201];
	Node *next;
};

void addToList(char tempData[], Node* &headPtr){
	Node *temp = new Node;
	strcpy(temp->data, tempData);
	temp->next = headPtr;
	headPtr=temp;
}
int main(){
	char *newData;
	newData = new char[201];
	Node *head = NULL;

	cout << "Enter Data" << endl;
	cin.getline(newData, 201);
	addToList(newData, head);
	while ((strcmp(newData, "quit")!=0)){
		cin.getline(newData, 201);
		if ((strcmp(newData, "quit")!=0)){
			addToList(newData, head);
		}
	}
	Node *transverse = head;
	while(transverse!=NULL){
	cout << transverse->data << endl;
	transverse = transverse->next;
	cout << transverse->data << endl;
	}
	delete [] newData;
	return 0;
}

