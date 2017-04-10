#include <cstdio>

struct Node {
	int data;
	Node * next;
}  ;

bool findCircularTortoiseHare(Node *head)
{
   Node *slower, * faster;
   slower = head;
   faster = head->next; //start faster one node ahead
   while(true) {
   
     // if the faster pointer encounters a NULL element
     if( !faster || !faster->next)
       return false;
    //if faster pointer ever equals slower or faster's next
    //pointer is ever equal to slow then it's a circular list
     else if (faster == slower || faster->next == slower)
        return true;
     else{
       // advance the pointers
        slower = slower->next;
        faster = faster->next->next;
      }
   }
}

Node * newNode(int in_data)
{
	Node *node = new Node;
	node->data = in_data;
	node->next = NULL;
	return node;
}

int main()
{

	Node *head;
	bool is_circ;

	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* first run, simple non-circular */
	is_circ = findCircularTortoiseHare( head);

	if ( is_circ ) printf("Circular\n");
	else printf("Not circ\n");

	/* second run, make it circular halfway; 4 points back to 2 */
	head->next->next->next->next = head->next->next; // 4 points back to 2
	is_circ = findCircularTortoiseHare( head);

	if ( is_circ ) printf("Circular\n");
	else printf("Not circ\n");

}
