typedef struct mnode
{
	int data;
	int weight;
	struct mnode* next;
}MNode;
typedef struct node
{
	int data;
	struct node* next;
}Node;
Node* getNode(int data);
MNode* getMNode(int data, int w);

void bfs(Node*);

void dfs(Node*);

void KMST();