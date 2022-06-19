// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* nNode=head;
        
        while(curr!=NULL){
            nNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nNode;
        }
        
        return prev;
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node* prev1=NULL;
        Node* temp=head;
        int ct=1;
        
        while(ct<m && temp!=NULL){
            prev1=temp;
            temp=temp->next;
            ct++;
        }
        Node* h1=temp;
        if(prev1){
            prev1->next=NULL;
        }
        
        Node* prev2=NULL;
        
        while(ct<=n && temp!=NULL){
            prev2=temp;
            temp=temp->next;
            ct++;
        }
        if(prev2)
            prev2->next=NULL;
            
        Node* revHead=reverse(h1);
        
        Node* fhead=head;
        
        if(prev1){
            prev1->next=revHead;
        }
        else{
            fhead=revHead;
        }
        h1->next=temp;
        return fhead;
        
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends