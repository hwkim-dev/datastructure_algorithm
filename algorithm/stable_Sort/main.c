#include <stdio.h>

#define CARD_MAX 100

struct card
{
    char suit;
    int num;
};

void stableBubbleSort(struct card card[], int size) {
    int i, j, v, cnt;
    struct card tmp;
    for (cnt = 0; cnt < size - 1; ++cnt) {
        for (j = size - 1; j > cnt; --j) {
            i = j - 1;

            if (card[i].num > card[j].num) {
                tmp = card[i];
                card[i] = card[j];
                card[j] = tmp;
            }
            if(card[i].num == card[j].num && card[i].suit > card[j].suit)
            {
                tmp = card[i];
                card[i] = card[j];
                card[j] = tmp;
            }
        }
    }

}

void print(struct card card[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%c_%d ", card[i].suit, card[i].num);
    }
    putchar('\n');
}

int main()
{
    int card_Amount = 0;
    struct card card[CARD_MAX] = {};

    while(1)
    {
        printf(">>Input card amount(Max:100) : ");
        scanf("%d", &card_Amount);
        //scanf("%d", &card_Amount);

        if(card_Amount > CARD_MAX || card_Amount < 0)
        {
            continue;
        }else
        {
            break;
        }
    }


    for (int i = 0; i < card_Amount; ++i) {
        printf("Enter suit & num >> ");
        scanf(" %c%d", &card[i].suit, &card[i].num);
    }
    print(card, card_Amount);
    stableBubbleSort(card, card_Amount);
    print(card, card_Amount);
}