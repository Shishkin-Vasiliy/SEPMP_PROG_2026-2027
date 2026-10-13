int *max(int *pa, int *pb)
{
    if (*pa > *pb)
        return pa;
    else if (*pa < *pb)
        return pb;
    else 
        return pa;
}
