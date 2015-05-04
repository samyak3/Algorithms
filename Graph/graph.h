typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* getNode(int data);

void bfs(Node*);

void dfs(Node*);
