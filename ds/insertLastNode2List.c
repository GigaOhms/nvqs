// https://mathhoang.blogspot.com/

struct node{
	int data;
	struct node *next;
};

struct node *getLastNode(struct node *head);

void insertNode(struct node **head, int data)
{

	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = data;
	if(*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		getLastNode(*head)->next = newNode;
	}
}

struct node *getLastNode(struct node *head)
{
	struct node *lastNode = head;
	if(head == NULL)
		return NULL;
	else{
		while(lastNode->next != NULL)
			lastNode = lastNode->next;
	}
	return lastNode;
}