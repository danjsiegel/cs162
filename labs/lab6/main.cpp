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
	Node *lastNode = NULL;
	strcpy(temp->data, tempData);
	if (headPtr == NULL){
		headPtr=temp;
		return;
	}
	lastNode=headPtr;
	while (lastNode->next!=NULL){
		lastNode=lastNode->next;
	}
	temp->next=NULL;
	lastNode->next = temp;
}
void transverseList(Node* &headPtr){
	Node *transverse = headPtr;
	while(transverse!=NULL){
		cout << transverse->data << endl;
		transverse = transverse->next;
	}
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
	transverseList(head);
	delete [] newData;
	return 0;
}

