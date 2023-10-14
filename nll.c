#include <stdio.h>
#include <stdlib.h>
struct Node 
{
  int data;
  struct Node* next;
};
struct Ll 
{
  struct Node* head;
};
 struct Ll* create(int size)
{
  struct Ll* list = (struct Ll*)malloc(sizeof(struct Ll));

  if ( list == NULL)
  {
    printf("NOT ENOUGHT MEMMORY");
  }  
  list->head = (struct Node*)malloc(sizeof(struct Node));
  if ( list->head == NULL)
  {
    printf("NOT ENOUGHT MEMMORY");
  }
  struct Node* selector = list->head;
  for (int  i = 1; i < size; i++)
  
  {
    selector=selector->next=(struct Node*)malloc(sizeof(struct Node));
  }
  int counter=0;
  for (struct Node* selector = list->head;selector!=NULL;selector=selector->next)
  
  {
    printf("Please enter the value of node number\n %d",counter+1);
    scanf("%d",&selector->data);
  }
  return list;
}
struct Ll print(struct Ll* ptr) //code to print a linked list
{
  
  for ( struct Node* selector = ptr->head; selector!=NULL; selector = selector->next)
  {  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("%d \t",selector->data);
  }
  
}
void begins(struct Ll* list,int x)//basic code to insert at the start of the linked list
{
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  if(newnode==NULL)
  {
    printf("ERROR NOT ENOUGH MEMMORY");
  }

  else{newnode->data = x;
  newnode->next = list->head;
  list->head=newnode;
}}
void endins(struct Ll* list,int x)//basic code to insert at the end of a linked list
{
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = x;
  if (newnode==NULL)
  {
    printf("ERROR NOT ENOUGH MEMMORY");
    exit(0);
  }
  struct Node* selector=list->head;
  while ((selector)->next != NULL )
  {
    selector=selector->next;
  }
  selector->next=newnode;
  newnode->next=NULL;
}
void midins(struct Ll* list,int x,int pos)//basic code to insert at a given node of a linked list
{
  struct Node* p1=list->head;
  struct Node* p2=list->head;
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  if (newnode==NULL)
  {
    printf("ERROR NOT ENOUGH MEMMORY");
    exit(0);
  }
  newnode->data=x;
  for(int i = 0;i<pos-2;i++)
  {
    p1 = p1->next;
  }
  p2=p1->next;
  p1->next=newnode;
  newnode->next=p2;
}
void begdel(struct Ll* List)//basic code to delete at the start of a linked list
{
  struct Node* s=List->head;
  List->head=List->head->next;
  free(s);
}
void endel(struct Ll* List)//code to delete element at end and assumes that there is at least 1 element 
{
  struct Node* nf= List->head;
  while (nf->next!=NULL)
  {
   nf=nf->next; 
  }
  struct Node* nff= List->head;
  while (nff->next!=nf)
  {
   nff=nff->next; 
  }
  free(nf);
  nff->next!=NULL;
  
  

  
} 
void flipper(struct Ll* list)//this code assumes that the linked list is at least 3 elements long
{
  struct Node*slast = list->head;
  struct Node*select = slast->next;
  struct Node* thirdNode = select->next;
  while (select!=NULL)//fix the dumbass
  {
    select->next=slast;
    slast=select;
    select=thirdNode;
    if (select!=NULL)
    {
      thirdNode=thirdNode->next;
    }
    
    
  }
  list->head->next=NULL;
  list->head=slast;
  

}
void middel(struct Ll* list, int pos)
{
    struct Node* prev = list->head; // Initialize prev to the head of the list
    struct Node* nnext;
    
    if (pos == 1) {
        list->head = prev->next; // Update the head to the next node
    } else {
        for (int i = 0; i < pos - 2; i++) {
            prev = prev->next;
        }
        nnext = prev->next;
        prev->next = nnext->next;
    }
    
    free(nnext);
}

int main()
{
  struct Ll* thermo = create(5);
  //begins(thermo,42);
  //endins(thermo,54);
  //midins(thermo,69,3);
  //endel(thermo);
  middel(thermo,3);
  //flipper(thermo);
  print(thermo);
}
