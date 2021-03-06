#include <stdio.h>
#include "PeriodicFn.h"

void fn1(char *str){

    printf("THIS IS FN 1&&str1fn1:%s&&\n",str);
}

void fn2(char *str1,char *str2){

    printf("THIS IS FN 2**str1:%s\nstr2:%s**\n",str1,str2);
}

void fn3(char *str1,char *str2){

    printf("//THIS IS FN 3str1:%s\nstr2:%s//\n`",str1,str2);
}

void * fn1gen(void * argadd){

    void ** args = argadd;
    
    fn1(args[0]);
    return NULL;
}
void * fn2gen(void * argadd){

    void ** args = argadd;
    
    fn2(args[0],args[1]);
    return NULL;
}
void * fn3gen(void * argadd){

    void ** args = argadd;

    fn3(args[0],args[1]);
    return NULL;
}

int main(void){

    const char *str1 = "str1",*str2 = "str2",*str3 = "str3";
    void * agrs1[1] = {(void*)str1};
    void * agrs2[2] = {(void*)str1,(void*)str2};
    void * agrs3[2] = {(void*)str1,(void*)str3};
    linked_fn lkfn = make_linked_fn();
    periodic_node * prn_aux;

    
    add_fn( &lkfn, *fn2gen, agrs2 , 90,1);
    add_fn( &lkfn, *fn1gen, agrs1 , 35,2);
    add_fn( &lkfn, *fn3gen, agrs3 , 35,3);
    add_fn( &lkfn, *fn2gen, agrs2 , 35,4);
    prn_aux = lkfn.head;

    for(int i = 0;i < 3;++i){

        printf("ADDR: %p\n",prn_aux);
        printf("NODE%d TIME:%d\n",i,prn_aux->time);
        exec_node(prn_aux);
        prn_aux = prn_aux->next;
    }

    printf("3/--------------------------\\\n");

    rm_fn( &lkfn,1);
    prn_aux = lkfn.head;
    for(int i = 0;i < 3;++i){

        printf("ADDR: %p\n",prn_aux);
        printf("NODE%d TIME:%d\n",i,prn_aux->time);
        exec_node(prn_aux);
        prn_aux = prn_aux->next;
    }
    printf("2/--------------------------\\\n");
    rm_fn(&lkfn, 2);
    prn_aux = lkfn.head;
    for(int i = 0;i < 3;++i){

        printf("ADDR: %p\n",prn_aux);
        printf("NODE%d TIME:%d\n",i,prn_aux->time);
        exec_node(prn_aux);
        prn_aux = prn_aux->next;
    }
    printf("1/--------------------------\\\n");
    
    rm_fn(&lkfn, 3);
    rm_fn(&lkfn, 4);
    prn_aux = lkfn.head;
    for(int i = 0;i < 3;++i){

        printf("ADDR: %p\n",prn_aux);
        printf("NODE%d TIME:%d\n",i,prn_aux->time);
        exec_node(prn_aux);
        prn_aux = prn_aux->next;
    }
    del_linked_fn(lkfn);
    return 0;
}
