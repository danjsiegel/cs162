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

void addToList(Node* &headPtr){
	char tempData[201];
	cout << "New Data: ";
	cin >> tempData;	
	Node *temp = new Node;
	temp->next = NULL;
	Node *current = headPtr;
	Node *previousNode = headPtr;
	strcpy(temp->data, tempData);
	if (headPtr == NULL) {
		headPtr = temp;
		return;
	}else if (strcmp(headPtr->data,tempData) >= 0) {
		temp->next = headPtr;
		headPtr=temp;
	} else{
		while (current->next != NULL){
		previousNode=current;
		current=current->next;
		if (strcmp(current->data,tempData) >= 0){
			previousNode->next = temp;
			temp->next = current;
			cout << "value added" << endl;
			return;
			}
		}
	}
	if (current->next == NULL){
		current->next = temp;
		temp->next = NULL;
	}
}

void deleteFromList(Node* &headPtr){
	char tempData[201];
	cout << "Data to Delete: ";
	cin >> tempData;	
	Node *current = new Node;
	Node *trailingNode = new Node;
	Node *deleteNode = NULL;
	current = headPtr;
	trailingNode = headPtr;
	if (headPtr != NULL && (strcmp(current->data, tempData)==0)){
		deleteNode = headPtr;
		headPtr = headPtr->next;
		delete deleteNode;
		return;
	}
	while (current != NULL && (strcmp(current->data, tempData)!=0)){
		trailingNode = current;
		current = current->next;
	}
	if (current == NULL){
		cout << "Value not Found" << endl;
	} else {
		deleteNode = current;
		current = current->next;
		trailingNode->next=current;
		delete deleteNode;
	}	
}
void transverseList(Node* &headPtr){
	Node *transverse = headPtr;
	while(transverse!=NULL){
		cout << transverse->data << endl;
		transverse = transverse->next;
	}
	delete transverse;
}
void deleteNodes(Node* &headPtr){
	Node *transverse = headPtr;
	Node *last= NULL;
	while(transverse!=NULL){
		last = transverse;
		transverse = transverse->next;
		delete last;
	}
	delete transverse;
}
int main(){
	int action = 0;
	Node *head = NULL;
	while (action != 4){
		cout << "Menu\n\n" << "1 - Add to List\n" << "2 - Delete from List\n" << "3 - Print List\n" << "4 - Quit" << endl;
		cin >> action;
		switch (action){
			case 1:
				addToList(head);
				break;
			case 2:
				deleteFromList(head);
				break;
			case 3:
				transverseList(head);
				break;
			case 4:
				cout << "goodbye" << endl;
				break;
			default:
				cin.clear();
				cin.ignore();
				break;
			}
	}
	return 0;
}

