#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

struct node 
	{
		int data;
		struct node *link;
	};
struct node *head = (struct node *)malloc(sizeof(struct node));

// Add to the beginning
void addNode(int n){
	struct node *add = (struct node *)malloc(sizeof(struct node));
	add->link = head;
	head = add;
	add->data = n;
}

// Add to the end
int addEnd(int n)
{
	//std::cout << "1" << std::endl;
	struct node *add1 = (struct node *)malloc(sizeof(struct node));
	//std::cout << "2" << std::endl;
	struct node *t1 = head;
	//std::cout << "3" << std::endl;
	if(head == NULL)
	{
		head = add1;
		add1->link = NULL;
		add1->data = n;
		return false;
	}
	while(t1->link != NULL)
	{
		//std::cout << "4" << std::endl;
		t1 = t1->link;
		//std::cout << "5" << std::endl;
	}
	t1->link = add1;
	add1->data = n;
	add1->link = NULL;
	return true;
}

// Add at a desired location
int add(int n)
{
	struct node *add1 = (struct node *)malloc(sizeof(struct node));
	struct node *t1 = head;
	if(head == NULL)
	{
		head = add1;
		add1->link = NULL;
		add1->data = n;
		return false;
	}
	int m;
	std::cout << "Where do you want to add " << std::endl;
  	std::cin >> m;
	while(t1->data != m)
	{
		//std::cout << "4" << std::endl;
		
		//std::cout << "5" << std::endl;
		if(t1->link == NULL)
		{
			std::cout << "no such value exists" << std::endl;
			return false;
		}
		t1 = t1->link;
	}
	add1->link = t1->link;
	t1->link = add1;
	add1->data = n;
	return true;
}

// Delete in the beginning
void DeleteStart()
{
	struct node *t2 = head;
	if (head == NULL)
	{
		std::cout << "no value to delete" << std::endl;
	}
	else if (head->link == NULL && head != NULL)
	{
		std::cout << "This is the only value so deleteing this" << std::endl;
		free(t2);
		head = NULL;
	}
	else 
	{
		head = head->link;
		free(t2);
	} 
}

// Delete in the end
void DeleteEnd()
{
	struct node *t3 = head;
	if (head == NULL)
	{
		std::cout << "no value to delete" << std::endl;
	}
	else if (head->link == NULL && head != NULL)
	{
		std::cout << "This is the only value so deleteing this" << std::endl;
		free(t3);
		head = NULL;
	}
	else
	{
		while(t3->link->link != NULL)
		{
			//std::cout << "4" << std::endl;
			t3 = t3->link;
			//td::cout << "5" << std::endl;
		}
		free(t3->link);
		t3->link = NULL;
	}	
}

// Adding at a desired location
int Delete()
{
	struct node *t3 = head;
	if (head == NULL)
	{
		std::cout << "no value to delete" << std::endl;
		return false;
	}
	else if (head->link == NULL && head != NULL)
	{
		std::cout << "This is the only value so deleteing this" << std::endl;
		free(t3);
		head = NULL;
		return false;
	}
	else
	{
		int m;
		std::cout << "Where do you want to delete " << std::endl;
	  	std::cin >> m;
	  	if(t3->data == m)
	  	{
	  		head = t3->link;
	  		free(t3);
	  		return false;
	  	}
	  	//cout << "1";
	  	struct node *t4 = t3->link;
		while(t4->data != m)
		{
			//cout << "2";
			if(t4->link == NULL)
			{
				std::cout << "no such value exists" << std::endl;
				return false;
			}
			t3 = t3->link;
			t4 = t4->link;
			//cout << "3";
		}
		//cout << "4";
		t3->link = t3->link->link;
		free(t4);
		return false;
	}
}

// print linkedlist
void print()
{
	struct node *t = head;
	//t = head;
	//std::cout << t->data << std::endl;
	//std::cout << "start printing" << std::endl;
	while(t != NULL)
	{
		//std::cout << "1" << std::endl;
		std::cout << t->data << std::endl;
		//std::cout << "2" << std::endl;
		t = t->link;
		//std::cout << "3" << std::endl;
	}
	//std::cout << "4" << std::endl;
}

// Reverse Linked List iterative
int reverse()
{
	if(head == NULL)
	{
		std::cout << "nothing is in the list to reverse" << std::endl;
		return false;
	}
	struct node *t = head;
	int count = 1;
	while (t->link != NULL)
	{
		count++;
		t = t->link;
	}
	std::cout << "total number of node are " << count << std::endl;
	if (count < 5)
	{
		struct node *curr = head;
		struct node *prev = NULL;
		struct node *next = NULL;
		//head->link = NULL;
		while (curr)
		{
			next = curr->link;
			curr->link = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	else
	{
		struct node *curr = head;
		struct node *prev = NULL;
		struct node *next = NULL;
		struct node *t;
		while(curr->link->link->link->link != NULL)
		{
			t = curr;
			curr = curr->link;
		}
		while (curr)
		{
			next = curr->link;
			curr->link = prev;
			prev = curr;
			curr = next;
		}
		t->link = prev;
	}
	return true;
}

// Reverse recursive
void recursive_reverse(struct node *p)
{
	if(p)
	{
		recursive_reverse(p->link);
		std::cout << p->data << std::endl;
	}
}

// Make list empty
void MakeEmpty()
{
	struct node *t = head;
	struct node *t1 = head->link;
	head = NULL;
	while(t->link != NULL)
	{
		free(t);
		t = t1;
		t1 = t1->link;
	}
}

int main()
{

  std::string command;       
  std::cout << "What operation to be performed? " << std::endl;
  std::cin >> command;
  head = NULL;
  while (command != "quit")
  { 
    //std::cout << command;
    if (command == "insert")
    {
    	int value;
    	std::cout << "Value you want to add " << std::endl;
  		std::cin >> value;
      	addNode(value);
      	//std::cout << "insert in the end" << std::endl;
    }
    else if (command == "reverse")
    {
      reverse();
    }
    else if (command == "delete")
    {
    //   	int value1;
    // 	std::cout << "Value you want to delete " << std::endl;
  		// std::cin >> value1;
      	DeleteStart();
      	//std::cout << "delete in the end" << std::endl;
    } 
    else if (command == "print")
    {
      std::cout << "inside PrintList" << std::endl;
      print();
    }
    else if (command == "rec_reverse")
    {
    	struct node *p = head;
      	recursive_reverse(p);
    }
    else if (command == "empty")
    {
      	MakeEmpty();
    }
    else std::cout << " Command not recognized." << std::endl; 
    std::cout << "What next operation to be performed? " << std::endl;
    std::cin >> command;
  };
}

// 
// head->link = NULL;
