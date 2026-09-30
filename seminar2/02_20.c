#include <stdio.h>

enum shape {
    ROCK,
    PAPER,
    SCISSORS
};

enum result {
    LOSS,
    DRAW,
    WIN
};

void print_shape(enum shape Shape);
void print_result(enum result Result);
enum shape get_result(enum shape a, enum shape b);
enum shape get_strength(enum shape s);

int main(void)
{
    enum shape a = ROCK;
    enum shape b = ROCK;
    enum result Result = get_result(a, b);

    print_shape(a);
    print_shape(b);
    print_result(Result);

    return 0;
}

void print_shape(enum shape Shape)
{
    switch(Shape)
    {
        case ROCK:
            printf("Rock\n");
            break;
        
        case PAPER:
            printf("Paper\n");
            break;

        case SCISSORS:
            printf("Scissors\n");
            break;
        
        default:
            ;
    }
}

void print_result(enum result Result)
{
    switch(Result)
    {
        case LOSS:
            printf("Loss\n");
            break;
        
        case DRAW:
            printf("Draw\n");
            break;

        case WIN:
            printf("Win\n");
            break;
        
        default:
            ;
    }
}

enum shape get_strength(enum shape s)
{
    switch(s)
    {
        case ROCK:
            return PAPER;
            break;

        case PAPER:
            return SCISSORS;
            break;

        case SCISSORS:
            return ROCK;
            break;

        default:
            ;
    }
}

enum shape get_result(enum shape a, enum shape b)
{
    enum shape s = get_strength(a);
    
    if (a == b)
        return DRAW;

    if (s == b)
        return LOSS;

    else 
        return WIN;
}