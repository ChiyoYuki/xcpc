#include <bits/stdc++.h>
using namespace std;
char code[256][256];

struct tree_and_list_node
{
    char data;
    unsigned long long num;
    struct tree_and_list_node *pre;
    struct tree_and_list_node *next;
    struct tree_and_list_node *left;
    struct tree_and_list_node *right;
};

typedef struct tree_and_list_node node;
typedef unsigned long long llu;

node *NewNode(char data, llu num, node *pre, node *next, node *left, node *right)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->num = num;
    newNode->pre = pre;
    newNode->next = next;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void SwapNode(node *x, node *y)
{
    node *a = x->pre;
    node *b = y->next;
    a->next = y;
    x->pre = y;
    x->next = b;
    y->pre = a;
    y->next = x;
    if (b != NULL)
        b->pre = x;
}

void SortNode(node *head)
{
    node *now = head;
    int i, j;
    int listSize = 0;
    while (now->next != NULL)
    {
        listSize++;
        now = now->next;
    }

    for (i = 0; i < listSize; i++)
    {
        now = head->next;
        while (now->next != NULL)
        {
            if (now->num > now->next->num)
                SwapNode(now, now->next);
            else
                now = now->next;
        }
    }
}

void InsertList(node *head, node *newNode)
{
    node *now = head;
    if (now->next == NULL)
    {
        now->next = newNode;
        newNode->pre = now;
        return;
    }
    else
    {
        do
        {
            now = now->next;
            if (newNode->num <= now->num)
            {
                newNode->pre = now->pre;
                newNode->next = now;
                newNode->pre->next = newNode;
                newNode->next->pre = newNode;
                return;
            }
        } while (now->next != NULL);
        now->next = newNode;
        newNode->pre = now;
        return;
    }
}

void BuildHuffman(node *head)
{
    while (head->next->next != NULL)
    {
        node *a = head->next;
        node *b = head->next->next;
        node *newNode = NewNode('\0', a->num + b->num, NULL, NULL, a, b);
        head->next = b->next;
        if (head->next != NULL)
            head->next->pre = head;
        a->pre = NULL;
        a->next = NULL;
        b->pre = NULL;
        b->next = NULL;
        InsertList(head, newNode);
    }
}

void EncodeText(node *nowNode, char *nowCode, char type, int place)
{
    int i = 0;
    if (type == 'l')
    {
        nowCode[place] = '0';
        place++;
        nowCode[place] = '\0';
    }
    else if (type == 'r')
    {
        nowCode[place] = '1';
        place++;
        nowCode[place] = '\0';
    }
    if (nowNode->data != '\0')
    {
        for (i = 0; nowCode[i] != '\0'; i++)
            code[nowNode->data][i] = nowCode[i];
        return;
    }
    else
    {
        EncodeText(nowNode->left, nowCode, 'l', place);
        EncodeText(nowNode->right, nowCode, 'r', place);
    }
}

void Encode(string s)
{
    int i;
    llu num[256] = {0};
    llu codeSize = 0, textSize = 0;
    double rate;
    char ch;
    char nowCode[256] = "";
    char inPath[256];

    node *head = NewNode('\0', 0, NULL, NULL, NULL, NULL);
    node *root = head;
    node *now = head;

    for (i = 0; i < s.size(); i++)
    {
        num[s[i]]++;
        textSize++;
    }

    for (i = 0; i < 256; i++)
    {
        if (num[i] != 0)
        {
            now->next = NewNode(i, num[i], now, NULL, NULL, NULL);
            now = now->next;
        }
    }

    SortNode(head);
    BuildHuffman(head);
    root = head->next;
    EncodeText(root, nowCode, 'm', 0);

    for (int j = 0; j < 256; j++)
    {
        for (i = 0; code[j][i] != '\0'; i++)
            ;
        codeSize += i*num[j];
    }

    rate = codeSize;
    rate = textSize * 8.0 / rate;
    printf("%d ", codeSize);
    printf("%.1lf\n", rate);
    return;
}

int main()
{
    int type;
    set<char> iii;
    string s = "";
    while (s != "END")
    {
        cin >> s;
        if (s == "END")
            break;
            iii.clear();
        for(int i=0;i<s.size();i++)
        {
            iii.insert(s[i]);
        }
        if(iii.size()==1)
        {
            cout<<s.size()*8<<' '<<s.size()<<" 8.0\n";
            continue;
        }
        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                code[i][j] = 0;
        cout << s.size() * 8 << ' ';
        Encode(s);
    }
    return 0;
}