#include <stdio.h>
#include <stdlib.h>

struct Card{
    char suit;
    int value;
};

int partition(struct Card card[], int p, int r)
{
    struct Card x = card[r];
    struct Card temp;
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if(card[j].value <= x.value)
        {
            ++i;
            temp = card[i];
            card[i] = card[j];
            card[j] = temp;
        }
    }
    ++i;
    temp = card[i];
    card[i] = card[r];
    card[r] = temp;

    return i;
}

void quick_Sort(struct Card card[], int p , int r)
{
    if(p < r)
    {
        int q = partition(card, p, r);
        quick_Sort(card, p, q - 1);
        quick_Sort(card, p + 1, r);
    }
}

int main() {
    int card_Len = 0;
    scanf("%d", &card_Len);
    struct Card *card = malloc(sizeof(struct Card) * card_Len);
    for (int i = 0; i < card_Len; ++i) {
        scanf("%s %d", &card[i].suit, &card[i].value);
    }

    quick_Sort(card, 0, card_Len - 1);

    for (int i = 0; i < card_Len; ++i) {
        printf("%c %d\n", card[i].suit, card[i].value);
    }
    return 0;
}
