#include <iostream>
#include <string>
#include "vlist.h"
#include <sstream>
#include <fstream>
using namespace std;

int video::removes(string title)
{
    //Node* title = m_head;
    Node* removed = m_head;
    Node* previous = m_head;
    Node* temp;
    int first=0;
    while (removed != NULL)
    {
        if (removed->m_title == title and first==0)
        {
            m_head=m_head->m_next;
            return 1;
        }
        first++;
        if (removed->m_title == title)
        {
            temp=removed->m_next;
            previous->m_next=temp;
            return 1;
        }
        previous=removed;
        removed=removed->m_next;
    }
    return 0;
}
int video::lookup(string title)
{
    int video_count = 1;
    Node* temp = m_head;
    // Nodes already present in the list
    // Parse to end of list
    while ( temp != NULL )
    {
        if (title == temp->m_title)
        {
           return video_count;
        }
        temp = temp->m_next;
        video_count++;
    }
    return 0;
}
int video::print_num()
{
    int video_count = 0;
    Node *temp = m_head;
    // Nodes already present in the list
    // Parse to end of list
    while ( temp != NULL )
    {
        temp = temp->m_next;
        video_count++;
    }
    return video_count;//video_count;
}
void video::inserts(string title, string url, string comment, int length, int rating)
{
    m_head= new Node(title, url, comment, length, rating, m_head);
    order();
}
void video::print(int counter)
{
    int video_tracker=0;
    Node *temp = m_head;
    if (counter==0)
    {
        while (temp != NULL)
         {
            cout << temp->m_title << endl;
            cout << temp->m_url << endl;
            cout << temp->m_comment << endl;
            cout << temp->m_length << endl;
            cout << temp->m_rating << endl;
            cout << endl;
            temp=temp->m_next;
        }
    }
    else
    {
        while (video_tracker < (counter-1))
        {
            temp = temp -> m_next;
            video_tracker++;
        }
        cout << temp->m_title << endl;
        cout << temp->m_url << endl;
        cout << temp->m_comment << endl;
        cout << temp->m_length << endl;
        cout << temp->m_rating << endl;
        cout << endl;
    }
}
void video::order()
{
    int tempint;
    string tempstring;
    Node*order = m_head;
    Node*next=m_head;
    next=next->m_next;
    while (order != NULL)
    {
        next=order->m_next;
        while (next != NULL)
        {
            if (order->m_title > order->m_next->m_title)
            {
                tempstring=order->m_title;
                order->m_title=order->m_next->m_title;
                order->m_next->m_title=tempstring;
                tempstring=order->m_url;
                order->m_url=order->m_next->m_url;
                order->m_next->m_url=tempstring;
                tempstring=order->m_comment;
                order->m_comment=order->m_next->m_comment;
                order->m_next->m_comment=tempstring;
                tempint=order->m_length;
                order->m_length=order->m_next->m_length;
                order->m_next->m_length=tempint;
                tempint=order->m_rating;
                order->m_rating=order->m_next->m_rating;
                order->m_next->m_rating=tempint;
            }
            next=next->m_next;
        }
        order=order->m_next;
    }
}
video::video()
{
    m_head=NULL;
}
