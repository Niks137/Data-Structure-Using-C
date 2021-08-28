#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

struct node* createnode()
{
	int x;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("MEMORY NOT ALLOCATED...");
	}

	else
	{
		printf("ENTER A VALUE\n");
		scanf_s("%d", &x);
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

void createlinkedlist(struct node** head)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;
	newnode = createnode();

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode;
	}
}

void displaylinkedlist(struct node* head)
{
	if (head == NULL)
	{
		printf("LINKED LIST NOT EXIT....");
	}
	else
	{
		while (head != NULL)
		{
			printf("%d=>", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void insertatfirst(struct node** head)
{
	struct node* newnode = NULL;
	newnode = createnode();
	if (newnode == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
}

void insertatlast(struct node** head)
{
	createlinkedlist(head);
}

int countnode(struct node* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void insertatposition(struct node** head)
{
	struct node* newnode = NULL;
	int pos, no_of_node, count;
	printf("ENTER A POSITION:\n");
	scanf_s("%d", &pos);
	no_of_node = countnode(*head);

	if (pos == 1)
	{
		insertatfirst(head);
	}
	else if (pos == no_of_node + 1)
	{
		insertatlast(head);
	}
	else if (pos < 1 || pos > no_of_node + 1)
	{
		printf("INVALID POSITION:\n");
		insertatposition(head);
	}
	else
	{
		int i;

		newnode = createnode();
		struct node* tempnode = *head;
		for (i = 0; i < pos - 1; i++)
		{
			tempnode = tempnode->next;
		}
		newnode->next = tempnode->next;
		tempnode->next = newnode;
	}
}

void deleteatfirst(struct node** head)
{
	struct node* tempnode = *head;
	if (*head == NULL)
	{
		printf("LINKED LIST NOT EXIT\n");
	}
	else
	{
		*head = tempnode->next;
		free(tempnode);
	}
}

void deleteatlast1(struct node** head)
{
	if (*head == NULL)
	{
		printf("LINKED LIST NOT EXIT...\n");
	}
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else if ((*head)->next->next == NULL)
	{
		free((*head)->next);
		(*head)->next = NULL;
	}
	else
	{
		struct node* tempnode1 = *head;
		struct node* tempnode2 = *head;
		while (tempnode1->next != NULL)
		{
			tempnode2 = tempnode2->next;
			tempnode1 = tempnode2->next;
		}
		free(tempnode1);
		tempnode2->next = NULL;

	}
}

void main()
{
	int choice;
	struct node* first = NULL;
	do
	{
		printf("🤩️....MENU IS HERE ....🤩️\n");
		printf("1. CREATE LINKED LIST:\n");
		printf("2. DISPLAY LINKED LIST:\n");
		printf("3. INSERT AT FIRST:\n");
		printf("4. INSERT AT LAST:\n");
		printf("5. INSERT AT POSITION:\n");
		printf("6. DELETE AT FIRST:\n");
		printf("7. DELETE AT LAST1:\n");

		printf("0.EXIT\n");

		printf("ENTER YOUR CHOICE\n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:createlinkedlist(&first);
			break;

		case 2:displaylinkedlist(first);
			break;

		case 3:insertatfirst(&first);
			break;

		case 4:insertatlast(&first);
			break;

		case 5:insertatposition(&first);
			break;

		case 6:deleteatfirst(&first);
			break;

		case 7:deleteatlast1(&first);
			break;




		}
	} while (choice != 0);

	printf("🤗️...........THANK YOUUU............🤗️\n");
}
