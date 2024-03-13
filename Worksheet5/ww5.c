int *createArray1(int *num){
    int n;
    int *dArr;
    scanf("%d", &n);
    dArr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dArr[i]);
    }
    *num = n;
    return dArr
}

int createArray2(int *dArr){
    int num
    scanf("%d", &num);

    * dArr = malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++){
        scanf("%d", &(*dArr)[i]);
    }

    return num;

}