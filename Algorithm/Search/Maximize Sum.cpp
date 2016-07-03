#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;

struct node {
    ll val ;
    struct node *left , *right ;
    int height = 0 ;
};


int getHeight(node *node1){
    if(node1 == NULL)   return 0 ;
    return node1->height ;
}

struct node *newNode(ll v){
    struct node *temp = (struct node *)malloc(sizeof(struct node)) ;
    temp->val = v ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp->height = 1 ;
    return temp ;
}

struct node *rightRotate(struct node * y){
    struct node *x = y->left ;
    struct node *tmp = x->right ;
    x->right = y ;
    y->left = tmp ;
    y->height = max(getHeight(y->left) , getHeight(y->right) ) + 1 ;
    x->height = max(getHeight(x->left) , getHeight(x->right) ) + 1 ;
    return x ;
}

struct node *leftRotate(struct node * x){
    struct node *y = x->right ;
    struct node *tmp = y->left ;
    y->left = x ;
    x->right = tmp ;
    x->height = max(getHeight(x->left) , getHeight(x->right) ) + 1 ;
    y->height = max(getHeight(y->left) , getHeight(y->right) ) + 1 ;
    return y ;
}

node* insert1(node* node1, ll v){
    if (node1 == NULL)   return(newNode(v));
    if (v < node1->val)    node1->left  = insert1(node1->left, v);
    else    node1->right = insert1(node1->right, v);
    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;

    int balance = 0 ;
    if(node1 != NULL)   balance = getHeight(node1->left) - getHeight(node1->right) ;

    if (balance > 1 && v < node1->left->val)
        return rightRotate(node1);
    if (balance < -1 && v > node1->right->val)
        return leftRotate(node1);
    if (balance > 1 && v > node1->left->val){
        node1->left =  leftRotate(node1->left);
        return rightRotate(node1);
    }
    if (balance < -1 && v < node1->right->val){
        node1->right = rightRotate(node1->right);
        return leftRotate(node1);
    }
    return node1;
}

ll flag ;
struct node *search1(struct node *node1 , ll v){
    if(node1 == NULL)    return NULL ;
    if(node1->val >= v){
        flag = min(flag , node1->val) ;
    }
    if( v < node1->val) node1->left = search1(node1->left , v) ;
    else    node1->right = search1(node1->right , v) ;
    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;

    int balance = 0 ;
    if(node1 != NULL)   balance = getHeight(node1->left) - getHeight(node1->right) ;

    if (balance > 1 && v < node1->left->val)
        return rightRotate(node1);
    if (balance < -1 && v > node1->right->val)
        return leftRotate(node1);
    if (balance > 1 && v > node1->left->val){
        node1->left =  leftRotate(node1->left);
        return rightRotate(node1);
    }
    if (balance < -1 && v < node1->right->val){
        node1->right = rightRotate(node1->right);
        return leftRotate(node1);
    }
    return node1;
}


int main(){
//    freopen("input.txt" , "r" , stdin);
    int T ;
    scanf("%d" , &T) ;
    while(T--){
        int n ;
        scanf("%d" , &n) ;
        ll m , a , ret = 0 ;
        scanf("%lld" , &m) ;
        scanf("%lld" , &ret) ; ret %= m ;
        ll sum = ret ;

        struct node *tree ;
        tree = NULL ;
        tree = insert1(tree , ret) ;

        for(int i = 1 ; i < n ; i++){
            scanf("%lld" , &a) ;
            sum = (sum + a)%m ;
            flag = m ;
            search1(tree , sum) ;
            ret = max(ret , (sum - flag + m)%m ) ;
            if(flag != sum) tree = insert1(tree , sum) ;
        }
        printf("%lld\n" , ret) ;
    }
}
