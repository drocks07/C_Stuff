#include<stdio.h>
#include<stdlib.h>
#define next link
struct node {
	int data;
        struct node *link;
};

struct node *root,*current;
void insert (void);
void display (void);
void reverse (void);
void sort_ascending (void);
void sort_descending (void);
void reverse_without_ptr(void);
int main () {
    int ch;
    while (1) {
          printf("1. Insert 2. Display \n3. Reverse 4. Sort_ascending \n5. Sort_descending 6.Revese_w/o_ptr 7. Exit\n");
          printf("Enter your choice\n");
          scanf("%d",&ch);
	  switch (ch) {
		case 1 :
			insert();
			break;
		case 2: 
			display();
			break;
		case 3:
			reverse();
			break;
                case 4 :
			sort_ascending();
			break;
		case 5 :
			sort_descending();
			break;
		case 6 :
			reverse_without_ptr();
			break;
		case 7:
			exit(0);
          }
    }
return 0;
}

void insert (void) {
     struct node *temp;
     temp = (struct node *) malloc(sizeof(struct node));
     printf("Enter data\n");
     scanf("%d",&temp->data);
     temp->link=NULL;
     
     if (NULL==root) {
	current=root=temp;
     }
     else {
        current->link = temp;
        current = temp;
     }
}

void display (void) {
     struct node *temp;
     temp=root;
     if (NULL==root) {
	printf("No elements\n");
     }
     else {
        while (temp) {
              printf("The data is %d\n",temp->data);
	      temp=temp->link;
        }
     }
}

void reverse (void) {
     struct node *current,*next,*previous;
     current=root;
     previous=NULL;
     if (NULL==root) {
        printf("No elements to reverse\n");
     }
     else {
        while (current) {
              next = current->link;
              current->link = previous;
	      previous = current;
              current = next;
        }
     root=previous;
     }
}

void sort_ascending (void) {
     struct node *i,*j;
     int temp;
     for (i=root;i->link!=NULL;i=i->link) {
         for (j=i->next;j;j=j->next) {
             if (i->data > j->data) {
		temp = i->data;
		i->data =j->data;
		j->data=temp;
             }
	  }
     }
}

void sort_descending (void) {
     struct node *i,*j;
     int temp; 
     for (i=root;i->link!=NULL;i=i->link) {
	 for (j=i;j!=NULL;j=j->link) {
	     if (i->data < j->data) {
		temp=j->data;
		j->data=i->data;
		i->data=temp;
             }
         }   
     }
}

int length (void) {
    struct node *temp;
    int len=0;
    temp=root;
    while (temp) {
         temp=temp->link;
         len++;
    }
    return len;
}

void reverse_without_ptr (void) {
	struct node *temp;
        temp=root;
        int size = length();
        int arr[size];
        int i;
        for (i=0;i<size;i++) {
            arr[i]=temp->data;
            temp=temp->link;
	}
        temp=root;
	for (i=size-1;i>=0;i--) {
             temp->data=arr[i];
	     temp=temp->link;
	}
        
}
