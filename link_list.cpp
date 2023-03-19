#include<bits/stdc++.h>
using namespace std;

class node{
public:
int data;
node *next;
node(int i){
    data = i;
    next = NULL;
}
};

node* insertion_pointer;
int cq = 0;
int length = 1;

void delete_first(node* &head){
    if(head==NULL){
        cout<<"Empty linklist\n";
        return;
    }
    head = head->next;
    length=length-1;
    if (head==NULL)
    {
        cq=1;
    }
    cout<<"Done!\n";
}


void delete_last(node* head){
    if(head==NULL){
        cout<<"Empty linklist\n";
        return;
    }
    node* temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    insertion_pointer = temp;
    length=length-1;
    if (head==NULL)
    {
        cq=1;
    }
    cout<<"Done!\n";
}

string reverse(node* &head){
    if(head==NULL)
    {
        return "empty linklist\n";
    }
    if(head->next==NULL){
        
        return "Already Reversed";
    }
    node* temp = head->next;
    node* te = head->next;
    node* p = head;
    head->next = NULL;
    int sos = length;
    sos= sos-2;
    while (sos--)
    {

        node* store = te->next;
        te->next = p;
        p = temp;
        temp = store;
        te = store;

    }
    temp->next = p;
    head = temp;
    return "Done!";
    
}


void check_palindrome(node* head){
    if(head==NULL)
    {
        cout<<"Empty linklist\n";
        return;
    }
    string s1 = "";
    node* temp = head;
    while (temp!=NULL)
    {
        s1 = s1+to_string(temp->data);
        temp = temp->next;
    }
    reverse(head);
    temp = head;
    string s2 = "";
    while (temp!=NULL)
    {
        s2 = s2+to_string(temp->data);
        temp = temp->next;
    }
    if(s1==s2){
        cout<<"Yes! Linklist is palindrome\n";
    }else{
        cout<<"No! Linklist is not a palindrome\n";
        reverse(head);
    } 
}



void Print_Odd_Numbers(node* head){
    if(head==NULL){
        cout<<"EMPTY LINKLIST\n";
        return;
    }
    node* temp = head;
    int pp = 0;
    cout<<"Searching Odd-Numbers\n";
    while (temp!=NULL)
    {
        if(temp->data%2!=0){
        cout<<temp->data<<" ";
        pp=1;
        }
        temp = temp->next;
    }
    if(pp==0)
    cout<<"\nThere Is NO Any Odd-Number\nPresent In Linklsit!";
    cout<<"\n";
}



void Print_Even_Numbers(node* head){
    if(head==NULL){
        cout<<"EMPTY LINKLIST\n";
        return;
    }
    node* temp = head;
    int pp=0;
    cout<<"Searching Even-Numbers\n";
    while (temp!=NULL)
    {
        if(temp->data%2==0){
        cout<<temp->data<<" ";
        pp=1;
        }
        temp = temp->next;
    }
    if(pp==0)
    cout<<"\nThere Is NO Any Even-Number\nPresent In Linklsit!";
    cout<<"\n";  
}



void mid(node* head){
    if(head==NULL)
    {
        cout<<"EMPTY LINKLIST\n";
        return;
    }
   
    node* temp = head;
    int p = ((length+1)/2-1);
    while (p--)
    {
        temp = temp->next;
    }
    cout<<"Mid Element : "<<temp->data;
    cout<<"\n";
}


void delete1(node* &head){
    if(head==NULL){
        cout<<"EMPTY LINKLIST\n";
        return;
    }
    cout<<head->data<<" deleting..\n";
    head = head->next;
    length--;
   
    cout<<"successfully deleted\n";
    if (head==NULL)
    {
        cq=1;
    }  
}



void insert(node* &head,int data){
    node* temp = insertion_pointer;
    node* newlink = new node(data);
    temp->next = newlink;
    newlink->next = NULL;
    insertion_pointer = newlink;
    length++;
    
    if(cq==1){
        head = newlink;
        cq=0;
    }
}

