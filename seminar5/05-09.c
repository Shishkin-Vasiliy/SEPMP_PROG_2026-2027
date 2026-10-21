int adder(int num)
{
    static int total = 0;

    total += num;

    return total;
}