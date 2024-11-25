#include <stdio.h>
#include <stdlib.h>
struct node{

	int data;
	struct node *next;

};
struct node *top=NULL;
void push(){
        int item;
        struct node *newnode;
        newnode =(struct node*)malloc(sizeof(struct node));
        printf("Enter value to push: ");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=top;
        top=newnode;
        display();
}

void pop(){
        if(top==NULL){
                printf("Stack is empty.");
        }
        else{
                struct node *temp;
                temp=top;
                printf("\n popped value is %d",top->data);
                top=top->next;
                free(temp);
        }

}
void display(){

                if(top==NULL)
		{
                        printf("stack is empty.");

                  }
                else
		{
                        struct node *temp;
                        temp=top;
                        while(temp!=NULL)
				{
                                printf("%d ",temp->data);
                                temp=temp->next;

                            }
		   }

                }
void search(){

		int key,flag=0;
		struct node *temp=top;
		printf("Enter value to search: ");
		scanf("%d",&key);
		while(temp!=NULL){
			if(temp->data==key){
			flag=1;
			break;

			}
			temp=temp->next;

		}
		if(flag==1){

			printf("value %d is found",temp->data);

			}
		else{
			printf("value is not in the stack.");

			}





}

int main(){
	int choice,k=0;
     while(k==0){
	printf("\n1.push\n2.pop\n3.display\n4.search\n5.exit\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		push();
		break;
	case 2:
                pop();
                break;
        case 3:
		display();
                break;

	case 4:
                search();
                break;
	case 5:exit(0);

	default:printf("Invalid choice");


	 }
     }
return 0;

}
