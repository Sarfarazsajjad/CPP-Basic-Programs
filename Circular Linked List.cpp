#include <iostream>
#include<string>
using namespace std;

struct Node
{
   int id;
   string name;
   Node *next;
};

void addNode(Node *& head);
void deleteNode(Node *& head);
void deleteNodeFind(int destroy, Node *&  head, Node * current, Node * garbage);
void display(Node *& head);

int main()
{
     int choice;
     Node * head = NULL;
         
     do
     {   
        cout << "----------[MENU]----------\n";
        cout << "-\t1. ADD\t\t -\n";
        cout << "-\t2. DELETE\t -\n";
        cout << "-\t3. DISPLAY\t -\n";
        cout << "-\t4. EXIT\t\t -\n";
        cout << "--------------------------\n";
        cout << "Select 1, 2, 3, or 4: ";
        cin >> choice;

        switch (choice)
        {
        case 1: addNode(head);
           break;
        case 2: deleteNode(head);
           break;
        case 3: display(head);
           break;
        case 4: exit(1);
        default: cout << "\nInvalid entry!\n\n";
           break;
        }
     }
     while (choice != 4);
     return 0;
}

//------------------------------------------------------------------------------
void addNode(Node *& head)
{
   int insert = 0;
   string name;
   Node * current = head;    // If list is NOT EMPTY, current used to insert new node.
   Node * tail = new (Node); // Dynamically create a new memory block.
   
   cout << "\nADD an ID#: ";
   cin >> insert;             // User inserts new node.
   cin.ignore();
   cout << "Name: ";
   getline(cin, name);
   
   tail->id = insert;        // Assign to tail, new tail insert can now access id.
   tail->name = name;

   if (head == NULL)         // If list IS EMPTY, insert 1st node for the Circular list.
   {
      head = tail;         // If list is EMPTY assign new tail insert to head.
      tail->next = head;    // Point tail->next at head: TAIL NOW POINTS TO HEAD
   }   
   else    // If Circular list is NOT EMPTY, ADD a node to the end of list.
   {
      while (current->next != head) // Start with head and find the last node. 
      {   
         // As long as currrent->next is NOT equal to head, continue.
         current = current->next;  // Move to the next node, if any.
      }
      current->next = tail; // Point current->next to tail.
      tail->next = head;    // Point tail->next at head: TAIL NOW POINTS TO HEAD
   }   
   cout << endl;
}
//------------------------------------------------------------------------------

void deleteNode(Node *& head)
{
   int destroy;               // User enters node to be deleted.
   Node * current = head;     // Start at the head, and checks each node.
   Node * garbage = current;  // garbage FOLLOWS along behind the pointer current. 
   
   if (head == NULL)         // Circular list is empty when head equals NULL.
   {
      cout << "\nList is empty!\n\n";
      return;
   }   
   cout << "\nDELETE an ID#: ";
   cin >> destroy;

   if (head == current->next)   // ** If there is ONLY one element in list. **
   {
      if (current->id == destroy)   // And it contains the id to be destroyed.
      {   
         head = NULL;    // ** IMPORTANT to reset head to NULL if only element **
         delete garbage; // delete node.
         garbage = 0;    // To prevent a dangling pointer and possible errors.
         cout << "\nID# found--> " << destroy << ": DELETED!\n\n";
         return;
      }
      else
      {
         cout << "\nID#--> " << destroy << " is NOT in the list!\n\n";
         return;
      }
   }   
    else if (current->id == destroy)  // Condition for deletion of first node in list.
    {      
      while (current->next != head) // Find the node that is not equal to head.
      {
         current = current->next;  // If more than one node, move to next node.
      }
      // Next node after head is assigned to current next, and then to head.
      head = current->next = head->next;   
      delete garbage;              // Delete the node.
      garbage = 0; // To prevent a dangling pointer and possible errors.
      cout << "\nID# found--> " << destroy << ": DELETED!\n\n";
      return;
    }

   // Call the other delete function if further search conditions are needed.
   deleteNodeFind(destroy, head, current, garbage);
}
//------------------------------------------------------------------------------

void deleteNodeFind(int destroy, Node *&  head, Node * current, Node * garbage)
{
    // Condition for deletion of all nodes EXCEPT first and last.
    while (current->next->next != head)
    {
        if (current->next->id == destroy)
        {
              garbage = current->next; // current next is assigned to garbage
              current->next = current->next->next; // current points to current next next.
              delete garbage;         // Delete node.
              garbage = 0; // To prevent a dangling pointer and possible errors.
              cout << "\nID# found--> " << destroy << ": DELETED!\n\n";
              return;
        }
        current = current->next;    // Move to the next node, if any.        
    }

    // Condition for deletion of LAST node only.
    if ((current->next->next == head) && (current->next->id == destroy))
    {
        garbage = current->next;    // Assign current next to garbage.
        delete garbage;             // delete node.
        garbage = 0; // To prevent a dangling pointer and possible errors.
        cout << "\nID# found--> " << destroy << ": DELETED!\n\n";
        current->next = head;       // IMPORTANT: point current to head.
        return;
    }
    cout << "\nID#--> " << destroy << " is NOT in the list!\n\n";
    return;
}

//------------------------------------------------------------------------------

void display(Node *& head)
{
   Node * current =  new (Node);   // Node to travel the Circular linked list.
   current = head;
   
   if (current == NULL) // Circular list is empty when head equals NULL.
   {
      cout << "\nList is empty!\n\n";
      return;
   }   

   cout << "\nList:\n";
   do
   {
      cout << "ID: " << current->id << "\t"
           << " Name: " << current-> name << endl; // Display current id.
      current = current->next;     // Move to the next node, if any.
   } while (current != head);       
   
   cout << ". . . .End of list. . . .\n\n";
}

//------------------------------------------------------------------------------


