#include <iostream>
#include <new>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
struct node {
   int data;
   struct node *next;
   struct node *prev;
};
node *createList(int *arr, int n){
   node *head, *p, *q;
   p = head = new node;
   head->data = arr[0];
   head->prev = NULL;
   head->next = NULL;
   for (int i = 1; i < n; ++i) {
      q = new node;
      q->data = arr[i];
      q->prev = p;
      q->next = NULL;
      p->next = q;
      p = q;
   }
   return head;
}
void displayList(node *head){
   while (head != NULL) {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}
node *mergeSortedLists(node *head1, node *head2){
   node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   if (head1->data < head2->data) {
      head1->next = mergeSortedLists(head1->next, head2);
      head1->next->prev = head1;
      head1->prev = NULL;
      return head1;
   } else {
      head2->next = mergeSortedLists(head1, head2->next);
      head2->next->prev = head2;
      head2->prev = NULL;
      return head2;
   }
}
void splitList(node *src, node **fRef, node **bRef){
   node *fast;
   node *slow;
   slow = src;
   fast = src->next;
   while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
         slow = slow->next;
         fast = fast->next;
      }
   }
   *fRef = src;
   *bRef = slow->next;
   slow->next = NULL;
}
void mergeSort(node **head){
   node *p = *head;
   node *a = NULL;
   node *b = NULL;
   if (p == NULL || p->next == NULL) {
      return;
   }
   splitList(p, &a, &b);
   mergeSort(&a);
   mergeSort(&b);
   *head = mergeSortedLists(a, b);
}
int main(){
   int arr[] = {10, 20, 8, 17, 5, 13, 4};
   node *head;
   head = createList(arr, SIZE(arr));
   cout << "Unsorted list: " << endl;
   displayList(head);
   mergeSort(&head);
   cout << "Final sorted list: " << endl;
   displayList(head);
   return 0;
}
