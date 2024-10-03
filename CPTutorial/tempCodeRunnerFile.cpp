ial(BigInt n){
    BigInt product = BigInt(1, 0);
    int i = 1;
    while(1){
        // printf("i = %d\n", i);
        if(n < BigInt(2, 0)){
            break;
        }
        // cout << " Product: ";
        // if(i == 100){
        //     break;
        // }
        // printf("%d\n", i);
        product = product * n;
        // product.printNum();
        n = n - BigInt(1, 0);
        i++;
    }
    return product;
}