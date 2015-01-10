#include <string>
#include <iostream>
using namespace std;
//Will define the class if it is not already defined
#ifndef LIST_H
#define LIST_H



// List class
class video
{

    private:
        class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
               // void Node(int length, int rating, string title, string url, string comment, Node *next)
               // {m_next = next; m_length = length; m_rating = rating; m_title=title; m_url=url; m_comment = comment;}
                Node(string title, string url, string comment, int length, int rating, Node *next)
                {m_title = title; m_url = url; m_comment = comment; m_length = length; m_rating=rating;m_next=next;}
                string m_title;
                string m_comment;
                string m_url;
                int m_rating;
                int m_length;
                Node *m_next;
        }*m_head;
    public:
        void inserts (string, string, string, int, int);
        int removes (string);
        int lookup(string);
        int print_num ();
        void print(int);
        video();
        void order();
};
#endif
