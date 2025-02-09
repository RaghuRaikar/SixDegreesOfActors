#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include "graphs.h"

using namespace std;

class Node
{
  public:
    string node_Name;
    int id;
    Node* pred;
    vector<Node*> adjacency_List;

    Node(string name,int id2)
    {
      node_Name = name;
      id = id2;
      pred = NULL;
    }

};

vector<string> tokenize(string input)
{
  vector<string> output;
  stringstream tokenizer(input);
  string token;
  while(getline(tokenizer, token, ' '))
  {
    output.push_back(token);
  }
  return output;
}

bool BFS(string start_actor, string end_actor, unordered_map<string, Node*> a1)
{
  set <Node*> visited;
  queue<Node*> bfs_queue;
  Node* current_node = a1[start_actor];
  vector<Node*> AL = current_node->adjacency_List;
  for(int i = 0; i < AL.size(); i++)
  {
    bfs_queue.push(AL[i]);
  }
  Node* queue_top;
  while(!bfs_queue.empty())
  {
    queue_top = bfs_queue.front();
    bfs_queue.pop();
    vector<Node*> cal = queue_top->adjacency_List;
    for(int i = 0; i < cal.size(); i++)
    {
      if(visited.count(cal[i]) > 0)
      {
        continue;
      }
      if(cal[i]->node_Name == end_actor)
      {
        cal[i]->pred = queue_top;
        return true;
      }
      visited.insert(cal[i]);
      cal[i]->pred = queue_top;
      bfs_queue.push(cal[i]);
    }
  }
  if(!bfs_queue.empty())
  {
    while(!bfs_queue.empty())
    {
      bfs_queue.pop();
    }
  }
  return false;
}

ofstream output;

void PrintPath(string start_actor, string end_actor, unordered_map<string, Node*> a1)
{
  vector<string> path;
  bool path_exists = BFS(start_actor, end_actor, a1);
  if(path_exists == true)
  {
    Node* end = a1[end_actor];
    bool break_while = false;
    while(end != NULL)
    {
      if(end->id == 0)
      {
        vector<Node*> check = end->adjacency_List;
        for(int i = 0; i < check.size(); i++)
        {
          if(check[i]->node_Name == start_actor)
          {
            path.push_back("-(" + end->node_Name + ")-");
            break_while = true;
            break;
          }
        }
      }
      if(break_while == true)
      {
        break;
      }
      if(end->id == 1)
      {
        path.push_back(end->node_Name);
      }
      else
      {
        path.push_back("-(" + end->node_Name + ")-");
      }
      end = end->pred;
    }
    path.push_back(start_actor);
    for(int i = path.size()-1; i < path.size(); i--)
    {
      output << path[i] << " ";
    }
    output << endl;
  }
  else
  {
    output << "Not Present" << endl;
  }
}

int main(int argc, char** argv)
{
  if(argc < 3)
  {
    throw std::invalid_argument("Usage: ./sixdegrees <INPUT FILE> <OUTPUT FILE>");
  }

  ifstream input;
  ifstream movie_input;

  unordered_map<string, Node*> actors;
  movie_input.open("cleaned_movielist.txt");

  string each_line;

  while(getline(movie_input,each_line))
  {
    vector<string> el = tokenize(each_line);
    string movie_name;
    
    for(int i = 0; i < el.size(); i++)
    {
      Node *movie;
      if(i == 0)
      {
        movie_name = el[0];
        movie = new Node(movie_name,0);
        i++;
      }
      string current_actor = el[i];
      if(actors.count(current_actor) == 1)
      {
        Node *update = actors[current_actor];
        movie->adjacency_List.push_back(actors[current_actor]);
        update->adjacency_List.push_back(movie);
      }
      else
      {
        Node *actor = new Node(current_actor, 1);
        actor->adjacency_List.push_back(movie);
        movie->adjacency_List.push_back(actor);
        actors.insert({current_actor,actor}); 
      }
    }
  }

  input.open(argv[1]);
  output.open(argv[2]);

  string each_line2;
  while(getline(input, each_line2))
  {
    vector<string> a3 = tokenize(each_line2);
    if(a3.size() == 0)
    {
      continue;
    }
    string a1 = a3[0];
    string a2 = a3[1];

    if(actors.count(a1) == 0 || actors.count(a2) == 0)
    {
      output << "Not present" << endl;
    }
    else if(a1 == a2)
    {
      output << a1 << endl;
    }
    else
    {
      PrintPath(a1,a2,actors);
    }
  }
  input.close();
  output.close();
}
