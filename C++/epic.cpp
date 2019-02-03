#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

#define NAME_SIZE 50

struct node
{
  int val;
  node *next;

};

struct treeNode
{ 
  int val;
  treeNode* left;
  treeNode* right;
};






class queue
{
  int start, end, currsize, maxsize;
  int *q;
  
  public:
  queue( int s ): maxsize(s)
  {
    start = 0;
    end = 0;
    currsize = 0;
    q = new int[maxsize];
  }

  public:
  void add( int num )
  { 
    if ( currsize < maxsize )
    {
      q[end++] = num;
      end %= maxsize;
      currsize++;
    }
    else cout << "\n Queue is full sir. \n";
  }
  
  public:
  int remove()
  {
    int res = NULL;
    if ( currsize > 0 )
    {
      res = q[start++];
      start %= maxsize;
      currsize--;
      return res;
    }
    else cout << "\n Queue is empty sir. \n";
  }     

  public:
  void displayQ()
  {
    for( int iterator = start; iterator != end; iterator= (iterator + 1)% maxsize)  
    cout<< " " << q[iterator];

    cout<<"\n";
  }

};



class list
{
  protected:
  node *head, *tail;
  
  public:
  list()
  {
    head = NULL;
    tail = NULL;
  }

  public:
  void createNode(int value)
  {
    node* temp = new node;
    temp->val = value;
    temp->next = NULL;
  
    if( head == NULL )
    {
      head = temp;
      tail = temp;
      temp = NULL;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  
}

 public:
  void displayNodes()
  {
    if( head == NULL) cout << "\n No nodes to display \n";
    else
    {
      node *temp = head;
      cout<< "\n Nodes in order:"; 
      while ( temp != NULL )
      {
        cout << temp->val << "->" ;
        temp = temp->next;
      }
      cout << "NULL\n"; 
    }

  }

  public:
  void deleteMiddle()
  {
    
    if(head == NULL || head->next == NULL)
    {
      cout<<"\n No nodes to delete \n";
      return;
    }



    node *slow,*fast,*prev;
    slow = head;
    fast = head;
    while(fast != NULL &&  fast->next != NULL )
    {
      fast = fast->next->next;
      prev = slow;
      slow = slow->next;
    }
     prev->next = slow->next;
     delete slow;;
  }
  
  
};

class stack: public list
{
  
  public:
  stack() : list() {}
  
  public:
  node* pop()
  {
    node *iterator, *result;
    iterator = head;
    if( head == NULL )
    {
      cout << "\n Nothing in the stack \n";
      return NULL;
    }
    while (iterator->next != tail)
    {
     iterator = iterator->next; 
    } 
    
    iterator->next = NULL;
    result = tail;
    tail = iterator;  
    return result;
  }
  
  public:
  void push (int val)
  {
    createNode(val);
  }
  
  public:
  bool isEmpty()
  {
    if(head == NULL) return true;
    else return false;
  }  

 };
 

int menu()
{
  int result;
  
  cout << "\nWelcome to EPIC\n" ;
  cout <<"\n"; 
  cout << "Choose one of the following options\n";
  cout <<"\n"; 
  cout <<" 1. Hash Map\n";
  cout <<" 2. Linked List\n";
  cout <<" 3. Stack\n";
  cout <<" 4. Queue\n";
  cout <<" 5. Binary Tree\n";
  cout <<"\n :";
  cin >> result;

  return result;
}

void hashmapBuilder()
{
  string rawinput,spaceR, input;
  
  do
  {
    cout << "\n Enter a string up to 200 letters and we will tell you how much of each you had (no spaces allowed)  \n :";
    cin.ignore();
    getline(cin,rawinput, '\n');
  } while( rawinput.length() > 200 );
  
  istringstream iss(rawinput);  
  
  while ( getline(iss, spaceR,' ' ))
  { 
    input.append(spaceR);
  }
  
  
  cout << "\n";
 
  unordered_map <char, int> counts;
  
  for( int i = 0; i < input.length(); i++ )
  {
    if ( counts[input[i]] == 0 ) counts[input[i]] = 1;
    else counts[input[i]]+=1; 
  }
  
  for( auto it = counts.begin(); it != counts.end(); ++it)
  {
    cout <<it->first << ": " <<  to_string(it->second);
    cout << "\n";
  }
  
  
}


void linkedlistBuilder()
{
  list *newList = new list;
  int newVal;
  do
  {
    
    cout << "\n Enter a number from 0-9, doing otherwise will end the addition of nodes: ";
    cin.ignore();
    cin >> newVal; 
    
    if( newVal < 0 || newVal >9 ) 
    {
      break;
    }
   
    newList->createNode(newVal);  
   
  }while( newVal >= 0 || newVal <=9 );

  newList->displayNodes();
  
  newList->deleteMiddle();
  
  newList->displayNodes();
}
void stackBuilder()
{
  stack *newStack = new stack;
  
  newStack->pop();
  newStack->push(1);
  newStack->push(2);
  newStack->push(3);
  
  cout << "\n" << newStack->pop()->val << "\n"; 
  
  newStack->displayNodes();


}


void queueBuilder()
{
  queue* newQ = new queue(5);
  int newVal;
  do
  {
    
    cout << "\n Enter a number smaller than 1000, do otherwise to quit: ";
    cin.ignore();
    cin >> newVal; 
    
    if( newVal > 1000 ) 
    {
      break;
    }
   
    newQ->add(newVal);  
   
  }while( newVal < 1000 );

  newQ->displayQ();
 
  cout<< "\n" << newQ->remove() << "\n";
  cout<< "\n" << newQ->remove() << "\n";
  cout<< "\n" << newQ->remove() << "\n";
  cout<< "\n" << newQ->remove() << "\n";
  newQ->add(6);
   
  newQ->displayQ();

}

void treeBuilder()
{
}

int controller(int choice)
{

  switch(choice)
  {
 
    case 1:
      hashmapBuilder();
      break;
    
    case 2:
      linkedlistBuilder();
      break;
   
    case 3:
      stackBuilder();
      break;
    
    case 4: 
      queueBuilder();
      break;
   
    case 5:
      treeBuilder();
      break;
 
    default:
    cout << "\n Not a valid choice \n ";
    return -1;
  }

return 0;
}


int main()
{
 controller( menu() ) ;

  
   
}




