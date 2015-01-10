#include <iostream>
#include <string>
#include "vlist.h"
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    video vlist;
    int exit = 0;
    string title;
    string  url;
    string comment;
    int rating;
    int length;
    string user_sort;
    while (user_sort != "^D" and exit == 0)
    {
    cout << "What would you like to do? Enter command in parenthesis" << endl;
    cout<<"1.Insert a new video into the linked-list (Insert)" << endl;
    cout<<"2.Print all the videos in the list (Print)" << endl;
    cout<<"3.Lookup a video by title and print it(Lookup)"<< endl;
    cout<<"4.Print the number of videos in the list(Length)"<< endl;
    cout<<"5.Remove a video by title (Remove)"<< endl;
    getline(cin,user_sort);
    if (user_sort == "Insert" or user_sort == "insert")
    {
        cout << "Enter in a title" << endl;
        getline(cin,title);
        cout << "Enter in a URL" << endl;
        getline (cin, url);
        cout << "Enter in a comment" <<endl;
        getline (cin,comment);
        cout << "Enter in a length" << endl;
        cin >>length;
        cout << "Enter in a rating" << endl;
         cin>> rating;
         if(!vlist.lookup(title))
         {
             vlist.inserts(title,url,comment,length,rating);
         }
         else
            cout << "Could not insert vider" << title << "already in list" << endl;

    }
    else if (user_sort == "Print" or user_sort == "print")
    {
        vlist.print(0);
    }
    else if (user_sort == "Lookup" or user_sort == "lookup")
    {
        cout << "Please enter in a title" << endl;
        getline(cin, title);
        //length=vlist.lookup(title);
        if (!vlist.lookup(title))
        {
            cout << "Title is not in list"<<endl;
        }
        else
        {
            vlist.print(length);
        }
    }
    else if (user_sort == "Length" or user_sort == "length")
    {
        cout <<"You have "<< vlist.print_num()<< " videos."<<endl;
    }
    else if (user_sort == "Remove" or user_sort == "remove")
    {
        cout << "Please enter in a title you would like to remove" << endl;
        getline(cin, title);
        if (!vlist.removes(title))
        {
            cout << "Title is not in the list" << endl;
        }

    }
    else if (user_sort == "^D")
    {
    }
    else
    {
        cout << "<" <<user_sort << "> is not a legal command, giving up."<< endl;
        exit = 1;
    }
    cin.ignore();
    }
    return exit;
}

