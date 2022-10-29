#include "queueArray.h"
void tests(int* erreur){
    bool valid = true;
    int n;
    printf("-------createEmptyQueue-------\n");
    struct Queue* queue1 = createEmptyQueue();
    if(queue1->size == 0 && queue1->front == 0 && queue1->rear == 0){
        printf("test createEmptyQueue OK\n");
    }else{
        printf("test createEmptyStack //\n");
        *erreur+=1;
    }
    printf("-------enqueue-------\n");
    valid = false;
    enqueue(queue1, 20, &valid);
    if(valid == true){
        printf("test enqueue un element OK\n");
    }else{
        printf("test enqueue un element //\n");
        *erreur+=1;
    }
    if(queue1->elems[0] == 20){
        printf("test enqueue un element valeur OK\n");
    }else{
        printf("test enqueue un element valeur //\n");
        *erreur+=1;
    }
    if(queue1->size == 1){
        printf("test enqueue un element size OK\n");
    }else{
        printf("test enqueue un element size //\n");
        *erreur+=1;
    }
    if(queue1->front == 0){
        printf("test enqueue un element front OK\n");
    }else{
        printf("test enqueue un element front //\n");
        *erreur+=1;
    }
    enqueue(queue1, 30, &valid);
    valid = false;
    enqueue(queue1, 40, &valid);
    if(valid == true){
        printf("test enqueue plusieurs elements OK\n");
    }else{
        printf("test enqueue plusieurs elements //\n");
        *erreur+=1;
    }
    if(queue1->elems[0] == 20 && queue1->elems[1] == 30 && queue1->elems[2] == 40){
        printf("test enqueue plusieurs elements valeurs OK\n");
    }else{
        printf("test enqueue plusieurs elements valeurs //\n");
        *erreur+=1;
    }
    if(queue1->size == 3){
        printf("test enqueue plusieurs elements size OK\n");
    }else{
        printf("test enqueue plusieurs elements size //\n");
        *erreur+=1;
    }
    if(queue1->front == 0){
        printf("test enqueue plusieurs elements front OK\n");
    }else{
        printf("test enqueue plusieurs elements front //\n");
        *erreur+=1;
    }
    valid = true;
    for (int i = 0; i < 30 ; ++i) {
        enqueue(queue1, 40, &valid);
    }
    if(valid == false){
        printf("test enqueue plein OK\n");
    }else{
        printf("test enqueue plein //\n");
        *erreur+=1;
    }
    if(queue1->elems[0] == 20 && queue1->elems[1] == 30 && queue1->elems[2] == 40 && queue1->elems[29] == 40){
        printf("test enqueue plein valeurs OK\n");
    }else{
        printf("test enqueue plein valeurs //\n");
        *erreur+=1;
    }
    if(queue1->size == 30){
        printf("test enqueue plein size OK\n");
    }else{
        printf("test enqueue plein size //\n");
        *erreur+=1;
    }
    if(queue1->front == 0){
        printf("test enqueue plein front OK\n");
    }else{
        printf("test enqueue plein front //\n");
        *erreur+=1;
    }
    deleteQueue(queue1);
    printf("-------head-------\n");
    struct Queue* queue2 = createEmptyQueue();
    valid = true;
    n = head(queue2, &valid);
    if(valid == false){
        printf("test head vide OK\n");
    }else{
        printf("test head vide //\n");
        *erreur+=1;
    }
    enqueue(queue2, 20, &valid);
    enqueue(queue2, 30, &valid);
    enqueue(queue2, 40, &valid);
    valid = false;
    n = head(queue2, &valid);
    if(valid == true){
        printf("test head non vide OK\n");
    }else{
        printf("test head non vide //\n");
        *erreur+=1;
    }
    if(queue2->elems[0] == n && n == 20){
        printf("test head non vide value OK\n");
    }else{
        printf("test head non vide value //\n");
        *erreur+=1;
    }
    deleteQueue(queue2);
    printf("-------dequeue-------\n");
    struct Queue* queue3 = createEmptyQueue();
    valid = true;
    n = dequeue(queue3, &valid);
    if(valid == false){
        printf("test dequeue vide OK\n");
    }else{
        printf("test dequeue vide //\n");
        *erreur+=1;
    }
    if(queue3->size == 0){
        printf("test dequeue vide size OK\n");
    }else{
        printf("test dequeue vide size //\n");
        *erreur+=1;
    }
    if(queue3->front == 0){
        printf("test dequeue vide front OK\n");
    }else{
        printf("test dequeue vide front //\n");
        *erreur+=1;
    }
    deleteQueue(queue3);
    struct Queue* queue4 = createEmptyQueue();
    enqueue(queue4, 20, &valid);
    valid = false;
    n = dequeue(queue4, &valid);
    if(valid == true){
        printf("test dequeue un element OK\n");
    }else{
        printf("test dequeue un element //\n");
        *erreur+=1;
    }
    if(n == 20 && n == queue4->elems[0]){
        printf("test dequeue un element value OK\n");
    }else{
        printf("test dequeue un element value //\n");
        *erreur+=1;
    }
    if(queue4->size == 0){
        printf("test dequeue un element size OK\n");
    }else{
        printf("test dequeue un element size //\n");
        *erreur+=1;
    }
    if(queue4->front == 0 || queue4->front == 1){
        printf("test dequeue un element front OK\n");
    }else{
        printf("test dequeue un element front //\n");
        *erreur+=1;
    }
    deleteQueue(queue4);
    struct Queue* queue5 = createEmptyQueue();
    enqueue(queue5, 20, &valid);
    enqueue(queue5, 30, &valid);
    enqueue(queue5, 40, &valid);
    enqueue(queue5, 50, &valid);

    valid = false;
    n = dequeue(queue5, &valid);
    if(valid == true){
        printf("test dequeue plusieurs elements OK\n");
    }else{
        printf("test dequeue plusieurs elements //\n");
        *erreur+=1;
    }
    if(n == 20 && n == queue5->elems[0]){
        n = dequeue(queue5, &valid);
        if(n == 30){
            printf("test dequeue plusieurs elements value OK\n");
        }else{
            printf("test dequeue plusieurs elements value //\n");
            *erreur+=1;
        }
    }else{
        printf("test dequeue plusieurs elements value //\n");
        *erreur+=1;
    }
    if(queue5->size == 2){
        printf("test dequeue plusieurs elements size OK\n");
    }else{
        printf("test dequeue plusieurs elements size //\n");
        *erreur+=1;
    }
    if(queue5->front == 1 || queue5->front == 2){
        printf("test dequeue plusieurs elements front OK\n");
    }else{
        printf("test dequeue plusieurs elements front //\n");
        *erreur+=1;
    }
    deleteQueue(queue5);
    printf("-------isQueueEmpty-------\n");
    struct Queue* queue6 = createEmptyQueue();
    valid = isQueueEmpty(queue6);
    if(valid == true){
        printf("test isQueueEmpty true OK\n");
    }else{
        printf("test isQueueEmpty true //\n");
        *erreur+=1;
    }
    enqueue(queue6, 20, &valid);
    valid = isQueueEmpty(queue6);
    if(valid == false){
        printf("test isQueueEmpty false OK\n");
    }else{
        printf("test isQueueEmpty false //\n");
        *erreur+=1;
    }
    dequeue(queue6, &valid);
    valid = isQueueEmpty(queue6);
    if(valid == true){
        printf("test isQueueEmpty true dequeue OK\n");
    }else{
        printf("test isQueueEmpty true dequeue //\n");
        *erreur+=1;
    }
    deleteQueue(queue6);
    printf("-------PrintQueue-------\n");
    struct Queue* queue7 = createEmptyQueue();
    printf("printQueue vide : \n");
    printf("model : rear->NULL<-front\n");
    printf("test : ");
    printQueue(queue7);
    printf("printQueue non vide : \n");
    for (int i = 20 ; i < 100 ; i+=10) {
        enqueue(queue7, i, &valid);
    }
    printf("model : rear->90-80-70-60-50-40-30-20<-front\n");
    printf("test : ");
    printQueue(queue7);
    deleteQueue(queue7);
}
void testUlt(int* erreur){
    bool valid = false;
    int n;
    struct Queue* queueUlt = createEmptyQueue();
    if(isQueueEmpty(queueUlt)){
        printf("OK\n");
    }else{
        printf("// 11\n");
        *erreur+=1;
    }
    enqueue(queueUlt, 15, &valid);
    if(valid == true){
        printf("OK\n");
    }else{
        printf("// 21\n");
        *erreur+=1;
    }
    if(queueUlt->size == 1){
        printf("OK\n");
    }else{
        printf("// 31\n");
        *erreur+=1;
    }
    if(queueUlt->elems[0] == 15){
        printf("OK\n");
    }else{
        printf("// 41\n");
        *erreur+=1;
    }
    if(queueUlt->front == 0){
        printf("OK\n");
    }else{
        printf("// 32\n");
        *erreur+=1;
    }
    for (int i = 0 ; i < 29 ; ++i) {
        enqueue(queueUlt, i, &valid);
        if(valid == true){
            printf("OK\n");
        }else{
            printf("// 21\n");
            *erreur+=1;
        }
    }
    if(queueUlt->size == 30){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueUlt->elems[0] == 15){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueUlt->elems[1] == 0){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueUlt->elems[29] == 28){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueUlt->front == 0){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    n = dequeue(queueUlt, &valid);
    if(queueUlt->size == 29 && queueSize(queueUlt) == 29){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(n == 15){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    enqueue(queueUlt, 29, &valid);
    if(valid == true){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueSize(queueUlt) == 30){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    enqueue(queueUlt, 52, &valid);
    if(valid == false){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueSize(queueUlt) == 30){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(head(queueUlt, &valid) == 0){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    for (int i = 0 ; i < 30 ; ++i) {
        n = dequeue(queueUlt, &valid);
        if(n == i && valid == true){
            printf("OK\n");
        }else{
            printf("//\n");
            *erreur+=1;
        }
    }
    n = dequeue(queueUlt, &valid);
    if(valid == false){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(isQueueEmpty(queueUlt)){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    for (int i = 0 ; i < 5 ; ++i) {
        enqueue(queueUlt, i, &valid);
    }
    for (int i = 0 ; i < 2 ; ++i) {
        n = dequeue(queueUlt, &valid);
    }
    if(head(queueUlt, &valid) == 2){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    for (int i = 0; i < 26; ++i) {
        enqueue(queueUlt, i+10, &valid);
    }
    if(valid == true){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(isQueueEmpty(queueUlt) == false){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(isQueueEmpty(queueUlt) == false){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(queueSize(queueUlt) == 29){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    dequeue(queueUlt, &valid);
    dequeue(queueUlt, &valid);
    dequeue(queueUlt, &valid);
    dequeue(queueUlt, &valid);
    if(head(queueUlt, &valid) == 11){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(valid == true){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    if(isQueueEmpty(queueUlt) == false){
        printf("OK\n");
    }else{
        printf("//\n");
        *erreur+=1;
    }
    deleteQueue(queueUlt);
}
int main(){
    int erreur = 0;
    tests(&erreur);
    printf("-------erreurs-------\n");
    printf("%d erreur.s\n",erreur);
    if(erreur == 0){
        printf("0 erreurs, lancement test ultime.\n");
        printf("------- TEST ULTIME -------\n");
        testUlt(&erreur);
        printf("------- erreurs ULTIMES -------\n");
        printf("%d erreur.s\n",erreur);
    }else{
        printf("Vous avez des erreurs basiques, vous ne pouvez pas accéder au test ultime.\n");
    }
    printf("-------debugger-------\n");
    printf("queueArray V0.1\n");
    printf("--------------\n");
    return 0;
}