void show(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


void insert_at_last(node* head,int data){
    node* temp = head;
    node* newlink = new node(data);
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newlink;
    newlink->next = NULL;
    length=length+1;
    insertion_pointer = newlink;
        if(cq==1){
        head = newlink;
        cq=0;
    }
}


void insert_at_first(node* &head,int data){
    node* newlink = new node(data);
    if(head==NULL)
    {
        head = newlink;
        head->data = newlink->data;
        head->next = NULL;
        return;
    }
    newlink->next = head;
    head = newlink;
    length=length+1;
        if(cq==1){
        head = newlink;
        cq=0;
    }
}


int main(){
    node* head = new node(1);
    head->next = NULL;
    insertion_pointer = head;
    cout<<"Current Status Of Linklist : \n"<<head->data<<"->NULL"<<"\n";
    string s;
    cout<<"Are You Want To Update Current Linklist (Yes or No) : ";
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    
    if(s=="yes"){
        cout<<"Enter The Data : ";
        int d;
        cin>>d;
        head->data = d;
        cout<<"updated linklist : "<<head->data<<"->NULL\n";
    }
    cout<<"____TASK-MENU____\n\n1.Insert_At_First\n2.Insert_At_Last\n3.Delete_first\n4.Delete_Last\n5.Print\n6.Mid-Element\n7.Print-Even-Numbers\n8.Print-Odd-Numbers\n9.Reverse\n10.check_palindrome\n11.__Queue-Implementation__\n12.Length\n13.Task-Menu\n14.Exit\n";
    int choice;
    while (1)
    {
    int n,data,qcho,rer=0;
    
    cout<<"Which task you want to perform : ";
    cin>>choice;
    
    switch (choice)
    {
    case 1:
        cout<<"Enter Number Of Data : ";
        cin>>n;
        for (int i = 0; i < n; i++)
        {
        cout<<"Enter "<<i+1<<" Data : ";
        cin>>data;
        insert_at_first(head,data);
        }
        break;
    case 2:
        cout<<"Enter Number Of Data : ";
        cin>>n;
        for (int i = 0; i < n; i++)
        {
        cout<<"Enter "<<i+1<<" Data : ";
        cin>>data;
        insert_at_last(head,data);
        }
        break;
    case 3:
        delete_first(head);
        break;
    case 4:
        delete_last(head);
        break;
    case 5:
        show(head);
        break;
    case 6:
        mid(head);
        break;
    case 7:
        Print_Even_Numbers(head);
        break;
    case 8:
        Print_Odd_Numbers(head);
        break;
    case 9:
        cout<<reverse(head)<<"\n";
        break;
    case 10:
        check_palindrome(head);
        break;
    case 11:
        cout<<"\n9.Queue-Implementation-Using-Linklist\n\n1.Insertion\n2.Deletion\n3.Print\n4.Reverse\n5.check_palindrome\n6.Length\n7.Exit\n";
        while (1)
        {   
            cout<<"Which task you want to perform : ";
            cin>>qcho;
            switch (qcho)
            {
            case 1:
                cout<<"Enter Number Of Data : ";
                cin>>n;
                for (int i = 0; i < n; i++)
                {
                    cout<<"Enter "<<i+1<<" Data : ";
                    cin>>data;
                    insert(head,data);
                }
                break;
            case 2:
                delete1(head);
                break;
            case 3:
                show(head);
                break;
            case 4:
                cout<<reverse(head)<<"\n";
                break;
            case 5:
                check_palindrome(head);
                break;
            case 6:
                cout<<"Length : "<<length<<endl;
                break;
            case 7:
                cout<<"Exiting Queue-Implementation...\nDone!\n";
                cout<<"____TASK-MENU____\n\n1.Insert_At_First\n2.Insert_At_Last\n3.Delete_first\n4.Delete_Last\n5.Print\n6.Mid-Element\n7.Print-Even-Numbers\n8.Print-Odd-Numbers\n9.Reverse\n10.check_palindrome\n11.__Queue-Implementation__\n12.Length\n13.Task-Menu\n14.Exit\n";
                break;
            default:
                cout<<"Enter Valid Case\n";
                break;
            if (qcho==7)
            {
                break;
            }
            
            }
            if (qcho==7)
            {
                break;
            }
        }
        break;
    case 12:
        cout<<"Length : "<<length<<endl;
        break;
    case 13:
        cout<<"____TASK-MENU____\n\n1.Insert_At_First\n2.Insert_At_Last\n3.Delete_first\n4.Delete_Last\n5.Print\n6.Mid-Element\n7.Print-Even-Numbers\n8.Print-Odd-Numbers\n9.Reverse\n10.check_palindrome\n11.__Queue-Implementation__\n12.Length\n13.Task-Menu\n14.Exit\n";
        break;
    case 14:
        cout<<"\nThank You!\n";
        return 0;
    default:
        cout<<"ENTER VALID CASE\n";
        break;
    }
}

    return 0;
}