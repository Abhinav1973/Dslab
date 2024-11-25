#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
int count = 0;

void display() {
	struct node *temp = head;
	if (temp == NULL) {
	printf("Empty Linked list\n");
	}
	else {
		while (temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
	printf("NULL\n");
	}
}
void in_beg() {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	if (head == NULL) {
		head = newnode;
		newnode->next = NULL;
	}
	else {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	count++;
	//printf("Node inserted at the beginning.\n");
}
void in_end() {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *temp = head;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
		if (head == NULL) {
		head = newnode;
		newnode->prev = NULL;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
	count++;
	printf("Node inserted at the end.\n");
}
void in_pos() {
	int pos;
	printf("Enter the position to insert: ");
	scanf("%d", &pos);
	if (pos < 1 || pos > count + 1) {
		printf("Invalid position!\n");
		return;
	}
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *temp = head;
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	if (pos == 1) {
		newnode->prev = NULL;
		newnode->next = head;
		if (head != NULL) head->prev = newnode;
		head = newnode;
	} 
	else {
		for (int i = 1; i < pos - 1; i++) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		if (temp->next != NULL) temp->next->prev = newnode;
		newnode->prev = temp;
		temp->next = newnode;
	}
	count++;
	//printf("Node inserted at position %d.\n", pos);
}
void del_beg() {
	if (count == 0) {
		printf("Empty linked list\n");
	}
	else {
		struct node *temp = head;
		head = head->next;
		if (head != NULL) head->prev = NULL;
		free(temp);
		count--;
		printf("Node deleted from the beginning.\n");
		//printf("%d is deleted\n", temp -> data);
	}
}
void del_end() {
	if (head == NULL) {
		printf("Invalid operation, list is empty.\n");
	}
	else if (head->next == NULL) {
		free(head);
		head = NULL;
		count--;
		printf("Node deleted from the end.\n");
	}
	else {
		struct node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
		count--;
		printf("Node deleted from the end.\n");
	}
}

void del_pos() {
	int pos;
	printf("Enter the position to delete: ");
	scanf("%d", &pos);
	if (pos < 1 || pos > count) {
		printf("Invalid position!\n");
		return;
	}
	if (pos == 1) {
		del_beg();
	}
	else {
		struct node *temp = head;
		for (int i = 1; i < pos; i++) {
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		if (temp->next != NULL) temp->next->prev = temp->prev;
		free(temp);
		count--;
		printf("Node deleted from position %d.\n", pos);
	}
}

int main() {
	int choice;
	while (1) {
		printf("1. INSERT AT BEG\n");
		printf("2. INSERT AT END\n");
		printf("3. INSERT AT POSITION\n");
		printf("4. DELETE FROM BEG\n");
		printf("5. DELETE FROM END\n");
		printf("6. DELETE FROM POSITION\n");
		printf("7. DSPLAY\n");
		printf("8. EXIT\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				in_beg();
				break;
			case 2:
				in_end();
				break;
			case 3:
				in_pos();
				break;
			case 4:
				del_beg();
				break;
			case 5:
				del_end();
				break;
			case 6:
				del_pos();
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}

return 0;
}
