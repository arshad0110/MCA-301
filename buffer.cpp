#include<iostream>
#include<string.h>

enum status_code { locked =1, unlocked, valid, invalid, delay_write};

class Buff_node{

public:
        int blk_no;
        int device_no;
        int data;
        status_code status;
        Buff_node *fowd_free_list;
        Buff_node *prev_free_list;
        Buff_node *fowd_hash_list;
        Buff_node *prev_hash_list;
        int buff_no;  

        Buff_node(int i){
                blk_no = 0;
                device_no = 1;
                fowd_free_list = nullptr;
                prev_free_list = nullptr;
                fowd_hash_list = nullptr;
                prev_hash_list = nullptr;
                buff_no = i;
                data = 0;
                
        }
        

};

class List{
private:
        Buff_node *hashques[4];

        Buff_node *fhead;
        // Buff_node *hash1head,*hash1tail;
        // Buff_node *hash2head,*hash2tail;
        // Buff_node *hash3head,*hash3tail;
        // Buff_node *hash4head,*hash4tail;
public:
        List(){
                fhead   = nullptr;
                for (int i = 0; i<4;++i){
                        hashques[i] = nullptr;
                }
                // hash1head = hash1tail = nullptr;
                // hash2head = hash2tail = nullptr;
                // hash3head = hash3tail = nullptr;
                // hash4head = hash4tail = nullptr;

        }

        void CreatePool(int n);

        void hashDisplay(const Buff_node *head) const;
        void freeDisplay();
};

void List::CreatePool(int n){
        Buff_node *temp = nullptr;
        for(int i =0;i<n;++i){
                Buff_node *newBuff = new Buff_node(i);
                
                if (fhead == nullptr){
                        fhead =  newBuff;
                        newBuff->fowd_free_list = fhead;
                        newBuff->prev_free_list = newBuff;
                        
                        temp = newBuff;
                }else{
                        temp->fowd_free_list = newBuff;
                        newBuff->prev_free_list = temp;
                        newBuff->fowd_free_list = fhead;
                        fhead->prev_free_list = newBuff;
                        temp = temp->fowd_free_list;
                }
        }

}

void List::freeDisplay(){
        Buff_node *head = fhead;
        if (head == nullptr){
                std::cout<<"free list is empty"<<std::endl;
                return;
        }else{
                Buff_node *temp = head;
               
                do
                
                {
                        std::cout<<"["<<temp->data<<":"<<temp->buff_no<<"], ";
                        temp = temp->fowd_free_list;
                }while(temp  != head );


        }
}






int main(){

        List l1;
        l1.CreatePool(10);
        l1.freeDisplay();

}
