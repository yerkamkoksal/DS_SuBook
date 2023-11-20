
//  SUBook.h
//  Homework5
//
//  Created by Yusuf Erkam KOKSAL on 13.12.2022.
//

#ifndef SUBook_h
#define SUBook_h
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Post;
class Comment;

class User {
    friend class Post;
    friend class Comment;
private:
    string name;
    vector <Post*> posts;
    int num_comments;

public:
    User();
        
    User(string username);
    
    string getName();
    
    Post& createPost(string content);           ///
    
    vector<Post*> getPosts();                   ///
    
    int getNumComments();
        
    ~User();
};


class Post: public User{
    friend class User;
    friend class Comment;
private:
    User& user;
    string content;
    vector<Comment*> comments;
    
public:
    Post(User& user1, string content1);
    
    void addComment(string content1, User* commenter);
    
    vector<Comment*> getComments();                             ///
    
    User& getUser();
    
    string getContent();
    
    ~Post();
};


class Comment{
    friend class Post;
    friend class User;
private:
    User& user;
    Post& post;
    string comment;
public:
        
    Comment(User& user, Post& post, string content1);
    
    User& getUser();
    
    string getContent();
    
    Post& getPost();
    
    ~Comment();

};


#endif /* SUBook_h */

