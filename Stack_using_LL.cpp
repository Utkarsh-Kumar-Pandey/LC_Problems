class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode *nn=new StackNode(x);
        nn->next=top;
        top=nn;
        
    }

    int pop() {
        if(top==NULL){
            return -1;
        }
        StackNode*delete_node=top;
        top=top->next;
        int popped_item=delete_node->data;
        delete delete_node;
        
        return popped_item;
    }

    MyStack() { top = NULL; }
};