#include<bits/stdc++.h>
typedef long long int lli ;
using namespace std;


class LinkedList{
   public:
   	lli data;
      LinkedList* next;
      LinkedList(){
         this->next=NULL;
      }
      LinkedList(lli data){
         this->data=data;
         this->next=NULL;

      }
      //ADD a NODE TO LINKEDLIST
      LinkedList* add(lli data,LinkedList *head){
        //IF LINKEDLIST IS EMPTY 
        if(head==NULL){
         LinkedList *temp=new LinkedList(data);
         head=temp;
        }
         
        else{
         LinkedList *temp=head;
         while(temp->next!=NULL){temp=temp->next;}
         temp->next=new LinkedList(data);
        }
         return head;
      }
      LinkedList * add(lli data,LinkedList *head,int pos){
      
         if(head==NULL){
            LinkedList *temp=new LinkedList(data);
            head=temp;
         }
         if(pos==1){
            LinkedList *temp=new LinkedList(data);
            temp->next=head;
            head=temp;
         }
         else {
         LinkedList *temp=head;
         int jump=pos-1;
         while(jump>1){
            temp=temp->next;
            jump--;
         }
         LinkedList *n=new LinkedList(data);
         n->next =temp->next;
         temp->next=n;
     }

          return head;
       
      }

      void print(LinkedList * head){
         LinkedList *temp=head;
         while(temp!=NULL){
            cout<<temp->data<<" ";
            //if(temp->next!=NULL)cout<<" ";
            temp=temp->next;
            
         }
      }

    int getMiddle(LinkedList *head){
         auto sp=head, fp=head;
            while(fp!=NULL and fp->next!=NULL){
               sp=sp->next;
               fp=fp->next->next;
           }
   return sp->data;
      }  

   LinkedList *deleteMiddle(LinkedList* head){
         auto sp=head,fp=head;
         auto pre=sp;
         while(fp!=NULL and fp->next!=NULL){
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
         }
         pre->next=sp->next;
         delete sp;
         return head;
      } 

      LinkedList* deleteLinkedList(LinkedList*head){
          auto pre=head;
          head=head->next;
          if(head==NULL){
            delete pre;
          }
          while(head!=NULL){
                 delete pre;
                 pre=head;
                 head=head->next;
          }
          return head;
      }  

      void printReverse(LinkedList * head){
         if(head==NULL) return;
         printReverse(head->next);
         cout<<head->data<<" ";
        
      }

      LinkedList * reverseLinkedlist(LinkedList* head){
         LinkedList *cur=head,*next=head,*pre=NULL;
         next=cur->next;
         while(cur){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
         }
         return pre;
      }
      bool ispalindrome(LinkedList* &left, LinkedList* right){
         if(right==NULL) return true;
         bool first =ispalindrome(left,right->next);
         if(first=false) return false;
         bool second=(right->data==left->data);
         left=left->next;

         return second;
      }
};
signed main(){
          
   LinkedList * head=NULL;
   head=head->add(1,head);
   head=head->add(2,head);
   head=head->add(3,head);
   head=head->add(4,head);
   head=head->add(5,head);
   head->print(head);cout<<endl;
   cout<<"MIDDLE ELEMENT IS : "<<head->getMiddle(head)<<endl;
   cout<<"Deleting middle Element: ";
   head=head->deleteMiddle(head);
   head->print(head);
   cout<<"\n";
   head=head->add(3,head,3);
   head->print(head);
   cout<<"\n";
   cout<<"Printing without reversing: ";
   head->printReverse(head);
   cout<<endl;
   cout<<"Printing with reversing: ";
   head=head->reverseLinkedlist(head);
   head->print(head);cout<<"\n";
   head=head->add(3,head,4);head->print(head);cout<<"\n";
   
   if(head->ispalindrome(head,head)) cout<<"It is palindromic LL";
   else{ cout<<"Its not a palindromic LL";}
   cout<<"\n";
  
   


   // cout<<"Deleting the LINKED List\n";
   // head=head->deleteLinkedList(head);
   // if(head==NULL)cout<<"List is empty";
   // else cout<<"Function did not work";
   
   return 0;
  }