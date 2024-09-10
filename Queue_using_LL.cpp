void MyQueue:: push(int x)
{
        QueueNode*nn=new QueueNode(x);
        //MISTAKE-front==rear will check for a single element as well 
        // Check condition for empty LL
        if(front==NULL){
            front=rear=nn;
        }
        else{
            rear->next=nn;
            rear=nn;
        }
}

int MyQueue :: pop()
{
        // Check condition for empty LL
        if(front==NULL){
            return -1;
        }
        int res=front->data;
        QueueNode*temp=front;
        front=front->next;
        delete temp;
        return res;
}