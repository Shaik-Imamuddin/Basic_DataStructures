#include<stdio.h>
#define MAX 100

int list[MAX];
int size = 0;


void insert(int pos,int val){
    if(size==MAX){
        printf("List is full");
        return;
    }

    if(pos<0 || pos>size){
        printf("Invalid Position");
        return;
    }

    for(int i=size;i>pos;i--){
        list[i]=list[i-1];
    }
    list[pos]=val;
    size++;
}

void delete(int pos){
    if(size==0){
        printf("List is Empty");
        return;
    }

    if(pos<0 || pos>=size){
        printf("Invalid Position");
        return;
    }

    for(int i=pos;i<size;i++){
        list[i]=list[i+1];
    }
    size--;
}

int get(int pos){
    if(pos<0 || pos>=size){
        printf("Invalid Position");
        return -1;
    }
    return list[pos];
}

void display(){
    if(size==0){
        printf("List is Empty");
        return;
    }

    for(int i=0;i<size;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

int main(){

    int pos,val;
    
    do{
        scanf("%d %d",&pos,&val);
        if(pos!=-1 && val!=-1)
            insert(pos,val);
    }while(pos!=-1 && val!=-1);

    display();

    int d_pos;
    scanf("%d",&d_pos);
    delete(d_pos);
    printf("%d\n",get(d_pos));
    display();
    return 0;
}