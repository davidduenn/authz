#include <iostream>
#include <string>

using namespace std;


// LinkedList of user_node contains LL of type_node contains LL of perm_node
struct perm_node{
  string perm;
  perm_node* next_perm;
};

struct type_node{
  string type;
  type_node* next_type;
  perm_node* perms;
};

struct user_node{
  int id;
  string name;
  user_node* next_user;
  type_node* types;
};


int main(){
  user_node *users = new user_node;
  users->id = 123;
  users->name = "david";
  users->next_user = NULL;
  users->types = new type_node;
  users->types->type = "news";
  users->types->perms = new perm_node;
  users->types->perms->perm = "editor";
}
