#include <iostream>
#include <string>

using namespace std;


// LinkedList of user_node contains LL of type_node contains LL of perm_node
class perm_node{
  friend class user_node;
  private:
    string perm;
    perm_node* next_perm = NULL;
};

class type_node{
  friend class user_node;
  private:
    string type;
    type_node* next_type = NULL;
    perm_node* perms = NULL;
    int add_perm_node(string perm);
};

class user_node{
  public:
    user_node(int id, string name);
    void add_type_node(string type);
    void add_perm_node(string type, string perm);
    int has_perm(string type, string perm);
  private:
    int id;
    string name;
    user_node* next_user = NULL;
    type_node* types = NULL;
};


int main(){
  user_node users(123, "david");
  users.add_type_node("article");
  users.add_perm_node("article","editor");
  cout << "has" << (users.has_perm("article","editor")?"":" no") << " permission" << endl;
  cout << "has" << (users.has_perm("article","publisher")?"":" no") << " permission" << endl;
  cout << "has" << (users.has_perm("news","editor")?"":" no") << " permission" << endl;
  cout << "has" << (users.has_perm("news","publisher")?"":" no") << " permission" << endl;
}


user_node::user_node(int id, string name){
  this->id = id;
  this->name = name;
}

void user_node::add_type_node(string type){
  this->types = new type_node;
  this->types->type = type;
}

void user_node::add_perm_node(string type, string perm){
  // need to search for and use only this type
  this->types->perms = new perm_node;
  this->types->perms->perm = perm;
}

int user_node::has_perm(string type, string perm){
  if(this->types->type == type &&
     this->types->perms->perm == perm){
    return 1;
  }
  return 0;
}
