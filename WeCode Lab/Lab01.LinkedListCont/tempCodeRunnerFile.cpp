void addHead(node* p, List &l)
{
    if(l.head == NULL) 
    {
        l.head = p;
        l.tail = l.head;
    }
    else 
    {
        p->next = l.head;
        l.head = p;
    } 
}

void insertAfterQ(List &l, node* p, node* q)
{
    if(q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if(l.tail == q) l.tail = p;
    }
    else addHead(p, l);
}

void insertList(List &l, int x)
{
    if(l.head == NULL)
    {
        addTail(l, x);
        return; 
    }
    node* p;
    p = l.head;
    while(p->next != NULL)
    {
        if(x >= p->info && x <= p->next->info)
        {
            break;
        }
        p = p->next;
    }

    node* temp = getNode(x);

    if(p->next == NULL)
    {
        addHead(temp, l);
        return;
    }
    else insertAfterQ(l, temp, p);
}