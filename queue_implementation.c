#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
typedef struct queue
{
  node *front;
  node *rear;
}queue;
void push(queue *head,int data){
  node *new_node=(node *)malloc(sizeof(node));
  new_node->data=data;
  new_node->next=NULL;
  if(head->front==NULL)
  {
    head->front=new_node;
    head->rear=new_node;
  }
  else
  {
    head->rear->next=new_node;
    head->rear=head->rear->next;
  }
}
void printQueue(queue *head)
{
  node *temp=head->front;
  while(temp)
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
int isEmpty(queue *head)
{
  if(head->front==NULL)
  {
    return 1;
  }
  return 0;
}
int front(queue *head)
{
  return head->front->data;
}
int end(queue *head)
{
  return head->rear->data;
}
void pop(queue *head)
{
  node *temp=head->front;
  head->front=head->front->next;
  free(temp);
  if(head->front==NULL)
  {
    head->rear=NULL;
  }
}
int main()
{
  queue *head=(queue *)malloc(sizeof(head));
  head->front=NULL;
  head->rear=NULL;
  printf("Is queue empty:%d\n",isEmpty(head));
  push(head,1);
  printQueue(head);
  push(head,2);
  printQueue(head);
  push(head,3);
  printQueue(head);
  printf("Is queue empty:%d\n",isEmpty(head));
  printf("First element in queue is %d\n",front(head));
  printf("Last element in queue is %d\n",end(head));
  printf("After pop,queue is\n");
  pop(head);
  printQueue(head);
  printf("After pop,queue is\n");
  pop(head);
  printQueue(head);
  printf("After pop,queue is\n");
  pop(head);
  printQueue(head);
  return 0;
}
