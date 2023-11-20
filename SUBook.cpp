// YUSUF ERKAM KOKSAL   29512    CS 204 HOMEWORK #5
//

#include "SUBook.h"

using namespace std;

//---- USER CLASS

User::User(){}


User::User(string username) {
    name = username;
    num_comments = 0;
}
string User::getName(){
    return name;
}
int User::getNumComments(){
    return num_comments;
}

Post& User::createPost(string content){
    Post* p1 = new Post(*this,content);
    posts.push_back(p1);
    return *p1;
}

vector<Post*> User::getPosts(){
    return this->posts;
}

User::~User(){
    for (auto pst = posts.begin(); pst != posts.end(); ++pst)
    {
        delete *pst;
    }
}
//---- POST CLASS

Post::Post(User& user1, string content1) : user(user1), content(content1) {}


vector<Comment*> Post::getComments(){
    return this->comments;
}


void Post::addComment(string content1, User* commenter){
    Comment* c1 = new Comment(*commenter, *this, content1);
    comments.push_back(c1);
    commenter->num_comments += 1;
}

User& Post::getUser(){
    return user;
}

string Post::getContent(){
    return content;
}

Post::~Post(){
    for (auto cmt = comments.begin(); cmt != comments.end(); ++cmt)
        {
            delete *cmt;
        }

}

//---- COMMENT CLASS
    

Comment::Comment(User& user1, Post& post1, string content1) : user(user1) , post(post1), comment(content1){}


User& Comment::getUser(){
    return user;
}

string Comment::getContent(){
    return comment;
}

Post& Comment::getPost(){
    return post;
}
Comment::~Comment(){
    user.num_comments -=1;
}



// --- END OF MY HOMEWORK ---//

void printPost(Post& post){
   cout <<  "|||||||||||||||||||||||||||||||||||||||" << endl;
   cout << post.getUser().getName() <<":" << endl;
   cout << post.getContent()<< endl;
   vector<Comment*> comments = post.getComments();
   for (int i =0; i < comments.size(); i++){
       cout << "  " << comments[i]->getUser().getName();
       cout << ": " << comments[i]->getContent() << endl;
}
   cout <<  "|||||||||||||||||||||||||||||||||||||||" << endl <<
endl;
}
void printUserNumComments(User& user){
 cout << "User " << user.getName() << " has " <<
user.getNumComments() << " comments" << endl << endl;
}

int main() {
    User u1("User1");
    {
        User u2("User2");
        Post& p1 = u2.createPost("User2 post");
        p1.addComment("User1 comment", &u1);

        p1.addComment("User2 comment", &u2);
        cout << u2.getName() << " has " << u2.getNumComments() << " comments" << endl;
        
        cout << u1.getName() << " has " << u1.getNumComments() << " comments" << endl;
    }
    cout << u1.getName() << " has " << u1.getNumComments() << " comments" << endl;
    
    return 0;
}

