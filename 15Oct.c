#include <stdio.h>
#include <stdlib.h>
typedef struct huffman
{
    int left;
    int right;
    int freq;
    char ch;
} huffman;
struct huffman tree[100];
int n, total = 0;
void print(int root, char code[], int pos)
{
    if (tree[root].left == -1 &&
        tree[root].right == -1)
    {
        if (pos == 0)
            code[pos++] = '0';
        code[pos] = '\0';
        printf("%c = %s\n", tree[root].ch, code);
        return;
    }
    code[pos] = '0';
    print(tree[root].left, code, pos + 1);
    code[pos] = '1';
    print(tree[root].right, code, pos + 1);
}
int main()
{
    int i, a, b;
    char code[100];
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &tree[i].ch, &tree[i].freq);
        tree[i].left = -1;
        tree[i].right = -1;
    }
    total = n;
    while (total < 2 * n - 1)
    {
        a = b = -1;
        for (i = 0; i < total; i++)
        {
            if (tree[i].freq == -1)
                continue;

            if (a == -1 ||
                tree[i].freq < tree[a].freq)
            {
                b = a;
                a = i;
            }
            else if (b == -1 ||
                     tree[i].freq < tree[b].freq)
            {
                b = i;
            }
        }
        tree[total].ch = '#';
        tree[total].freq = tree[a].freq + tree[b].freq;
        tree[total].left = a;
        tree[total].right = b;
        tree[a].freq = -1;
        tree[b].freq = -1;
        total++;
    }
    printf("\nHuffman Codes:\n");
    print(total - 1, code, 0);
    return 0;
}
