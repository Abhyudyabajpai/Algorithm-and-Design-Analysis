#include<iostream>
using namespace std;
//node structure for doubly linked list
struct node{
   int data;
   struct node *next;
   struct node *prev;
};
//node creation
struct node* getNode(){
   return ((struct node *)malloc(sizeof(struct node)));
}
//printing the list
int print_list(struct node *temp){
   struct node *t = temp;
   if(temp == NULL)
   return 0;
   else {
      cout<<"List: ";
      while(temp->next != t) {
         cout<<temp->data<<" ";
         temp = temp->next;
      }
      cout<<temp->data;
      return 1;
   }
}
//converting array to linked list
void convert_array(int arr[], int n, struct node **start) {
   //declaring new pointer
   struct node *newNode,*temp;
   int i;
   //moving through all the elements
   for(i=0;i<n;i++){
      newNode = getNode();
      newNode->data = arr[i];
      if(i==0) {
         *start = newNode;
         newNode->prev = *start;
         newNode->next = *start;
      } else  {
         //calculating the last node
         temp = (*start)->prev;
         temp->next = newNode;
         newNode->next = *start;
         newNode->prev = temp;
         temp = *start;
         temp->prev = newNode;
      }
   }
}
int main(){
   int arr[] = {1,2,3,4,5};
   int n = sizeof(arr) / sizeof(arr[0]);
   struct node *start = NULL;
   convert_array(arr, n, &start);
   print_list(start);
   return 0;
}
